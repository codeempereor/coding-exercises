/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 51.find_kth_largest.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h, stdlib.h
 * 功能描述:
 *   1. 第 k 大的数
 * 算法描述:
 *   - 第 k 大的数：使用快速选择算法，高效找到第 k 大元素
 * 适用场景:
 *   - 排序算法
 *   - 选择问题
 *   - 快速选择
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
 * @brief 交换两个整数
 * @param a 第一个整数
 * @param b 第二个整数
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief 分区函数
 * @param nums 数组
 * @param left 左边界
 * @param right 右边界
 * @return int 基准元素的位置
 */
int partition(int *nums, int left, int right)
{
    int pivot = nums[right];
    int i = left - 1;
    
    for (int j = left; j < right; j++)
    {
        if (nums[j] >= pivot)
        {
            i++;
            swap(&nums[i], &nums[j]);
        }
    }
    
    swap(&nums[i + 1], &nums[right]);
    return i + 1;
}

/**
 * @brief 快速选择算法
 * @param nums 数组
 * @param left 左边界
 * @param right 右边界
 * @param k 第k大元素的位置
 * @return int 第k大元素
 */
int quick_select(int *nums, int left, int right, int k)
{
    if (left == right)
    {
        return nums[left];
    }
    
    int pivot_idx = partition(nums, left, right);
    int rank = pivot_idx - left + 1;
    
    if (rank == k)
    {
        return nums[pivot_idx];
    }
    else if (rank > k)
    {
        return quick_select(nums, left, pivot_idx - 1, k);
    }
    else
    {
        return quick_select(nums, pivot_idx + 1, right, k - rank);
    }
}

/**
 * @brief 找到数组中第k大的元素
 * @param nums 数组
 * @param n 数组大小
 * @param k 第k大
 * @return int 第k大元素
 */
int find_kth_largest(int *nums, int n, int k)
{
    return quick_select(nums, 0, n - 1, k);
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
    
    printf("=== 第k大元素 ===\n");
    printf("题目：找出数组中第k大的数\n\n");
    
    // 测试用例
    int test_cases[][10] = {
        {1, 3, 5, 2, 2},
        {10, 10, 9, 9, 8, 7, 5, 6, 4, 3},
        {5, 4, 3, 2, 1},
        {1, 1, 1, 1, 1},
        {7, 10, 4, 3, 20, 15}
    };
    int test_sizes[] = {5, 10, 5, 5, 6};
    int test_ks[] = {3, 3, 2, 1, 3};
    int test_count = sizeof(test_cases) / sizeof(test_cases[0]);
    
    for (int i = 0; i < test_count; i++)
    {
        int nums[10];
        // 复制测试用例到新数组
        for (int j = 0; j < test_sizes[i]; j++)
        {
            nums[j] = test_cases[i][j];
        }
        
        printf("测试用例%d: ", i + 1);
        print_array(nums, test_sizes[i]);
        printf(", k=%d → ", test_ks[i]);
        
        int result = find_kth_largest(nums, test_sizes[i], test_ks[i]);
        printf("%d\n", result);
    }
    
    return 0;
}
