/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 48.find_median_sorted_arrays.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 寻找两个有序数组的中位数
 * 算法描述:
 *   - 寻找两个有序数组的中位数：使用二分查找，确保时间复杂度 O(log(min(m,n)))
 * 适用场景:
 *   - 排序算法
 *   - 二分查找
 *   - 中位数计算
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
 * @brief 找到两个有序数组的第k小元素
 * @param nums1 第一个有序数组
 * @param nums1Size 第一个数组大小
 * @param nums2 第二个有序数组
 * @param nums2Size 第二个数组大小
 * @param k 第k小元素
 * @return double 第k小元素的值
 */
double find_kth(int* nums1, int nums1Size, int* nums2, int nums2Size, int k)
{
    // 确保nums1是较短的数组
    if (nums1Size > nums2Size)
    {
        return find_kth(nums2, nums2Size, nums1, nums1Size, k);
    }
    
    // 边界情况
    if (nums1Size == 0)
    {
        return nums2[k - 1];
    }
    if (k == 1)
    {
        return nums1[0] < nums2[0] ? nums1[0] : nums2[0];
    }
    
    // 计算两个数组中要比较的位置
    int i = nums1Size < k/2 ? nums1Size : k/2;
    int j = k - i;
    
    if (nums1[i - 1] < nums2[j - 1])
    {
        // 排除nums1的前i个元素
        return find_kth(nums1 + i, nums1Size - i, nums2, nums2Size, k - i);
    }
    else
    {
        // 排除nums2的前j个元素
        return find_kth(nums1, nums1Size, nums2 + j, nums2Size - j, k - j);
    }
}

/**
 * @brief 找到两个有序数组的中位数
 * @param nums1 第一个有序数组
 * @param nums1Size 第一个数组大小
 * @param nums2 第二个有序数组
 * @param nums2Size 第二个数组大小
 * @return double 中位数
 */
double find_median_sorted_arrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int total = nums1Size + nums2Size;
    
    if (total % 2 == 1)
    {
        // 奇数长度，返回中间元素
        return find_kth(nums1, nums1Size, nums2, nums2Size, total / 2 + 1);
    }
    else
    {
        // 偶数长度，返回中间两个元素的平均值
        double left = find_kth(nums1, nums1Size, nums2, nums2Size, total / 2);
        double right = find_kth(nums1, nums1Size, nums2, nums2Size, total / 2 + 1);
        return (left + right) / 2;
    }
}

/**
 * @brief 打印数组
 * @param nums 数组
 * @param size 数组大小
 */
void print_array(int* nums, int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("%d", nums[i]);
        if (i < size - 1)
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
    
    printf("=== 两个有序数组的中位数 ===\n");
    printf("题目：找到两个有序数组的中位数\n\n");
    
    // 测试用例
    int test_cases1[][5] = {
        {1, 3},
        {1, 2},
        {},
        {0, 0},
        {2}
    };
    int test_cases2[][5] = {
        {2},
        {3, 4},
        {1},
        {0, 0},
        {}
    };
    int test_sizes1[] = {2, 2, 0, 2, 1};
    int test_sizes2[] = {1, 2, 1, 2, 0};
    int test_count = sizeof(test_cases1) / sizeof(test_cases1[0]);
    
    for (int i = 0; i < test_count; i++)
    {
        printf("测试用例%d: ", i + 1);
        print_array(test_cases1[i], test_sizes1[i]);
        printf(", ");
        print_array(test_cases2[i], test_sizes2[i]);
        
        double result = find_median_sorted_arrays(
            test_cases1[i], test_sizes1[i],
            test_cases2[i], test_sizes2[i]
        );
        
        printf(" → %.1f\n", result);
    }
    
    return 0;
}
