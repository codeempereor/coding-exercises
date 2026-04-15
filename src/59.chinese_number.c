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

/**
 * @brief 数字对应的中文
 */
const char *digits[] = {"零", "一", "二", "三", "四", "五", "六", "七", "八", "九"};

/**
 * @brief 单位
 */
const char *units[] = {"", "十", "百", "千"};

/**
 * @brief 大单位
 */
const char *big_units[] = {"", "万", "亿"};

/**
 * @brief 将数字转换为中文
 * @param num 数字
 * @param result 结果字符串
 * @param unit_pos 单位位置
 */
void number_to_chinese(long long num, char *result, int unit_pos)
{
    if (num == 0)
    {
        return;
    }
    
    long long part = num % 10000;
    char temp[50] = {0};
    int temp_len = 0;
    
    // 处理每一位
    int flag = 0; // 标记是否需要加零
    for (int i = 0; i < 4; i++)
    {
        int digit = part % 10;
        part /= 10;
        
        if (digit != 0)
        {
            if (flag)
            {
                strcat(temp, "零");
                flag = 0;
            }
            strcat(temp, digits[digit]);
            if (i > 0)
            {
                strcat(temp, units[i]);
            }
        }
        else if (temp_len > 0)
        {
            flag = 1;
        }
    }
    
    // 反转temp
    int len = strlen(temp);
    for (int i = 0; i < len / 2; i++)
    {
        char t = temp[i];
        temp[i] = temp[len - i - 1];
        temp[len - i - 1] = t;
    }
    
    // 添加大单位
    if (strlen(temp) > 0)
    {
        strcat(temp, big_units[unit_pos]);
        strcat(temp, result);
        strcpy(result, temp);
    }
    
    // 递归处理高位
    number_to_chinese(num / 10000, result, unit_pos + 1);
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
    
    if (num < 0)
    {
        strcat(result, "负");
        num = -num;
    }
    
    if (num == 0)
    {
        strcat(result, "零");
        return result;
    }
    
    number_to_chinese(num, result, 0);
    
    // 处理特殊情况：十
    if (strlen(result) == 2 && result[0] == '一' && result[1] == '十')
    {
        result[0] = '十';
        result[1] = '\0';
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