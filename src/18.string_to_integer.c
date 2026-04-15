/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 18.string_to_integer.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h, string.h
 * 功能描述:
 *   1. 字符串转整数
 * 算法描述:
 *   - 字符串转整数：处理符号、数字和边界情况
 * 适用场景:
 *   - 数据转换
 *   - 输入处理
 *   - 边界情况处理
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-04-15 三道渊: 初始化文件
 * ============================================================================ */
#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif
#include <string.h>
#include <ctype.h>
#include <limits.h>

/**
 * @brief 将字符串转换为整数
 * @param s 输入字符串
 * @return 转换后的整数
 */
int string_to_integer(const char *s)
{
    if (s == NULL || *s == '\0')
    {
        return 0;
    }
    
    int i = 0;
    int n = strlen(s);
    int sign = 1;
    long long result = 0;
    
    // 跳过前导空格
    while (i < n && isspace(s[i]))
    {
        i++;
    }
    
    // 处理符号
    if (i < n && (s[i] == '+' || s[i] == '-'))
    {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }
    
    // 逐位转换
    while (i < n && isdigit(s[i]))
    {
        int digit = s[i] - '0';
        
        // 检查溢出
        if (result > (LLONG_MAX - digit) / 10)
        {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        
        result = result * 10 + digit;
        i++;
    }
    
    result *= sign;
    
    // 处理溢出
    if (result > INT_MAX)
{
        return INT_MAX;
    }
    if (result < INT_MIN)
    {
        return INT_MIN;
    }
    
    return (int)result;
}

/**
 * @brief 字符串转整数
 * @return void
 */


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

printf("=== 字符串转整数 ===\n");
    printf("题目：将字符串转换为整数\n\n");
    
    // 测试用例1：基本情况
    char s1[] = "123";
    
    printf("测试用例1：\n");
    printf("输入字符串：%s\n", s1);
    int result1 = string_to_integer(s1);
    printf("转换结果：%d\n", result1);
    printf("预期结果：123\n\n");
    
    // 测试用例2：带负号
    char s2[] = "-123";
    
    printf("测试用例2：\n");
    printf("输入字符串：%s\n", s2);
    int result2 = string_to_integer(s2);
    printf("转换结果：%d\n", result2);
    printf("预期结果：-123\n\n");
    
    // 测试用例3：带空格
    char s3[] = "   456";
    
    printf("测试用例3：\n");
    printf("输入字符串：%s\n", s3);
    int result3 = string_to_integer(s3);
    printf("转换结果：%d\n", result3);
    printf("预期结果：456\n\n");
    
    // 测试用例4：溢出
    char s4[] = "2147483648";
    
    printf("测试用例4：\n");
    printf("输入字符串：%s\n", s4);
    int result4 = string_to_integer(s4);
    printf("转换结果：%d\n", result4);
    printf("预期结果：2147483647 (INT_MAX)\n");

return 0;
}
