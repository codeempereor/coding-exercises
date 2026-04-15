/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 69.array_cyclic_shift.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 数组循环移位
 * 算法描述:
 *   - 数组循环移位：通过三次反转实现
 * 适用场景:
 *   - 数组处理
 *   - 循环移位
 *   - 数据重组
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
 * @brief 反转数组
 * @param nums 数组
 * @param start 起始位置
 * @param end 结束位置
 */
void reverse(int* nums, int start, int end)
{
    while (start < end)
    {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

/**
 * @brief 数组循环移位
 * @param nums 数组
 * @param numsSize 数组大小
 * @param k 移位次数
 */
void rotate(int* nums, int numsSize, int k)
{
    k = k % numsSize;
    if (k == 0)
    {
        return;
    }
    
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
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

    printf("=== 数组循环移位 ===\n");
    printf("题目：将数组向右循环移动k个位置\n\n");
    
    // 测试用例
    int test_cases[][5] = {
        {1, 2, 3, 4, 5},
        {0, 1, 2, 0, 0},
        {-1, -100, 3, 99, 0}
    };
    int test_sizes[] = {5, 3, 4};
    int test_ks[] = {2, 4, 2};
    int test_count = 3;
    
    for (int i = 0; i < test_count; i++)
    {
        int nums[5];
        for (int j = 0; j < test_sizes[i]; j++)
        {
            nums[j] = test_cases[i][j];
        }
        
        printf("测试用例%d: ", i + 1);
        printf("原数组: ");
        for (int j = 0; j < test_sizes[i]; j++)
        {
            printf("%d ", nums[j]);
        }
        printf("k=%d\n", test_ks[i]);
        
        rotate(nums, test_sizes[i], test_ks[i]);
        
        printf("移位后: ");
        for (int j = 0; j < test_sizes[i]; j++)
        {
            printf("%d ", nums[j]);
        }
        printf("\n\n");
    }

    return 0;
}
