/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 57.sum_1_to_n.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 求1+2+3+...+n
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-04-15 三道渊: 初始化文件
 * ============================================================================ */

#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif

/**
 * @brief 求1+2+3+...+n
 * @param n 正整数
 * @return int 和
 */
int sum_n(int n)
{
    int sum = n;
    // 使用逻辑与的短路特性终止递归
    // 当n为1时，n-1为0，&&后面的表达式不会执行
    (n > 1) && (sum += sum_n(n - 1));
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
    
    printf("=== 求1+2+3+...+n ===\n");
    printf("题目：求1+2+3+...+n，不能使用乘除法、for、while、if等关键字\n\n");
    
    // 测试用例
    int test_cases[] = {
        1,
        5,
        10,
        100,
        200
    };
    int test_count = sizeof(test_cases) / sizeof(test_cases[0]);
    
    for (int i = 0; i < test_count; i++)
    {
        int result = sum_n(test_cases[i]);
        printf("测试用例%d: 1+2+...+%d = %d\n", 
               i + 1, test_cases[i], result);
    }
    
    return 0;
}