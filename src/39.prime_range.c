/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 39.prime_range.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h, math.h
 * 功能描述:
 *   1. 区间素数
 * 算法描述:
 *   - 区间素数：使用筛法，筛选出区间内的素数
 * 适用场景:
 *   - 数学问题
 *   - 素数筛选
 *   - 数论研究
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
 * @brief 判断一个数是否是素数
 * @param n 正整数
 * @return int 1表示是素数，0表示不是
 */
int is_prime(int n)
{
    if (n <= 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        return 0;
    }
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief 输出指定区间内的所有素数
 * @param start 起始值
 * @param end 结束值
 * @return int 素数的个数
 */
int prime_range(int start, int end)
{
    int count = 0;
    
    for (int i = start; i <= end; i++)
    {
        if (is_prime(i))
        {
            printf("%d ", i);
            count++;
        }
    }
    
    printf("\n");
    return count;
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
    
    printf("=== 区间素数 ===\n");
    printf("题目：找出指定区间内的所有素数\n\n");
    
    // 测试用例
    int test_cases[][2] = {
        {1, 20},
        {10, 50},
        {50, 100},
        {100, 200},
        {2, 10}
    };
    int test_count = sizeof(test_cases) / sizeof(test_cases[0]);
    
    for (int i = 0; i < test_count; i++)
    {
        int start = test_cases[i][0];
        int end = test_cases[i][1];
        printf("测试用例%d: [%d, %d] → ", i + 1, start, end);
        int count = prime_range(start, end);
        printf("共%d个素数\n", count);
    }
    
    // 用户输入
    int start, end;
    printf("\n请输入起始值: ");
    scanf("%d", &start);
    printf("请输入结束值: ");
    scanf("%d", &end);
    
    printf("结果: ");
    int count = prime_range(start, end);
    printf("共%d个素数\n", count);
    
    return 0;
}
