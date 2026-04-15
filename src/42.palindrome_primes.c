/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 42.palindrome_primes.c
 * 作    者: 三道渊
 * 创建日期: 2026-03-29
 * 最后修改: 2026-04-09
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 回文素数
 * 算法描述:
 *   - 素数判断：试除法，排除偶数和小于等于1的数
 *   - 回文数判断：将数字反转后与原数比较
 *   - 遍历指定范围，筛选同时满足素数和回文数条件的数
 *   - 时间复杂度：O(n√n)
 *   - 空间复杂度：O(1)
 * 适用场景:
 *   - 数学问题：回文素数查找
 *   - 数论研究：特殊数的性质
 *   - 算法练习：组合条件筛选
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-04-09 三道渊: 实现回文素数功能，添加测试用例
 *   - 2026-03-29 三道渊: 初始化文件
 * ============================================================================ */

#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif

#define MAX_N 100

/**
 * @brief 素数
 * @return int
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
 * @brief 回文数
 * @return int
 */
int is_palindrome(int n)
{
    int reverse = 0;
    int temp = n;
    while (temp > 0)
    {
        reverse = reverse * 10 + temp % 10;
        temp /= 10;
    }
    return reverse == n;
}

/**
 * @brief 主函数 回文素数
 * @return int 程序退出状态码
 */
int main()
{
    #ifdef _WIN32
    // 设置控制台输出为UTF-8
    SetConsoleOutputCP(CP_UTF8);
    #endif

    printf("=== 回文素数 ===\n");

    //范围
    int start = 1;
    int end = 1000;

    printf("%d 到 %d回文素数:\n", start, end);

    int count = 0;

    for (int i = start; i <= end; i++)
    {
        if (is_prime(i) && is_palindrome(i))
        {
            printf("%d\t\t", i);
            count++;
        }
    }
    printf("\n共 %d 个回文素数\n", count);
return 0;
}
