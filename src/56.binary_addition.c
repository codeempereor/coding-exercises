/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 56.binary_addition.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h, string.h
 * 功能描述:
 *   1. 二进制字符串相加
 * 算法描述:
 *   - 二进制字符串相加：模拟二进制加法，处理进位
 * 适用场景:
 *   - 二进制计算
 *   - 字符串处理
 *   - 模拟运算
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-04-15 三道渊: 初始化文件
 * ============================================================================ */
#include <stdio.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif

#define MAX_N 100001

/**
 * @brief 计算字符串长度
 * @param s 字符串
 * @return int 字符串长度
 */
int strlen(const char *s)
{
    int len = 0;
    while (s[len]) len++;
    return len;
}

/**
 * @brief 二进制字符串相加
 * @param a 第一个二进制字符串
 * @param b 第二个二进制字符串
 * @return char* 相加结果
 */
char* add_binary(char *a, char *b)
{
    int len1 = strlen(a);
    int len2 = strlen(b);
    int carry = 0;
    static char result[MAX_N];
    int index = 0;
    
    int i = len1 - 1, j = len2 - 1;
    while (i >= 0 || j >= 0 || carry > 0)
    {
        int digit1 = i >= 0 ? a[i] - '0' : 0;
        int digit2 = j >= 0 ? b[j] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 2;
        result[index++] = (sum % 2) + '0';
        i--;
        j--;
    }
    
    // 反转结果
    for (int k = 0; k < index / 2; k++)
    {
        char temp = result[k];
        result[k] = result[index - k - 1];
        result[index - k - 1] = temp;
    }
    result[index] = '\0';
    
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
    
    printf("=== 二进制字符串相加 ===\n");
    printf("题目：给定两个用字符串表示的二进制数，返回它们的和\n\n");
    
    // 测试用例
    char *test_cases1[] = {
        "101",
        "0",
        "1",
        "11",
        "1010"
    };
    char *test_cases2[] = {
        "1",
        "1",
        "1",
        "11",
        "1011"
    };
    int test_count = sizeof(test_cases1) / sizeof(test_cases1[0]);
    
    for (int i = 0; i < test_count; i++)
    {
        char *result = add_binary(test_cases1[i], test_cases2[i]);
        printf("测试用例%d: \"%s\" + \"%s\" = \"%s\"\n", 
               i + 1, test_cases1[i], test_cases2[i], result);
    }
    
    return 0;
}