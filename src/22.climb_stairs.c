/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 22.climb_stairs.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 爬楼梯
 * 算法描述:
 *   - 爬楼梯：使用动态规划，计算到达每阶楼梯的方法数
 * 适用场景:
 *   - 动态规划练习
 *   - 路径计数
 *   - 组合问题
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-04-15 三道渊: 初始化文件
 * ============================================================================ */
#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif

#define MAX_N 50

/**
 * @brief 爬楼梯问题（递归+记忆化）
 * @param n 楼梯级数
 * @return 爬楼梯的方法数
 */
int climb_stairs_recursive(int n, int memo[])
{
    if (n <= 1)
    {
        return 1;
    }
    if (memo[n] != -1)
    {
        return memo[n];
    }
    memo[n] = climb_stairs_recursive(n - 1, memo) + climb_stairs_recursive(n - 2, memo);
    return memo[n];
}

/**
 * @brief 爬楼梯问题（动态规划）
 * @param n 楼梯级数
 * @return 爬楼梯的方法数
 */
int climb_stairs_dp(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    
    int dp[MAX_N];
    dp[0] = 1;
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    return dp[n];
}

/**
 * @brief 爬楼梯问题（空间优化）
 * @param n 楼梯级数
 * @return 爬楼梯的方法数
 */
int climb_stairs_optimized(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    
    int prev2 = 1; // f(n-2)
    int prev1 = 1; // f(n-1)
    int current;
    
    for (int i = 2; i <= n; i++)
    {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    
    return prev1;
}

/**
 * @brief 爬楼梯
 * @return void
 */


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

printf("=== 爬楼梯 ===\n");
    printf("题目：假设你正在爬楼梯。需要 n 阶你才能到达楼顶。每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？\n\n");
    
    // 测试用例1：基本情况
    int n1 = 3;
    int memo1[MAX_N];
    for (int i = 0; i <= n1; i++) memo1[i] = -1;
    
    printf("测试用例1：\n");
    printf("楼梯级数：%d\n", n1);
    printf("递归+记忆化：%d\n", climb_stairs_recursive(n1, memo1));
    printf("动态规划：%d\n", climb_stairs_dp(n1));
    printf("空间优化：%d\n", climb_stairs_optimized(n1));
    printf("预期结果：3\n\n");
    
    // 测试用例2：较大值
    int n2 = 10;
    int memo2[MAX_N];
    for (int i = 0; i <= n2; i++) memo2[i] = -1;
    
    printf("测试用例2：\n");
    printf("楼梯级数：%d\n", n2);
    printf("递归+记忆化：%d\n", climb_stairs_recursive(n2, memo2));
    printf("动态规划：%d\n", climb_stairs_dp(n2));
    printf("空间优化：%d\n", climb_stairs_optimized(n2));
    printf("预期结果：89\n");

return 0;
}
