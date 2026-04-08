/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 35.subset_sum_count.c
 * 作    者: 三道渊
 * 创建日期: 2026-03-29
 * 最后修改: 2026-04-08
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 子集和计数
 * 算法描述:
 *   - 动态规划：使用一维数组dp[i]表示和为i的子集个数
 *   - 初始化dp[0] = 1（空集）
 *   - 遍历数组，从大到小更新dp数组
 *   - 时间复杂度：O(n*target)
 *   - 空间复杂度：O(target)
 * 适用场景:
 *   - 动态规划：子集和问题
 *   - 组合计数：统计满足条件的子集个数
 *   - 背包问题：0-1背包的变种
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-04-08 三道渊: 实现子集和计数功能，添加测试用例
 *   - 2026-03-29 三道渊: 初始化文件
 * ============================================================================ */

#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif

#define MAX_N 100

/**
 * @brief 计算子集和等于目标值的个数
 * @param nums 数组
 * @param n 数组长度
 * @param target 目标值
 * @return int 子集个数
 */
int subset_sum_count(int nums[], int n, int target)
{
    // 动态规划数组，dp[i]表示和为i的子集个数
    int dp[1001] = {0};
    dp[0] = 1;  // 和为0的子集只有空集
    
    for (int i = 0; i < n; i++)
    {
        // 从大到小遍历，避免重复使用同一个元素
        for (int j = target; j >= nums[i]; j--)
        {
            dp[j] += dp[j - nums[i]];
        }
    }
    
    return dp[target];
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
    
    printf("=== 子集和计数 ===\n");
    printf("题目：计算数组中和为目标值的子集个数\n\n");
    
    // 测试用例
    int test_cases[][5] = {
        {1, 2, 3, 4, 5},  // 数组
        {2, 4, 6, 8, 10},  // 数组
        {1, 1, 1, 1, 1},  // 数组
        {3, 5, 7, 9, 11},  // 数组
        {1, 3, 5, 7, 9}   // 数组
    };
    int targets[] = {5, 10, 3, 12, 15};
    int test_count = sizeof(test_cases) / sizeof(test_cases[0]);
    
    for (int i = 0; i < test_count; i++)
    {
        int n = 5;  // 每个测试用例数组长度为5
        int result = subset_sum_count(test_cases[i], n, targets[i]);
        
        printf("测试用例%d: 数组=", i + 1);
        for (int j = 0; j < n; j++)
        {
            printf("%d ", test_cases[i][j]);
        }
        printf("目标值=%d → %d\n", targets[i], result);
    }
    
    return 0;
}
