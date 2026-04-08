/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 36.amicable_numbers.c
 * 作    者: 三道渊
 * 创建日期: 2026-03-29
 * 最后修改: 2026-04-08
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 亲密数
 * 算法描述:
 *   - 计算每个数的真因数之和
 *   - 对于每个数a，计算其真因数之和b
 *   - 检查b的真因数之和是否等于a，且a < b
 *   - 时间复杂度：O(n√n)
 * 适用场景:
 *   - 数学问题：亲密数查找
 *   - 因数分解：真因数计算
 *   - 数论研究：数的性质分析
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-04-08 三道渊: 实现亲密数功能，添加测试用例
 *   - 2026-03-29 三道渊: 初始化文件
 * ============================================================================ */

#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif

#define MAX_N 100

/**
 * @brief 计算一个数的所有真因数之和
 * @param n 正整数
 * @return int 真因数之和
 */
int sum_of_proper_divisors(int n)
{
    if (n <= 1)
    {
        return 0;
    }
    
    int sum = 1;  // 1是所有数的真因数
    
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
            if (i != n / i)
            {
                sum += n / i;
            }
        }
    }
    
    return sum;
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
    
    printf("=== 亲密数 ===\n");
    printf("题目：找出指定范围内的所有亲密数对\n\n");
    
    // 查找10000以内的亲密数
    printf("10000以内的亲密数对：\n");
    
    for (int a = 2; a < 10000; a++)
    {
        int b = sum_of_proper_divisors(a);
        
        // 避免重复计算，只处理a < b的情况
        if (a < b && sum_of_proper_divisors(b) == a)
        {
            printf("(%d, %d)\n", a, b);
        }
    }
    
    // 测试用例
    printf("\n测试用例：\n");
    int test_cases[] = {220, 284, 1184, 1210};
    int test_count = sizeof(test_cases) / sizeof(test_cases[0]);
    
    for (int i = 0; i < test_count; i++)
    {
        int num = test_cases[i];
        int sum = sum_of_proper_divisors(num);
        printf("%d的真因数之和: %d\n", num, sum);
    }
    
    return 0;
}
