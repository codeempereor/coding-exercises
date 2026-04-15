/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 30.string_elimination.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h, string.h
 * 功能描述:
 *   1. 字符串消除
 * 算法描述:
 *   - 字符串消除：使用栈，模拟消除过程
 * 适用场景:
 *   - 字符串处理
 *   - 栈应用
 *   - 模拟过程
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
 * @brief 消除字符串中连续的重复字符
 * @param str 输入字符串
 * @param result 存储结果的数组
 * @return 消除后的字符串长度
 */
int string_elimination(const char *str, char *result)
{
    int len = 0;
    while (str[len] != '\0') len++;
    
    if (len == 0)
    {
        result[0] = '\0';
        return 0;
    }
    
    int stack[MAX_N];
    int top = -1;
    
    for (int i = 0; i < len; i++)
    {
        if (top >= 0 && stack[top] == str[i])
        {
            top--;
        }
        else
        {
            stack[++top] = str[i];
        }
    }
    
    int result_len = 0;
    for (int i = 0; i <= top; i++)
    {
        result[result_len++] = stack[i];
    }
    result[result_len] = '\0';
    
    return result_len;
}

/**
 * @brief 字符串消除
 * @return void
 */
;
    
    int n = sizeof(test_cases) / sizeof(test_cases[0]);
    
    for (int i = 0; i < n; i++)
    {
        int len = string_elimination(test_cases[i], result);
        printf("测试用例%d: \"%s\"\n", i + 1, test_cases[i]);
        printf("  消除后: \"%s\"\n", result);
        printf("  长度: %d\n\n", len);
    }
}

/**
 * @brief 主函数
 * @return int 程序退出状态码
 */
int main()
{#ifdef _WIN32
    // 设置控制台输出为UTF-8
    SetConsoleOutputCP(CP_UTF8);
    #endif

printf("=== 字符串消除 ===\n");
    printf("题目：消除字符串中连续的重复字符\n\n");
    
    char result[MAX_N];
    
    const char *test_cases[] = {
        "aabccba",
        "abbaca",
        "azxxzy",
        "aaaa",
        "abc",
        ""

return 0;
}
