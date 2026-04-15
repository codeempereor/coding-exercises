/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 60.max_xor.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h, stdlib.h
 * 功能描述:
 *   1. 最大异或值
 * 算法描述:
 *   - 最大异或值：使用字典树，优化异或值的查找
 * 适用场景:
 *   - 位运算
 *   - 字典树
 *   - 优化问题
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-04-15 三道渊: 初始化文件
 * ============================================================================ */
#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

/**
 * @brief 字典树节点
 */
typedef struct TrieNode {
    struct TrieNode *children[2];
} TrieNode;

/**
 * @brief 创建新的字典树节点
 * @return TrieNode* 新节点
 */
TrieNode* create_node()
{
    TrieNode *node = (TrieNode*)malloc(sizeof(TrieNode));
    if (node)
    {
        node->children[0] = NULL;
        node->children[1] = NULL;
    }
    return node;
}

/**
 * @brief 插入数字到字典树
 * @param root 字典树根节点
 * @param num 数字
 */
void insert(TrieNode *root, int num)
{
    TrieNode *current = root;
    for (int i = 31; i >= 0; i--)
    {
        int bit = (num >> i) & 1;
        if (!current->children[bit])
        {
            current->children[bit] = create_node();
        }
        current = current->children[bit];
    }
}

/**
 * @brief 在字典树中查找最大异或值
 * @param root 字典树根节点
 * @param num 数字
 * @return int 最大异或值
 */
int find_max_xor(TrieNode *root, int num)
{
    TrieNode *current = root;
    int max_xor = 0;
    for (int i = 31; i >= 0; i--)
    {
        int bit = (num >> i) & 1;
        int opposite_bit = 1 - bit;
        
        if (current->children[opposite_bit])
        {
            max_xor |= (1 << i);
            current = current->children[opposite_bit];
        }
        else
        {
            current = current->children[bit];
        }
    }
    return max_xor;
}

/**
 * @brief 释放字典树
 * @param root 字典树根节点
 */
void free_trie(TrieNode *root)
{
    if (!root)
    {
        return;
    }
    free_trie(root->children[0]);
    free_trie(root->children[1]);
    free(root);
}

/**
 * @brief 找到数组中任意两个数的最大异或值
 * @param nums 数组
 * @param n 数组大小
 * @return int 最大异或值
 */
int find_maximum_xor(int *nums, int n)
{
    if (n < 2)
    {
        return 0;
    }
    
    // 构建字典树
    TrieNode *root = create_node();
    insert(root, nums[0]);
    
    int max_result = 0;
    for (int i = 1; i < n; i++)
    {
        int current_max = find_max_xor(root, nums[i]);
        if (current_max > max_result)
        {
            max_result = current_max;
        }
        insert(root, nums[i]);
    }
    
    free_trie(root);
    return max_result;
}

/**
 * @brief 打印数组
 * @param nums 数组
 * @param n 数组大小
 */
void print_array(int *nums, int n)
{
    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf("%d", nums[i]);
        if (i < n - 1)
        {
            printf(", ");
        }
    }
    printf("]");
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
    
    printf("=== 最大异或值 ===\n");
    printf("题目：给定一个数组，返回任选两个数的最大异或值\n\n");
    
    // 测试用例
    int test_cases[][5] = {
        {1, 2, 3, 4, 5},
        {5, 5, 5, 5, 1},
        {3, 10, 5, 25, 2, 8},
        {0},
        {1, 2}
    };
    int test_sizes[] = {5, 5, 6, 1, 2};
    int test_count = sizeof(test_cases) / sizeof(test_cases[0]);
    
    for (int i = 0; i < test_count; i++)
    {
        printf("测试用例%d: ", i + 1);
        print_array(test_cases[i], test_sizes[i]);
        printf(" → ");
        
        int result = find_maximum_xor(test_cases[i], test_sizes[i]);
        printf("%d\n", result);
    }
    
    return 0;
}