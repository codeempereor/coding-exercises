/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 41.first_missing_positive.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 缺失的第一个正数
 * 算法描述:
 *   - 缺失的第一个正数：使用原地哈希，标记出现的正数
 * 适用场景:
 *   - 数组处理
 *   - 原地算法
 *   - 异常检测
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
 * @brief 交换两个数
 * @param a 第一个数的指针
 * @param b 第二个数的指针
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief 找出缺失的第一个正数
 * @param nums 数组
 * @param n 数组长度
 * @return int 缺失的第一个正数
 */
int first_missing_positive(int nums[], int n)
{
    for (int i = 0; i < n; i++)
    {
        // 将元素放到正确的位置
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
        {
            swap(&nums[i], &nums[nums[i] - 1]);
        }
    }
    
    // 找到第一个缺失的正数
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i + 1)
        {
            return i + 1;
        }
    }
    
    // 所有正数都存在，返回n+1
    return n + 1;
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
    
    printf("=== 缺失的第一个正数 ===\n");
    printf("题目：找出数组中缺失的第一个正数\n\n");
    
    // 测试用例
    int test_cases[][10] = {
        {1, 2, 0},
        {3, 4, -1, 1},
        {7, 8, 9, 11, 12},
        {1, 2, 3, 4, 5},
        {-1, -2, -3}
    };
    int test_sizes[] = {3, 4, 5, 5, 3};
    int test_count = sizeof(test_cases) / sizeof(test_cases[0]);
    
    for (int i = 0; i < test_count; i++)
    {
        int result = first_missing_positive(test_cases[i], test_sizes[i]);
        printf("测试用例%d: [", i + 1);
        for (int j = 0; j < test_sizes[i]; j++)
        {
            printf("%d", test_cases[i][j]);
            if (j < test_sizes[i] - 1)
            {
                printf(", ");
            }
        }
        printf("] → %d\n", result);
    }
    
    return 0;
}
