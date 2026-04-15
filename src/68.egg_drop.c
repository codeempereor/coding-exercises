/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 68.egg_drop.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 鸡蛋掉落
 * 算法描述:
 *   - 鸡蛋掉落：使用动态规划，计算最少尝试次数
 * 适用场景:
 *   - 动态规划
 *   - 优化问题
 *   - 风险评估
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
 * @brief 鸡蛋掉落
 * @param k 鸡蛋数
 * @param n 楼层数
 * @return int 最小操作次数
 */
int superEggDrop(int k, int n)
{
    int dp[k + 1][n + 1];
    
    // 初始化
    for (int i = 1; i <= k; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    for (int j = 1; j <= n; j++)
    {
        dp[1][j] = j;
    }
    
    // 填充dp表
    for (int i = 2; i <= k; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            dp[i][j] = n;
            int left = 1, right = j;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                int broken = dp[i - 1][mid - 1];
                int not_broken = dp[i][j - mid];
                int res = 1 + (broken > not_broken ? broken : not_broken);
                if (broken < not_broken)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
                if (res < dp[i][j])
                {
                    dp[i][j] = res;
                }
            }
        }
    }
    
    return dp[k][n];
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

    printf("=== 鸡蛋掉落 ===\n");
    printf("题目：给定k个鸡蛋和n层楼，找到最低的楼层使得鸡蛋会碎\n\n");
    
    // 测试用例
    int test_cases[][2] = {
        {1, 2},
        {2, 6},
        {3, 14},
        {2, 100}
    };
    int test_count = 4;
    
    for (int i = 0; i < test_count; i++)
    {
        int k = test_cases[i][0];
        int n = test_cases[i][1];
        int result = superEggDrop(k, n);
        printf("测试用例%d: k=%d, n=%d → %d\n", i + 1, k, n, result);
    }

    return 0;
}
