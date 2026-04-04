/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 21.float_to_string.c
 * 作    者: 三道渊
 * 创建日期: 2026-03-29
 * 最后修改: 2026-04-04
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 浮点数转字符串：将浮点数转换为字符串表示
 * 算法描述:
 *   - 分离整数和小数部分：分别处理整数部分和小数部分
 *   - 整数部分：通过取模和除法逐位转换
 *   - 小数部分：通过乘法和取整逐位转换
 *   - 处理符号位和特殊情况
 *   - 时间复杂度O(n)，其中n是数字的位数
 * 适用场景:
 *   - 数据类型转换
 *   - 格式化输出
 *   - 字符串处理
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-04-04 三道渊: 补充算法描述和适用场景，实现完整功能
 *   - 2026-03-29 三道渊: 初始化文件
 * ============================================================================ */

#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif

#define MAX_N 100

/**
 * @brief 整数转字符串
 * @param num 整数
 * @param str 字符串
 */
void int_to_string(int num, char *str)
{
    int i = 0;
    int is_negative = 0;
    
    if (num < 0)
    {
        is_negative = 1;
        num = -num;
    }
    
    if (num == 0)
    {
        str[i++] = '0';
    }
    
    while (num > 0)
    {
        str[i++] = num % 10 + '0';
        num /= 10;
    }
    
    if (is_negative)
    {
        str[i++] = '-';
    }
    
    str[i] = '\0';
    
    int start = 0;
    int end = i - 1;
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

/**
 * @brief 浮点数转字符串
 * @param num 浮点数
 * @param str 字符串
 * @param precision 小数位数
 */
void float_to_string(double num, char *str, int precision)
{
    int i = 0;
    
    if (num < 0)
    {
        str[i++] = '-';
        num = -num;
    }
    
    int int_part = (int)num;
    double frac_part = num - int_part;
    
    int_to_string(int_part, str + i);
    
    while (str[i] != '\0')
    {
        i++;
    }
    
    if (precision > 0)
    {
        str[i++] = '.';
        
        for (int j = 0; j < precision; j++)
        {
            frac_part *= 10;
            int digit = (int)frac_part;
            str[i++] = digit + '0';
            frac_part -= digit;
        }
        
        str[i] = '\0';
    }
}

/**
 * @brief 浮点数转字符串
 * @return void
 */
void solve()
{
    printf("=== 浮点数转字符串 ===\n");
    printf("题目：将浮点数转换为字符串表示\n\n");
    
    char str[MAX_N];
    
    double nums[] = {123.456, -789.123, 0.123, -0.456, 123.0};
    int n = sizeof(nums) / sizeof(nums[0]);
    
    for (int i = 0; i < n; i++)
    {
        float_to_string(nums[i], str, 3);
        printf("测试用例%d: %.3f -> %s\n", i + 1, nums[i], str);
    }
    
    printf("\n测试用例6: 不同精度\n");
    float_to_string(3.1415926, str, 2);
    printf("精度2: %.6f -> %s\n", 3.1415926, str);
    
    float_to_string(3.1415926, str, 4);
    printf("精度4: %.6f -> %s\n", 3.1415926, str);
    
    float_to_string(3.1415926, str, 6);
    printf("精度6: %.6f -> %s\n", 3.1415926, str);
}

/**
 * @brief 主函数
 * @return int 程序退出状态码
 */
int main() {
    #ifdef _WIN32
    // 设置控制台输出为UTF-8
    SetConsoleOutputCP(CP_UTF8);
    #endif
    solve();
    return 0;
}
