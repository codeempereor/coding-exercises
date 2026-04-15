/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 59.chinese_number.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h, string.h
 * 功能描述:
 *   1. 整数的中文读法
 * 算法描述:
 *   - 整数的中文读法：处理各个段位的数字，添加适当的单位
 * 适用场景:
 *   - 数字转换
 *   - 中文表示
 *   - 格式化输出
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-04-15 三道渊: 初始化文件
 * ============================================================================ */
#include <stdio.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif

#define MAX_LEN 100

// 数字对应的中文
const char *digits[] = {"零", "一", "二", "三", "四", "五", "六", "七", "八", "九"};

// 单位
const char *units[] = {"", "十", "百", "千"};

// 大单位
const char *big_units[] = {"", "万", "亿"};

/**
 * @brief 处理四位以内的数字
 * @param num 数字（0-9999）
 * @param result 结果字符串
 * @return int 是否有非零数字
 */
int process_four_digits(int num, char *result)
{
    if (num == 0)
    {
        return 0;
    }
    
    int has_digit = 0;
    int need_zero = 0;
    char temp[20] = {0};
    int temp_pos = 0;
    
    // 从高位到低位处理
    for (int i = 3; i >= 0; i--)
    {
        int digit = (num / 1000) % 10;
        num %= 1000;
        
        if (i == 2)
        {
            digit = (num / 100) % 10;
            num %= 100;
        }
        else if (i == 1)
        {
            digit = (num / 10) % 10;
            num %= 10;
        }
        else if (i == 0)
        {
            digit = num;
        }
        
        if (digit != 0)
        {
            if (need_zero)
            {
                // 添加零
                strcat(temp, "零");
                need_zero = 0;
            }
            
            // 添加数字
            strcat(temp, digits[digit]);
            
            // 添加单位
            if (i > 0)
            {
                strcat(temp, units[i]);
            }
            
            has_digit = 1;
        }
        else if (has_digit)
        {
            need_zero = 1;
        }
    }
    
    if (has_digit)
    {
        strcat(result, temp);
    }
    
    return has_digit;
}

/**
 * @brief 将整数转换为中文读法
 * @param num 整数
 * @return char* 中文读法
 */
char* number_to_chinese_string(long long num)
{
    static char result[MAX_LEN] = {0};
    memset(result, 0, sizeof(result));
    
    // 处理负数
    if (num < 0)
    {
        strcat(result, "负");
        num = -num;
    }
    
    // 处理零
    if (num == 0)
    {
        strcat(result, "零");
        return result;
    }
    
    // 处理各个段位
    int segments[3] = {0};
    segments[0] = num % 10000;
    segments[1] = (num / 10000) % 10000;
    segments[2] = num / 100000000;
    
    // 从高位到低位处理
    int has_upper_digit = 0;
    
    // 处理亿位
    if (segments[2] > 0)
    {
        process_four_digits(segments[2], result);
        strcat(result, "亿");
        has_upper_digit = 1;
    }
    
    // 处理万位
    if (segments[1] > 0)
    {
        if (has_upper_digit && segments[1] < 1000)
        {
            strcat(result, "零");
        }
        process_four_digits(segments[1], result);
        strcat(result, "万");
        has_upper_digit = 1;
    }
    
    // 处理个位
    if (segments[0] > 0)
    {
        if (has_upper_digit && segments[0] < 1000)
        {
            strcat(result, "零");
        }
        process_four_digits(segments[0], result);
    }
    
    // 处理特殊情况：一十 -> 十
    if (strlen(result) == 2 && strcmp(result, "一十") == 0)
    {
        strcpy(result, "十");
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
    
    printf("=== 整数的中文读法 ===\n");
    printf("题目：给定一个整数，输出它的中文读法\n\n");
    
    // 测试用例
    long long test_cases[] = {
        114514,
        1000,
        -1035,
        0,
        123456789,
        100000000,
        999999999,
        1001,
        1010,
        10000
    };
    int test_count = sizeof(test_cases) / sizeof(test_cases[0]);
    
    for (int i = 0; i < test_count; i++)
    {
        char *result = number_to_chinese_string(test_cases[i]);
        printf("测试用例%d: %lld → %s\n", i + 1, test_cases[i], result);
    }
    
    return 0;
}