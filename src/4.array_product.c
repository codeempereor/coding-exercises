/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 4.array_product.c
 * 作    者: 三道渊
 * 创建日期: 2026-03-29
 * 最后修改: 2026-03-29
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 数组乘积
 * 算法描述:
 *   - 左右乘积数组法：计算每个元素左侧和右侧的乘积，然后相乘得到结果
 *   - 先计算左侧乘积数组，再计算右侧乘积数组，最后将对应位置相乘
 *   - 时间复杂度O(n)，空间复杂度O(1)（除输出数组外）
 * 适用场景:
 *   - 数组元素乘积计算
 *   - 数学计算中的前缀积和后缀积
 *   - 不使用除法的情况下计算元素乘积
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-03-29 三道渊: 初始化文件
 * ============================================================================ */

#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif

#define MAX_N 100

/**
 * @brief 计算除自身外数组所有元素的乘积
 * @param nums 输入数组
 * @param n 数组长度
 * @param output 输出数组
 */
void product_except_self(int nums[], int n, int output[])
{
    // 计算左侧乘积，从左到右
    int left = 1;
    for (int i = 0; i < n; i++)
    {
        output[i] = left;
        left *= nums[i];
    }
    
    // 计算右侧乘积并与左侧乘积相乘，从右到左
    int right = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        output[i] *= right;
        right *= nums[i];
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
 * @brief 数组乘积
 * @return void
 */
;
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    int output1[n1];
    
    printf("测试用例1:");
    print_array(nums1, n1);
    
    product_except_self(nums1, n1, output1);
    
    printf("结果：");
    print_array(output1, n1);
    printf("预期:24 12 8 6\n");
    
    // 测试用例2：包含0的情况
    int nums2[] = {1, 2, 0, 4};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    int output2[n2];
    
    printf("\n测试用例2:");
    print_array(nums2, n2);
    
    product_except_self(nums2, n2, output2);
    
    printf("结果：");
    print_array(output2, n2);
    printf("预期:0 0 8 0\n");
    
    // 测试用例3：包含负数的情况
    int nums3[] = {-1, 2, -3, 4};
    int n3 = sizeof(nums3) / sizeof(nums3[0]);
    int output3[n3];
    
    printf("\n测试用例3:"); 
    print_array(nums3, n3);
    
    product_except_self(nums3, n3, output3);
    
    printf("结果：");
    print_array(output3, n3);
    printf("预期：-24 12 -8 6\n");
    
    // 测试用例4：只有两个元素的情况
    int nums4[] = {2, 3};
    int n4 = sizeof(nums4) / sizeof(nums4[0]);
    int output4[n4];
    
    printf("\n测试用例4:");
    print_array(nums4, n4);
    
    product_except_self(nums4, n4, output4);
    
    printf("结果：");
    print_array(output4, n4);
    printf("预期:3 2\n");
}

/**
 * @brief 主函数
 * @return int 程序退出状态码
 */
int main()
{#ifdef _WIN32
    // 设置控制台输出为UTF-8
    SetConsoleOutputCP(CP_UTF8);
    #endif

printf("=== 数组乘积 ===\n");
    
    // 测试用例1：基本情况
    int nums1[] = {1, 2, 3, 4

return 0;
}
