/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 67.max_product_subarray.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 最大乘积子数组
 * 算法描述:
 *   - 最大乘积子数组：使用动态规划，记录最大和最小乘积
 * 适用场景:
 *   - 数组分析
 *   - 动态规划
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
 * @brief 最大乘积子数组
 * @param nums 数组
 * @param numsSize 数组大小
 * @return int 最大乘积
 */
int maxProduct(int* nums, int numsSize)
{
    if (numsSize == 0)
    {
        return 0;
    }
    
    int max_so_far = nums[0];
    int min_so_far = nums[0];
    int result = nums[0];
    
    for (int i = 1; i < numsSize; i++)
    {
        int temp = max_so_far;
        max_so_far = nums[i] > max_so_far * nums[i] ? (nums[i] > min_so_far * nums[i] ? nums[i] : min_so_far * nums[i]) : (max_so_far * nums[i] > min_so_far * nums[i] ? max_so_far * nums[i] : min_so_far * nums[i]);
        min_so_far = nums[i] < temp * nums[i] ? (nums[i] < min_so_far * nums[i] ? nums[i] : min_so_far * nums[i]) : (temp * nums[i] < min_so_far * nums[i] ? temp * nums[i] : min_so_far * nums[i]);
        result = result > max_so_far ? result : max_so_far;
    }
    
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

    printf("=== 最大乘积子数组 ===\n");
    printf("题目：找到一个数组中乘积最大的连续子数组\n\n");
    
    // 测试用例
    int test_cases[][5] = {
        {2, 3, -2, 4, 0},  // nums = [2, 3, -2, 4]
        {-2, 0, -1, 0, 0},  // nums = [-2, 0, -1]
        {-2, 3, -4, 0, 0},  // nums = [-2, 3, -4]
        {0, 2, 0, 0, 0},     // nums = [0, 2]
        {-1, -2, -9, -6, 0}  // nums = [-1, -2, -9, -6]
    };
    int test_sizes[] = {4, 3, 3, 2, 4};
    int test_count = 5;
    
    for (int i = 0; i < test_count; i++)
    {
        int nums[5];
        for (int j = 0; j < test_sizes[i]; j++)
        {
            nums[j] = test_cases[i][j];
        }
        int result = maxProduct(nums, test_sizes[i]);
        printf("测试用例%d: ", i + 1);
        for (int j = 0; j < test_sizes[i]; j++)
        {
            printf("%d ", nums[j]);
        }
        printf("→ %d\n", result);
    }

    return 0;
}
