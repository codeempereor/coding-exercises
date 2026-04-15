/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 61.partition_k_subsets.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 划分为 k 个相等的子集
 * 算法描述:
 *   - 划分为 k 个相等的子集：使用回溯法，尝试将元素分配到不同子集
 * 适用场景:
 *   - 组合问题
 *   - 回溯算法
 *   - 优化问题
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
 * @brief 回溯函数
 * @param nums 数组
 * @param numsSize 数组大小
 * @param k 子集数量
 * @param start 起始位置
 * @param currentSum 当前和
 * @param target 目标和
 * @param visited 访问标记
 * @return int 是否可以划分
 */
int backtrack(int* nums, int numsSize, int k, int start, int currentSum, int target, int* visited);

/**
 * @brief 划分为k个等和子集
 * @param nums 数组
 * @param numsSize 数组大小
 * @param k 子集数量
 * @return int 是否可以划分
 */
int canPartitionKSubsets(int* nums, int numsSize, int k)
{
    int sum = 0;
    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i];
    }
    
    if (sum % k != 0)
    {
        return 0;
    }
    
    int target = sum / k;
    int visited[numsSize];
    for (int i = 0; i < numsSize; i++)
    {
        visited[i] = 0;
    }
    
    return backtrack(nums, numsSize, k, 0, 0, target, visited);
}

/**
 * @brief 回溯函数
 * @param nums 数组
 * @param numsSize 数组大小
 * @param k 子集数量
 * @param start 起始位置
 * @param currentSum 当前和
 * @param target 目标和
 * @param visited 访问标记
 * @return int 是否可以划分
 */
int backtrack(int* nums, int numsSize, int k, int start, int currentSum, int target, int* visited)
{
    if (k == 1)
    {
        return 1;
    }
    
    if (currentSum == target)
    {
        return backtrack(nums, numsSize, k - 1, 0, 0, target, visited);
    }
    
    for (int i = start; i < numsSize; i++)
    {
        if (!visited[i] && currentSum + nums[i] <= target)
        {
            visited[i] = 1;
            if (backtrack(nums, numsSize, k, i + 1, currentSum + nums[i], target, visited))
            {
                return 1;
            }
            visited[i] = 0;
        }
    }
    
    return 0;
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

    printf("=== 划分为k个等和子集 ===\n");
    printf("题目：给定一个整数数组和一个整数k，判断是否可以将数组分成k个和相等的子集\n\n");
    
    // 测试用例
    int test_cases[][10] = {
        {4, 3, 2, 3, 5, 2, 1, 0, 0, 0},  // nums = [4, 3, 2, 3, 5, 2, 1], k = 4
        {1, 2, 3, 4, 0, 0, 0, 0, 0, 0},  // nums = [1, 2, 3, 4], k = 3
        {2, 2, 2, 2, 2, 2, 0, 0, 0, 0},  // nums = [2, 2, 2, 2, 2, 2], k = 3
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 0},  // nums = [1, 1, 1, 1, 1, 1, 1, 1], k = 4
        {3, 1, 3, 2, 2, 1, 3, 0, 0, 0}   // nums = [3, 1, 3, 2, 2, 1, 3], k = 3
    };
    int k_values[] = {4, 3, 3, 4, 3};
    int test_count = 5;
    
    for (int i = 0; i < test_count; i++)
    {
        int nums[10];
        int numsSize = 0;
        for (int j = 0; j < 10; j++)
        {
            if (test_cases[i][j] != 0)
            {
                nums[numsSize++] = test_cases[i][j];
            }
        }
        
        int result = canPartitionKSubsets(nums, numsSize, k_values[i]);
        printf("测试用例%d: ", i + 1);
        for (int j = 0; j < numsSize; j++)
        {
            printf("%d ", nums[j]);
        }
        printf("k=%d → %s\n", k_values[i], result ? "可以划分" : "无法划分");
    }

    return 0;
}
