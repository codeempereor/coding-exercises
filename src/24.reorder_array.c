/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 24.reorder_array.c
 * 作    者: 三道渊
 * 创建日期: 2026-03-30
 * 最后修改: 2026-03-30
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 奇偶重排
 * 算法描述:
 *   - 双指针法：将数组中的奇数放在前面，偶数放在后面
 *   - 步骤1：初始化两个指针，left指向数组开始，right指向数组末尾
 *   - 步骤2：left向右移动，直到找到偶数
 *   - 步骤3：right向左移动，直到找到奇数
 *   - 步骤4：交换left和right指向的元素
 *   - 步骤5：重复步骤2-4，直到left >= right
 *   - 时间复杂度O(n)，空间复杂度O(1)
 * 适用场景:
 *   - 数组重排
 *   - 双指针技巧
 *   - 数据分类
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-03-30 三道渊: 初始化文件
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
 * @brief 奇偶重排
 * @param nums 输入数组
 * @param n 数组长度
 */
void reorder_array(int nums[], int n)
{
    int left = 0;
    int right = n - 1;
    
    while (left < right)
    {
        // left向右移动，直到找到偶数
        while (left < right && nums[left] % 2 == 1)
        {
            left++;
        }
        // right向左移动，直到找到奇数
        while (left < right && nums[right] % 2 == 0)
        {
            right--;
        }
        // 交换
        if (left < right)
        {
            swap(&nums[left], &nums[right]);
            left++;
            right--;
        }
    }
}

/**
 * @brief 打印数组
 * @param arr 输入数组
 * @param len 数组长度
 */
void print_array(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * @brief 奇偶重排
 * @return void
 */
void solve()
{
    printf("=== 奇偶重排 ===\n");
    printf("题目：将数组中的奇数放在前面，偶数放在后面\n\n");
    
    // 测试用例1：基本情况
    int nums1[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    
    printf("测试用例1：\n");
    printf("原数组：");
    print_array(nums1, n1);
    reorder_array(nums1, n1);
    printf("重排后：");
    print_array(nums1, n1);
    printf("预期结果：奇数在前，偶数在后\n\n");
    
    // 测试用例2：全是奇数
    int nums2[] = {1, 3, 5, 7, 9};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    
    printf("测试用例2：\n");
    printf("原数组：");
    print_array(nums2, n2);
    reorder_array(nums2, n2);
    printf("重排后：");
    print_array(nums2, n2);
    printf("预期结果：1 3 5 7 9\n\n");
    
    // 测试用例3：全是偶数
    int nums3[] = {2, 4, 6, 8, 10};
    int n3 = sizeof(nums3) / sizeof(nums3[0]);
    
    printf("测试用例3：\n");
    printf("原数组：");
    print_array(nums3, n3);
    reorder_array(nums3, n3);
    printf("重排后：");
    print_array(nums3, n3);
    printf("预期结果：2 4 6 8 10\n");
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
    solve();
    return 0;
}
