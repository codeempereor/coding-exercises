/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 44.string_multiply.c
 * 作    者: 三道渊
 * 创建日期: 2026-03-29
 * 最后修改: 2026-03-29
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 字符串相乘
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-03-29 三道渊: 初始化文件
 * ============================================================================ */

#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif

#define MAX_N 100

/**
 * @brief 字符串相乘
 * @param num1 第一个数字字符串
 * @param num2 第二个数字字符串
 * @return char* 乘积字符串
 */
char* multiply(char *num1, char *num2)
{
    int len1 = 0, len2 = 0;
    while (num1[len1]) len1++;
    while (num2[len2]) len2++;
    
    // 结果最多有len1+len2位
    int *result = (int*)calloc(len1 + len2, sizeof(int));
    
    // 从右到左遍历相乘
    for (int i = len1 - 1; i >= 0; i--)
    {
        int n1 = num1[i] - '0';
        for (int j = len2 - 1; j >= 0; j--)
        {
            int n2 = num2[j] - '0';
            int product = n1 * n2;
            int sum = product + result[i + j + 1];
            
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }
    
    // 跳过前导零
    int start = 0;
    while (start < len1 + len2 && result[start] == 0)
    {
        start++;
    }
    
    // 处理结果为空的情况
    if (start == len1 + len2)
    {
        char *res = (char*)malloc(2 * sizeof(char));
        res[0] = '0';
        res[1] = '\0';
        free(result);
        return res;
    }
    
    // 构建结果字符串
    int res_len = len1 + len2 - start;
    char *res = (char*)malloc((res_len + 1) * sizeof(char));
    for (int i = 0; i < res_len; i++)
    {
        res[i] = result[start + i] + '0';
    }
    res[res_len] = '\0';
    
    free(result);
    return res;
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
    
    printf("=== 字符串相乘 ===\n");
    printf("题目：实现两个非负整数的字符串相乘\n\n");
    
    // 测试用例
    char *test_cases1[] = {
        "2",
        "123",
        "999",
        "123456789",
        "0"
    };
    char *test_cases2[] = {
        "3",
        "456",
        "999",
        "987654321",
        "0"
    };
    int test_count = sizeof(test_cases1) / sizeof(test_cases1[0]);
    
    for (int i = 0; i < test_count; i++)
    {
        char *result = multiply(test_cases1[i], test_cases2[i]);
        printf("测试用例%d: %s × %s = %s\n", 
               i + 1, test_cases1[i], test_cases2[i], result);
        free(result);
    }
    
    return 0;
}
