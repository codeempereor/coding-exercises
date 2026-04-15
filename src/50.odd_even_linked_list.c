/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 50.odd_even_linked_list.c
 * 作    者: 三道渊
 * 创建日期: 2026-03-29
 * 最后修改: 2026-03-29
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 奇偶链表
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-03-29 三道渊: 初始化文件
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
 * @brief 奇偶链表
 * @param head 链表头节点
 * @return ListNode* 重新排列后的链表头节点
 */
ListNode* odd_even_list(ListNode* head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    
    ListNode* odd = head;  // 奇数位置指针
    ListNode* even = head->next;  // 偶数位置指针
    ListNode* even_head = even;  // 偶数链表的头节点
    
    while (even != NULL && even->next != NULL)
    {
        odd->next = even->next;  // 奇数节点指向下一个奇数节点
        odd = odd->next;  // 移动奇数指针
        
        even->next = odd->next;  // 偶数节点指向下一个偶数节点
        even = even->next;  // 移动偶数指针
    }
    
    odd->next = even_head;  // 将奇数链表的末尾连接到偶数链表的开头
    
    return head;
}

/**
 * @brief 打印链表
 * @param head 链表头节点
 */
void print_list(ListNode* head)
{
    ListNode* curr = head;
    while (curr)
    {
        printf("%d", curr->val);
        if (curr->next)
        {
            printf(" -> ");
        }
        curr = curr->next;
    }
    printf("\n");
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
    
    printf("=== 奇偶链表 ===\n");
    printf("题目：将链表中的奇数位置节点和偶数位置节点分开\n\n");
    
    // 测试用例1
    printf("测试用例1：\n");
    ListNode *head1 = create_node(1);
    ListNode *node2 = create_node(2);
    ListNode *node3 = create_node(3);
    ListNode *node4 = create_node(4);
    ListNode *node5 = create_node(5);
    
    head1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    
    printf("原链表: ");
    print_list(head1);
    ListNode *result1 = odd_even_list(head1);
    printf("奇偶链表: ");
    print_list(result1);
    
    // 测试用例2
    printf("\n测试用例2：\n");
    ListNode *head2 = create_node(2);
    ListNode *node2_2 = create_node(1);
    ListNode *node3_2 = create_node(3);
    ListNode *node4_2 = create_node(5);
    ListNode *node5_2 = create_node(6);
    ListNode *node6_2 = create_node(4);
    ListNode *node7_2 = create_node(7);
    
    head2->next = node2_2;
    node2_2->next = node3_2;
    node3_2->next = node4_2;
    node4_2->next = node5_2;
    node5_2->next = node6_2;
    node6_2->next = node7_2;
    
    printf("原链表: ");
    print_list(head2);
    ListNode *result2 = odd_even_list(head2);
    printf("奇偶链表: ");
    print_list(result2);
    
    // 测试用例3
    printf("\n测试用例3：\n");
    ListNode *head3 = create_node(1);
    printf("原链表: ");
    print_list(head3);
    ListNode *result3 = odd_even_list(head3);
    printf("奇偶链表: ");
    print_list(result3);
    
    return 0;
}
