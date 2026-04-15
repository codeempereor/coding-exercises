/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 47.remove_duplicates.c
 * 作    者: 三道渊
 * 创建日期: 2026-03-29
 * 最后修改: 2026-03-29
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 移除重复元素
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
 * @brief 移除排序数组中的重复项
 * @param nums 排序数组
 * @param numsSize 数组大小
 * @return int 移除重复项后的数组长度
 */
int remove_duplicates(int* nums, int numsSize)
{
    if (numsSize == 0)
    {
        return 0;
    }
    
    int slow = 0;
    for (int fast = 1; fast < numsSize; fast++)
    {
        if (nums[fast] != nums[slow])
        {
            slow++;
            nums[slow] = nums[fast];
        }
    }
    
    return slow + 1;
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
    
    printf("=== 移除重复元素 ===\n");
    printf("题目：删除排序数组中的重复项\n\n");
    
    // 测试用例
    int test_cases[][10] = {
        {1, 1, 2},
        {0, 0, 1, 1, 1, 2, 2, 3, 3, 4},
        {},
        {1},
        {1, 2, 3, 4, 5}
    };
    int test_sizes[] = {3, 10, 0, 1, 5};
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
        
        int new_size = remove_duplicates(nums, test_sizes[i]);
        
        printf(" → ");
        print_array(nums, new_size);
        printf(" (长度: %d)\n", new_size);
    }
    
    return 0;
}
