/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 52.first_missing_positive_2.c
 * 作    者: 三道渊
 * 创建日期: 2026-03-29
 * 最后修改: 2026-03-29
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 缺失的第一个正数（第二版）
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
 * @brief 找到缺失的最小正整数
 * @param nums 数组
 * @param n 数组大小
 * @return int 缺失的最小正整数
 */
int first_missing_positive(int *nums, int n)
{
    // 处理负数和零，将它们标记为n+1
    for (int i = 0; i < n; i++)
    {
        if (nums[i] <= 0)
        {
            nums[i] = n + 1;
        }
    }
    
    // 标记出现过的正数
    for (int i = 0; i < n; i++)
    {
        int num = abs(nums[i]);
        if (num <= n)
        {
            nums[num - 1] = -abs(nums[num - 1]);
        }
    }
    
    // 找到第一个正数的位置
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            return i + 1;
        }
    }
    
    // 所有位置都被标记，返回n+1
    return n + 1;
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
    
    printf("=== 缺失的第一个正数（第二版） ===\n");
    printf("题目：找出数组中缺失的最小正整数\n\n");
    
    // 测试用例
    int test_cases[][10] = {
        {1, 0, 2},
        {-2, 3, 4, 1, 5},
        {3, 4, -1, 1},
        {7, 8, 9, 11, 12},
        {1, 2, 3, 4, 5}
    };
    int test_sizes[] = {3, 5, 4, 5, 5};
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
        printf(" → ");
        
        int result = first_missing_positive(nums, test_sizes[i]);
        printf("%d\n", result);
    }
    
    return 0;
}
