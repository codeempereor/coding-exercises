/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 31.prime_factorization.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h, math.h
 * 功能描述:
 *   1. 质因数分解
 * 算法描述:
 *   - 质因数分解：使用试除法，分解质因数
 * 适用场景:
 *   - 数学问题
 *   - 密码学
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
 * @brief 质因数分解
 * @param n 要分解的正整数
 * @return void
 */
void prime_factorization(int n)
{
    printf("%d = ", n);
    
    if (n <= 1) 
    {
        printf("%d\n", n);
        return;
    }
    
    int factor = 2;     // 从2开始尝试每个可能的因数
    int first = 1;      // 标志位，用于判断是否是第一个因数
    
    while (n > 1) 
    {
        if (n % factor == 0)     // 如果当前因数是n的因数
        {
            if (!first)     // 如果不是第一个因数
            {
                printf(" * ");
            }
            int count = 0;
            while (n % factor == 0)        // 计算当前因数的出现次数
            {
                count++;
                n /= factor;
            }
            if (count == 1)     // 如果当前因数只出现一次
            {
                printf("%d", factor);
            } else     // 如果当前因数出现次数大于1
            {
                printf("%d^%d", factor, count);
            }
            first = 0;
        }
        factor++;
    }
    printf("\n");
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
    
    printf("=== 质因数分解 ===\n");
    
    // 测试用例1：基本情况
    printf("测试用例1:");
    prime_factorization(12);
    printf("\n");
    
    // 测试用例2：包含0的情况
    printf("测试用例2:");
    prime_factorization(0);
    printf("\n");
    
    // 测试用例3：包含负数的情况
    printf("测试用例3:");
    prime_factorization(-12);
    printf("\n");
    
    // 测试用例4：两个数字相邻的情况
    printf("测试用例4:");
    prime_factorization(100);
    printf("\n");

    int test_cases[] = {12, 18, 25, 36, 49, 100, 12345, 999999};
    int n = sizeof(test_cases) / sizeof(test_cases[0]);
    
    for (int i = 0; i < n; i++) 
    {
        prime_factorization(test_cases[i]);
    }
    
    // 测试输入
    int num;
    printf("\n请输入一个正整数: ");
    scanf("%d", &num);
    prime_factorization(num);
    
    return 0;
}
