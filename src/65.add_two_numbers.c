/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 65.add_two_numbers.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 两数相加
 * 算法描述:
 *   - 两数相加：使用链表，模拟加法过程
 * 适用场景:
 *   - 链表操作
 *   - 大数计算
 *   - 模拟运算
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
 * @brief 链表节点结构
 */
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

/**
 * @brief 创建链表节点
 * @param val 节点值
 * @return ListNode* 新节点
 */
ListNode* createNode(int val)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

/**
 * @brief 两数相加（链表）
 * @param l1 第一个链表
 * @param l2 第二个链表
 * @return ListNode* 结果链表
 */
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* dummy = createNode(0);
    ListNode* current = dummy;
    int carry = 0;
    
    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        int sum = carry;
        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        
        carry = sum / 10;
        current->next = createNode(sum % 10);
        current = current->next;
    }
    
    ListNode* result = dummy->next;
    free(dummy);
    return result;
}

/**
 * @brief 打印链表
 * @param head 链表头
 */
void printList(ListNode* head)
{
    while (head != NULL)
    {
        printf("%d", head->val);
        if (head->next != NULL)
        {
            printf(" -> ");
        }
        head = head->next;
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

    printf("=== 两数相加（链表） ===\n");
    printf("题目：给定两个非空链表，表示两个非负整数，将它们相加并返回新的链表\n\n");
    
    // 测试用例1: 2->4->3 + 5->6->4 = 7->0->8
    ListNode* l1 = createNode(2);
    l1->next = createNode(4);
    l1->next->next = createNode(3);
    
    ListNode* l2 = createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4);
    
    printf("测试用例1:\n");
    printf("l1: ");
    printList(l1);
    printf("l2: ");
    printList(l2);
    
    ListNode* result1 = addTwoNumbers(l1, l2);
    printf("结果: ");
    printList(result1);
    printf("预期: 7 -> 0 -> 8\n\n");
    
    // 测试用例2: 0 + 0 = 0
    ListNode* l3 = createNode(0);
    ListNode* l4 = createNode(0);
    
    printf("测试用例2:\n");
    printf("l1: ");
    printList(l3);
    printf("l2: ");
    printList(l4);
    
    ListNode* result2 = addTwoNumbers(l3, l4);
    printf("结果: ");
    printList(result2);
    printf("预期: 0\n\n");
    
    // 释放内存
    while (l1 != NULL)
    {
        ListNode* temp = l1;
        l1 = l1->next;
        free(temp);
    }
    while (l2 != NULL)
    {
        ListNode* temp = l2;
        l2 = l2->next;
        free(temp);
    }
    while (l3 != NULL)
    {
        ListNode* temp = l3;
        l3 = l3->next;
        free(temp);
    }
    while (l4 != NULL)
    {
        ListNode* temp = l4;
        l4 = l4->next;
        free(temp);
    }
    while (result1 != NULL)
    {
        ListNode* temp = result1;
        result1 = result1->next;
        free(temp);
    }
    while (result2 != NULL)
    {
        ListNode* temp = result2;
        result2 = result2->next;
        free(temp);
    }

    return 0;
}
