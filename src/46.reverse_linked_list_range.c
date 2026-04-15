/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 46.reverse_linked_list_range.c
 * 作    者: 三道渊
 * 创建日期: 2026-03-29
 * 最后修改: 2026-03-29
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 链表区间反转
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
 * @brief 反转链表的指定区间
 * @param head 链表头节点
 * @param left 起始位置
 * @param right 结束位置
 * @return ListNode* 反转后的链表头节点
 */
ListNode* reverse_between(ListNode* head, int left, int right)
{
    if (head == NULL || left == right)
    {
        return head;
    }
    
    // 创建哑节点
    ListNode* dummy = create_node(0);
    dummy->next = head;
    ListNode* pre = dummy;
    
    // 移动到反转开始的前一个节点
    for (int i = 1; i < left; i++)
    {
        pre = pre->next;
    }
    
    // 开始反转
    ListNode* curr = pre->next;
    ListNode* next;
    
    for (int i = 0; i < right - left; i++)
    {
        next = curr->next;
        curr->next = next->next;
        next->next = pre->next;
        pre->next = next;
    }
    
    ListNode* result = dummy->next;
    free(dummy);
    return result;
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
    
    printf("=== 链表区间反转 ===\n");
    printf("题目：反转链表的指定区间\n\n");
    
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
    ListNode *result1 = reverse_between(head1, 2, 4);
    printf("反转2-4区间: ");
    print_list(result1);
    
    // 测试用例2
    printf("\n测试用例2：\n");
    ListNode *head2 = create_node(5);
    printf("原链表: ");
    print_list(head2);
    ListNode *result2 = reverse_between(head2, 1, 1);
    printf("反转1-1区间: ");
    print_list(result2);
    
    // 测试用例3
    printf("\n测试用例3：\n");
    ListNode *head3 = create_node(1);
    ListNode *node3_2 = create_node(2);
    head3->next = node3_2;
    printf("原链表: ");
    print_list(head3);
    ListNode *result3 = reverse_between(head3, 1, 2);
    printf("反转1-2区间: ");
    print_list(result3);
    
    return 0;
}
