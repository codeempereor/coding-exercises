/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 27.min_subarray_sum.c
 * 作    者: 三道渊
 * 创建日期: 2026-03-29
 * 最后修改: 2026-04-04
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 最小子数组和：查找数组中和最小的连续子数组
 * 算法描述:
 *   - 动态规划法：类似于最大子数组和问题
 *   - 步骤1：初始化最小和为第一个元素
 *   - 步骤2：遍历数组，对于每个元素，选择当前元素或当前元素加上前一个子数组和
 *   - 步骤3：更新全局最小和
 *   - 时间复杂度O(n)，空间复杂度O(1)
 * 适用场景:
 *   - 数组处理问题
 *   - 动态规划应用
 *   - 最优化问题
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-04-04 三道渊: 补充算法描述和适用场景，实现完整功能
 *   - 2026-03-29 三道渊: 初始化文件
 * ============================================================================ */

#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif

#define MAX_N 100

/**
 * @brief 查找最小子数组和
 * @param arr 输入数组
 * @param n 数组长度
 * @return 最小子数组和
 */
int min_subarray_sum(int arr[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    
    int min_sum = arr[0];
    int current_sum = arr[0];
    
    for (int i = 1; i < n; i++)
    {
        current_sum = (arr[i] < current_sum + arr[i]) ? arr[i] : current_sum + arr[i];
        min_sum = (current_sum < min_sum) ? current_sum : min_sum;
    }
    
    return min_sum;
}

/**
 * @brief 最小子数组和
 * @return void
 */
void solve()
{
    printf("=== 最小子数组和 ===\n");
    printf("题目：查找数组中和最小的连续子数组\n\n");
    
    int test_cases[][10] = {
        {1, -2, 3, -1, 2, -4, 5},
        {-2, -3, -1, -4},
        {1, 2, 3, 4, 5},
        {5, -1, 2, -3, 1},
        {-1, 2, 3, -5, 4, 6}
    };
    
    int test_sizes[] = {7, 4, 5, 5, 6};
    int n = sizeof(test_sizes) / sizeof(test_sizes[0]);
    
    for (int i = 0; i < n; i++)
    {
        int min_sum = min_subarray_sum(test_cases[i], test_sizes[i]);
        printf("测试用例%d: [", i + 1);
        for (int j = 0; j < test_sizes[i]; j++)
        {
            printf("%d", test_cases[i][j]);
            if (j < test_sizes[i] - 1)
            {
                printf(", ");
            }
        }
        printf("]\n");
        printf("  最小子数组和: %d\n\n", min_sum);
    }
}

/**
 * @brief 主函数
 * @return int 程序退出状态码
 */
int main() {
    #ifdef _WIN32
    // 设置控制台输出为UTF-8
    SetConsoleOutputCP(CP_UTF8);
    #endif
    solve();
    return 0;
}
