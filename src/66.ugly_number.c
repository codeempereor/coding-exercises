/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 66.ugly_number.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 丑数
 * 算法描述:
 *   - 丑数：通过生成丑数序列，判断是否为丑数
 * 适用场景:
 *   - 数学问题
 *   - 动态规划
 *   - 序列生成
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
 * @brief 丑数
 * @param n 第n个丑数
 * @return int 第n个丑数
 */
int nthUglyNumber(int n)
{
    int dp[n];
    dp[0] = 1;
    int p2 = 0, p3 = 0, p5 = 0;
    
    for (int i = 1; i < n; i++)
    {
        int next2 = dp[p2] * 2;
        int next3 = dp[p3] * 3;
        int next5 = dp[p5] * 5;
        dp[i] = next2 < next3 ? (next2 < next5 ? next2 : next5) : (next3 < next5 ? next3 : next5);
        
        if (dp[i] == next2) p2++;
        if (dp[i] == next3) p3++;
        if (dp[i] == next5) p5++;
    }
    
    return dp[n - 1];
}

/**
 * @brief 判断是否为丑数
 * @param num 数字
 * @return int 是否为丑数
 */
int isUgly(int num)
{
    if (num <= 0)
    {
        return 0;
    }
    
    while (num % 2 == 0) num /= 2;
    while (num % 3 == 0) num /= 3;
    while (num % 5 == 0) num /= 5;
    
    return num == 1;
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

    printf("=== 丑数 ===\n");
    printf("题目：丑数是只包含质因数2、3和5的正整数\n\n");
    
    // 测试用例1：第n个丑数
    int test_cases_n[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int test_count_n = 10;
    
    printf("测试用例1：第n个丑数\n");
    for (int i = 0; i < test_count_n; i++)
    {
        int n = test_cases_n[i];
        int result = nthUglyNumber(n);
        printf("第%d个丑数: %d\n", n, result);
    }
    printf("\n");
    
    // 测试用例2：判断是否为丑数
    int test_cases_is[] = {6, 8, 14, 1, 0, -1};
    int test_count_is = 6;
    
    printf("测试用例2：判断是否为丑数\n");
    for (int i = 0; i < test_count_is; i++)
    {
        int num = test_cases_is[i];
        int result = isUgly(num);
        printf("%d: %s\n", num, result ? "是丑数" : "不是丑数");
    }

    return 0;
}
