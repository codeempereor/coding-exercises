/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 70.integer_partition.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 整数划分
 * 算法描述:
 *   - 整数划分：使用动态规划，计算整数的划分数
 * 适用场景:
 *   - 数学问题
 *   - 动态规划
 *   - 组合问题
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
 * @brief 整数划分
 * @param n 整数
 * @return int 划分数
 */
int integerPartition(int n)
{
    int dp[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = 0;
    }
    dp[0] = 1;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            dp[j] += dp[j - i];
        }
    }
    
    return dp[n];
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

    printf("=== 整数划分 ===\n");
    printf("题目：计算将整数n划分为若干正整数之和的不同方式的数目\n\n");
    
    // 测试用例
    int test_cases[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int test_count = 10;
    
    for (int i = 0; i < test_count; i++)
    {
        int n = test_cases[i];
        int result = integerPartition(n);
        printf("测试用例%d: n=%d → %d\n", i + 1, n, result);
    }

    return 0;
}
