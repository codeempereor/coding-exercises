/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 32.sum_of_aaa.c
 * 作    者: 三道渊
 * 创建日期: 2026-03-29
 * 最后修改: 2026-04-08
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 连数求和
 * 算法描述:
 *   - 逐次构建连数并累加
 *   - 从a开始，每次乘以10再加上a得到下一个连数
 *   - 累加所有连数得到总和
 *   - 时间复杂度：O(n)
 * 适用场景:
 *   - 数学问题：连数求和
 *   - 数字序列计算
 *   - 基础算法练习
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-04-08 三道渊: 实现连数求和功能，添加测试用例
 *   - 2026-03-29 三道渊: 初始化文件
 * ============================================================================ */

#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

#define MAX_N 100

/**
 * @brief 计算连数之和
 * @param a 基础数字（1-9）
 * @param n 项数
 * @return long long 连数之和
 */
long long sum_of_aaa(int a, int n)
{
    long long sum = 0;
    long long current = 0;
    
    for (int i = 0; i < n; i++)
    {
        current = current * 10 + a;
        sum += current;
    }
    
    return sum;
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
    
    printf("=== 连数求和 ===\n");
    printf("题目：计算 a + aa + aaa + ... + a...a(n个a)的和\n\n");
    
    // 测试用例
    int test_cases[][2] = {{1, 3}, {2, 4}, {5, 2}, {9, 5}};
    int test_count = sizeof(test_cases) / sizeof(test_cases[0]);
    
    for (int i = 0; i < test_count; i++)
    {
        int a = test_cases[i][0];
        int n = test_cases[i][1];
        long long result = sum_of_aaa(a, n);
        
        printf("测试用例%d: %d + %d%d + ", i + 1, a, a, a);
        for (int j = 3; j < n; j++)
        {
            printf("%d", a);
        }
        if (n > 3)
        {
            printf(" + ");
        }
        for (int j = 0; j < n; j++)
        {
            printf("%d", a);
        }
        printf(" = %lld\n", result);
    }
    
    // 用户输入
    int a, n;
    printf("\n请输入基础数字a (1-9): ");
    scanf("%d", &a);
    printf("请输入项数n: ");
    scanf("%d", &n);
    
    if (a >= 1 && a <= 9 && n > 0)
    {
        long long result = sum_of_aaa(a, n);
        printf("\n计算结果: %d + %d%d", a, a, a);
        for (int j = 3; j < n; j++)
        {
            printf(" + ");
            for (int k = 0; k <= j; k++)
            {
                printf("%d", a);
            }
        }
        printf(" = %lld\n", result);
    }
    else
    {
        printf("输入错误:a必须在1-9之间,n必须大于0\n");
    }
    
    return 0;
}
