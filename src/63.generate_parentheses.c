/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 63.generate_parentheses.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h, string.h
 * 功能描述:
 *   1. 生成括号
 * 算法描述:
 *   - 生成括号：使用回溯法，生成有效的括号组合
 * 适用场景:
 *   - 组合问题
 *   - 回溯算法
 *   - 字符串处理
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
 * @brief 生成括号
 * @param n 括号对数
 * @return void
 */
void generateParenthesisHelper(int n, int open, int close, char* current, int index, char** result, int* returnSize)
{
    if (index == 2 * n)
    {
        current[index] = '\0';
        result[*returnSize] = (char*)malloc((2 * n + 1) * sizeof(char));
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }
    
    if (open < n)
    {
        current[index] = '(';
        generateParenthesisHelper(n, open + 1, close, current, index + 1, result, returnSize);
    }
    
    if (close < open)
    {
        current[index] = ')';
        generateParenthesisHelper(n, open, close + 1, current, index + 1, result, returnSize);
    }
}

/**
 * @brief 生成括号
 * @param n 括号对数
 * @param returnSize 返回大小
 * @return char** 结果数组
 */
char** generateParenthesis(int n, int* returnSize)
{
    *returnSize = 0;
    char** result = (char**)malloc(1000 * sizeof(char*));
    char current[1000];
    generateParenthesisHelper(n, 0, 0, current, 0, result, returnSize);
    return result;
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

    printf("=== 生成括号 ===\n");
    printf("题目：生成所有由n对括号组成的有效括号组合\n\n");
    
    // 测试用例
    int test_cases[] = {3, 1, 2, 4};
    int test_count = 4;
    
    for (int i = 0; i < test_count; i++)
    {
        int n = test_cases[i];
        int returnSize;
        char** result = generateParenthesis(n, &returnSize);
        printf("测试用例%d (n=%d):\n", i + 1, n);
        for (int j = 0; j < returnSize; j++)
        {
            printf("  %s\n", result[j]);
            free(result[j]);
        }
        free(result);
    }

    return 0;
}
