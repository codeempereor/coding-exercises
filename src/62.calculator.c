/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 62.calculator.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h, string.h
 * 功能描述:
 *   1. 计算器
 * 算法描述:
 *   - 计算器：处理表达式的计算，支持加减乘除和括号
 * 适用场景:
 *   - 表达式计算
 *   - 栈应用
 *   - 解析器设计
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
 * @brief 整数计算器
 * @param s 表达式字符串
 * @return int 计算结果
 */
int calculate(char* s)
{
    int stack[1000];
    int top = -1;
    int num = 0;
    char sign = '+';
    int i = 0;
    
    while (s[i] != '\0')
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            num = num * 10 + (s[i] - '0');
        }
        else if (s[i] == '(')
        {
            // 递归处理括号
            int j = i;
            int count = 0;
            while (s[j] != '\0')
            {
                if (s[j] == '(') count++;
                if (s[j] == ')') count--;
                if (count == 0) break;
                j++;
            }
            char temp[1000];
            int k = 0;
            for (int m = i + 1; m < j; m++)
            {
                temp[k++] = s[m];
            }
            temp[k] = '\0';
            num = calculate(temp);
            i = j;
        }
        
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '\0' || s[i + 1] == '\0')
        {
            if (sign == '+')
            {
                stack[++top] = num;
            }
            else if (sign == '-')
            {
                stack[++top] = -num;
            }
            else if (sign == '*')
            {
                stack[top] *= num;
            }
            else if (sign == '/')
            {
                stack[top] /= num;
            }
            sign = s[i];
            num = 0;
        }
        i++;
    }
    
    int result = 0;
    for (int j = 0; j <= top; j++)
    {
        result += stack[j];
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

    printf("=== 整数计算器 ===\n");
    printf("题目：实现一个基本的计算器，支持加减乘除和括号\n\n");
    
    // 测试用例
    char* test_cases[] = {
        "3+2*2",
        "3/2",
        "3+5/2",
        "(3+2)*2",
        "3*(4+5)/2"
    };
    int test_count = 5;
    
    for (int i = 0; i < test_count; i++)
    {
        int result = calculate(test_cases[i]);
        printf("测试用例%d: %s = %d\n", i + 1, test_cases[i], result);
    }

    return 0;
}
