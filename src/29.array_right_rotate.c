/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 29.array_right_rotate.c
 * 作    者: 三道渊
 * 创建日期: 2026-03-30
 * 最后修改: 2026-03-30
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 数组右旋转
 * 算法描述:
 *   - 三次反转法：通过三次反转操作实现数组右旋转
 *   - 步骤1：反转整个数组
 *   - 步骤2：反转前k个元素
 *   - 步骤3：反转剩余的元素
 *   - 时间复杂度O(n)，空间复杂度O(1)
 * 适用场景:
 *   - 数组旋转
 *   - 循环移位
 *   - 数据重排
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-03-30 三道渊: 初始化文件
 * ============================================================================ */

#include <stdio.h>

#define MAX_N 100

/**
 * @brief 反转数组的指定范围
 * @param arr 输入数组
 * @param start 起始位置
 * @param end 结束位置
 */
void reverse_range(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

/**
 * @brief 将数组向右旋转k个位置
 * @param arr 输入数组
 * @param n 数组长度
 * @param k 旋转位置数
 */
void array_right_rotate(int arr[], int n, int k)
{
    if (n == 0 || k % n == 0)
    {
        return;
    }
    
    k = k % n; // 处理k大于n的情况
    
    // 三次反转法
    // 步骤1：反转整个数组
    reverse_range(arr, 0, n - 1);
    // 步骤2：反转前k个元素
    reverse_range(arr, 0, k - 1);
    // 步骤3：反转剩余的元素
    reverse_range(arr, k, n - 1);
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
 * @brief 数组右旋转
 * @return void
 */
void solve()
{
    printf("=== 数组右旋转 ===\n");
    printf("题目：将数组中的元素向右旋转k个位置\n\n");
    
    // 测试用例1：基本情况
    int nums1[] = {1, 2, 3, 4, 5, 6, 7};
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    int k1 = 3;
    
    printf("测试用例1：\n");
    printf("原数组：");
    print_array(nums1, n1);
    printf("旋转位置：%d\n", k1);
    array_right_rotate(nums1, n1, k1);
    printf("旋转后：");
    print_array(nums1, n1);
    printf("预期结果：5 6 7 1 2 3 4\n\n");
    
    // 测试用例2：k大于数组长度
    int nums2[] = {1, 2, 3};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    int k2 = 4;
    
    printf("测试用例2：\n");
    printf("原数组：");
    print_array(nums2, n2);
    printf("旋转位置：%d\n", k2);
    array_right_rotate(nums2, n2, k2);
    printf("旋转后：");
    print_array(nums2, n2);
    printf("预期结果：3 1 2\n\n");
    
    // 测试用例3：k为0
    int nums3[] = {1, 2, 3, 4, 5};
    int n3 = sizeof(nums3) / sizeof(nums3[0]);
    int k3 = 0;
    
    printf("测试用例3：\n");
    printf("原数组：");
    print_array(nums3, n3);
    printf("旋转位置：%d\n", k3);
    array_right_rotate(nums3, n3, k3);
    printf("旋转后：");
    print_array(nums3, n3);
    printf("预期结果：1 2 3 4 5\n");
}

/**
 * @brief 主函数
 * @return int 程序退出状态码
 */
int main()
{
    solve();
    return 0;
}
