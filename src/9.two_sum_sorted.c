/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 9.two_sum_sorted.c
 * 作    者: 三道渊
 * 创建日期: 2026-03-29
 * 最后修改: 2026-03-29
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 有序数组两数之和
 * 算法描述:
 *   - 双指针法：利用有序数组的特性，使用两个指针从两端向中间移动
 *   - 初始化左指针指向数组开始，右指针指向数组末尾
 *   - 计算两指针指向元素的和：
 *     - 如果和等于目标值，返回这两个元素
 *     - 如果和小于目标值，左指针右移
 *     - 如果和大于目标值，右指针左移
 *   - 时间复杂度O(n)，空间复杂度O(1)
 * 适用场景:
 *   - 有序数组中的两数之和问题
 *   - 查找满足条件的两个元素
 *   - 范围搜索
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-03-29 三道渊: 添加了Windows API调用，设置控制台编码为UTF-8
 *   - 2026-03-29 三道渊: 初始化文件
 * ============================================================================ */

#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif

#define MAX_N 100

/**
 * @brief 寻找有序数组中两数之和等于目标值的所有元素对
 * @param nums 有序数组
 * @param n 数组长度
 * @param target 目标值
 * @return void
 */
void two_sum_sorted(int nums[], int n, int target)
{
    int left = 0;
    int right = n - 1;
    int found = 0;
    
    while (left < right)
    {
        int sum = nums[left] + nums[right];
        
        if (sum == target)
        {
            printf("%d + %d = %d\n", nums[left], nums[right], target);
            found = 1;
            
            // 继续寻找其他可能的数对
            left++;
            right--;
            
            // 跳过重复元素
            while (left < right && nums[left] == nums[left - 1])
            {
                left++;
            }
            while (left < right && nums[right] == nums[right + 1])
            {
                right--;
            }
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    
    if (!found)
    {
        printf("未找到\n");
    }
}

/**
 * @brief 打印数组
 * @param arr 数组
 * @param n 数组长度
 */
void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * @brief 有序数组两数之和
 * @return void
 */
void solve()
{
    printf("=== 有序数组两数之和 ===\n");
    printf("题目：在有序数组中查找两个数，使得它们的和正好是输入的目标值\n\n");
    
    // 测试用例1：基本情况
    int nums1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    int target1 = 10;

    
    printf("测试用例1:");
    print_array(nums1, n1);
    printf("目标值：%d\n", target1);
    
    printf("找到：\n");
    two_sum_sorted(nums1, n1, target1);
    printf("预期:1 + 9 = 10 或 2 + 8 = 10 等\n\n");
    
    // 测试用例2：负数情况
    int nums2[] = {-5, -3, -2, 0, 1, 4, 6, 8};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    int target2 = 2;

    
    printf("测试用例2:");
    print_array(nums2, n2);
    printf("目标值：%d\n", target2);
    
    printf("找到：\n");
    two_sum_sorted(nums2, n2, target2);
    printf("预期：-2 + 4 = 2\n\n");
    
    // 测试用例3：无结果情况
    int nums3[] = {1, 2, 3, 4, 5};
    int n3 = sizeof(nums3) / sizeof(nums3[0]);
    int target3 = 100;

    
    printf("测试用例3:");
    print_array(nums3, n3);
    printf("目标值：%d\n", target3);
    
    printf("找到：\n");
    two_sum_sorted(nums3, n3, target3);
    printf("预期：未找到\n\n");
    
    // 测试用例4：只有两个元素
    int nums4[] = {2, 7};
    int n4 = sizeof(nums4) / sizeof(nums4[0]);
    int target4 = 9;

    
    printf("测试用例4:");
    print_array(nums4, n4);
    printf("目标值：%d\n", target4);
    
    printf("找到：\n");
    two_sum_sorted(nums4, n4, target4);
    printf("预期:2 + 7 = 9\n");
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
