/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 43.linked_list_cycle.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 链表环检测
 * 算法描述:
 *   - 链表环检测：使用快慢指针，判断是否存在环
 * 适用场景:
 *   - 链表操作
 *   - 环检测
 *   - 算法设计
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-04-15 三道渊: 初始化文件
 * ============================================================================ */
#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif

#define MAX_N 100

/**
 * @brief 链表节点结构体
 */
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

/**
 * @brief 创建新的链表节点
 * @param val 节点值
 * @return ListNode* 新节点指针
 */
ListNode* create_node(int val)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    if (node)
    {
        node->val = val;
        node->next = NULL;
    }
    return node;
}

/**
 * @brief 检测链表是否有环
 * @param head 链表头节点
 * @return int 1表示有环，0表示无环
 */
int has_cycle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return 0;
    }
    
    ListNode *slow = head;
    ListNode *fast = head;
    
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast)
        {
            return 1;
        }
    }
    
    return 0;
}

/**
 * @brief 找到链表环的入口
 * @param head 链表头节点
 * @return ListNode* 环入口节点
 */
ListNode *detect_cycle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    
    ListNode *slow = head;
    ListNode *fast = head;
    int hasCycle = 0;
    
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast)
        {
            hasCycle = 1;
            break;
        }
    }
    
    if (!hasCycle)
    {
        return NULL;
    }
    
    // 快指针回到头节点，快慢指针每次走一步，相遇点即为环入口
    fast = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow;
}

/**
 * @brief 主函数
 * @return int 程序退出状态码
 */
int main()
{
    #ifdef _WIN32
    // 设置控制台输出为UTF-8
    SetConsoleOutputCP(CP_UTF8);
    #endif
    
    printf("=== 链表环入口 ===\n");
    printf("题目：检测链表是否有环，并找到环的入口\n\n");
    
    // 测试用例1：有环的链表
    printf("测试用例1：有环的链表\n");
    ListNode *head1 = create_node(3);
    ListNode *node2 = create_node(2);
    ListNode *node0 = create_node(0);
    ListNode *node4 = create_node(4);
    
    head1->next = node2;
    node2->next = node0;
    node0->next = node4;
    node4->next = node2;  // 创建环
    
    if (has_cycle(head1))
    {
        ListNode *cycle_start = detect_cycle(head1);
        printf("链表有环，环入口值为: %d\n", cycle_start->val);
    }
    else
    {
        printf("链表无环\n");
    }
    
    // 测试用例2：无环的链表
    printf("\n测试用例2：无环的链表\n");
    ListNode *head2 = create_node(1);
    ListNode *node2_2 = create_node(2);
    ListNode *node3_2 = create_node(3);
    
    head2->next = node2_2;
    node2_2->next = node3_2;
    
    if (has_cycle(head2))
    {
        ListNode *cycle_start = detect_cycle(head2);
        printf("链表有环，环入口值为: %d\n", cycle_start->val);
    }
    else
    {
        printf("链表无环\n");
    }
    
    // 测试用例3：空链表
    printf("\n测试用例3：空链表\n");
    ListNode *head3 = NULL;
    if (has_cycle(head3))
    {
        ListNode *cycle_start = detect_cycle(head3);
        printf("链表有环，环入口值为: %d\n", cycle_start->val);
    }
    else
    {
        printf("链表无环\n");
    }
    
    return 0;
}
