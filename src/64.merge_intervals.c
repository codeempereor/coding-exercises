/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 64.merge_intervals.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h, stdlib.h
 * 功能描述:
 *   1. 合并区间
 * 算法描述:
 *   - 合并区间：按起始位置排序，然后合并重叠的区间
 * 适用场景:
 *   - 区间处理
 *   - 排序算法
 *   - 数据合并
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
 * @brief 比较函数
 * @param a 第一个区间
 * @param b 第二个区间
 * @return int 比较结果
 */
int compare(const void* a, const void* b)
{
    int* interval1 = *(int**)a;
    int* interval2 = *(int**)b;
    return interval1[0] - interval2[0];
}

/**
 * @brief 合并区间
 * @param intervals 区间数组
 * @param intervalsSize 区间数量
 * @param returnSize 返回大小
 * @return int** 合并后的区间
 */
int** merge(int** intervals, int intervalsSize, int* returnSize)
{
    if (intervalsSize == 0)
    {
        *returnSize = 0;
        return NULL;
    }
    
    qsort(intervals, intervalsSize, sizeof(int*), compare);
    
    int** result = (int**)malloc(intervalsSize * sizeof(int*));
    *returnSize = 0;
    
    result[*returnSize] = (int*)malloc(2 * sizeof(int));
    result[*returnSize][0] = intervals[0][0];
    result[*returnSize][1] = intervals[0][1];
    (*returnSize)++;
    
    for (int i = 1; i < intervalsSize; i++)
    {
        int* last = result[*returnSize - 1];
        if (intervals[i][0] <= last[1])
        {
            if (intervals[i][1] > last[1])
            {
                last[1] = intervals[i][1];
            }
        }
        else
        {
            result[*returnSize] = (int*)malloc(2 * sizeof(int));
            result[*returnSize][0] = intervals[i][0];
            result[*returnSize][1] = intervals[i][1];
            (*returnSize)++;
        }
    }
    
    return result;
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

    printf("=== 合并区间 ===\n");
    printf("题目：合并所有重叠的区间\n\n");
    
    // 测试用例
    int test_cases[][2] = {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18}
    };
    int intervalsSize = 4;
    int** intervals = (int**)malloc(intervalsSize * sizeof(int*));
    for (int i = 0; i < intervalsSize; i++)
    {
        intervals[i] = (int*)malloc(2 * sizeof(int));
        intervals[i][0] = test_cases[i][0];
        intervals[i][1] = test_cases[i][1];
    }
    
    int returnSize;
    int** result = merge(intervals, intervalsSize, &returnSize);
    
    printf("测试用例1:\n");
    printf("输入: [[1,3],[2,6],[8,10],[15,18]]\n");
    printf("输出: ");
    for (int i = 0; i < returnSize; i++)
    {
        printf("[%d,%d]", result[i][0], result[i][1]);
        if (i < returnSize - 1)
        {
            printf(",");
        }
        free(result[i]);
    }
    printf("\n");
    
    free(result);
    for (int i = 0; i < intervalsSize; i++)
    {
        free(intervals[i]);
    }
    free(intervals);

    return 0;
}
