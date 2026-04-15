/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 11.max_partition_equality.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 最大分区相等和
 * 算法描述:
 *   - 最大分区相等和：使用前缀和和哈希表，寻找可能的分区点
 * 适用场景:
 *   - 数组分割
 *   - 资源分配
 *   - 平衡问题
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
 * @brief 计算数组的前缀和
 * @param arr 输入数组
 * @param n 数组长度
 * @param prefix 前缀和数组
 */
void compute_prefix_sum(int arr[], int n, long long prefix[])
{
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }
}

/**
 * @brief 查找等和分割的最大长度
 * @param arr 输入数组
 * @param n 数组长度
 * @return 最大分割长度，0表示无法分割
 */
int max_partition_equality(int arr[], int n)
{
    // 计算总数组和
    long long total_sum = 0;
    for (int i = 0; i < n; i++)
    {
        total_sum += arr[i];
    }
    
    // 如果总和不等于两倍的前缀和，说明可以分割
    // 遍历所有可能的分割点
    long long prefix_sum = 0;
    int max_len = 0;
    
    for (int i = 0; i < n - 1; i++)  // 分割点不能是最后一个元素
    {
        prefix_sum += arr[i];
        
        // 检查前缀和 * 2 是否等于剩余部分和
        long long remaining_sum = total_sum - prefix_sum;
        
        // 如果当前前缀和等于剩余部分和，说明可以分割
        if (prefix_sum == remaining_sum)
{
            // 分割长度为 i + 1（从0到i）
            int current_len = i + 1;
            if (current_len > max_len)
            {
                max_len = current_len;
            }
        }
    }
    
    return max_len;
}

/**
 * @brief 打印数组
 * @param arr 输入数组
 * @param n 数组长度
 */
void print_array(int arr[], int n)
{
    printf("数组: [");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i < n - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
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

    printf("=== 最大等和分割 ===\n");
    printf("题目：将数组分割成两部分，使两部分和相等，返回能分割的最大子数组长度\n\n");
    
    // 测试用例1：可以分割
    int arr1[] = {1, 2, 3, 4, 5, 6};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    
    printf("测试用例1：\n");
    print_array(arr1, n1);
    int result1 = max_partition_equality(arr1, n1);
    printf("最大等和分割长度：%d\n", result1);
    printf("预期：3（分割为[1,2,3]和[4,5,6]）\n\n");
    
    // 测试用例2：无法分割
    int arr2[] = {1, 2, 3};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    printf("测试用例2：\n");
    print_array(arr2, n2);
    int result2 = max_partition_equality(arr2, n2);
    printf("最大等和分割长度：%d\n", result2);
    printf("预期：0（无法分割）\n\n");
    
    // 测试用例3：全部相等
    int arr3[] = {2, 2, 2, 2};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    
    printf("测试用例3：\n");
    print_array(arr3, n3);
    int result3 = max_partition_equality(arr3, n3);
    printf("最大等和分割长度：%d\n", result3);
    printf("预期：2（分割为[2,2]和[2,2]）\n\n");
    
    // 测试用例4：有一个分割点
    int arr4[] = {3, 1, 2, 3, 1};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    
    printf("测试用例4：\n");
    print_array(arr4, n4);
    int result4 = max_partition_equality(arr4, n4);
    printf("最大等和分割长度：%d\n", result4);
    printf("预期：3（分割为[3,1,2]和[3,1]）\n");

    return 0;
}
