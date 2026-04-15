/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 58.letter_combinations.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h, string.h
 * 功能描述:
 *   1. 电话号码的字母组合
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-04-15 三道渊: 初始化文件
 * ============================================================================ */

#include <stdio.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif

#define MAX_COMBINATIONS 1000
#define MAX_LENGTH 10

/**
 * @brief 数字到字母的映射
 */
const char *phone_map[] = {
    "",     // 0
    "",     // 1
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz"  // 9
};

/**
 * @brief 回溯生成字母组合
 * @param digits 数字字符串
 * @param index 当前处理的位置
 * @param current 当前组合
 * @param result 结果数组
 * @param result_size 结果大小
 */
void backtrack(const char *digits, int index, char *current, char **result, int *result_size)
{
    if (digits[index] == '\0')
    {
        current[index] = '\0';
        strcpy(result[*result_size], current);
        (*result_size)++;
        return;
    }
    
    int digit = digits[index] - '0';
    const char *letters = phone_map[digit];
    
    for (int i = 0; letters[i]; i++)
    {
        current[index] = letters[i];
        backtrack(digits, index + 1, current, result, result_size);
    }
}

/**
 * @brief 生成电话号码的字母组合
 * @param digits 数字字符串
 * @return char** 字母组合数组
 */
char** letter_combinations(char *digits, int *return_size)
{
    int len = 0;
    while (digits[len]) len++;
    
    if (len == 0)
    {
        *return_size = 0;
        return NULL;
    }
    
    // 计算可能的组合数
    int combinations = 1;
    for (int i = 0; i < len; i++)
    {
        int digit = digits[i] - '0';
        int letters_len = 0;
        while (phone_map[digit][letters_len]) letters_len++;
        combinations *= letters_len;
    }
    
    // 分配结果数组
    char **result = (char**)malloc(combinations * sizeof(char*));
    for (int i = 0; i < combinations; i++)
    {
        result[i] = (char*)malloc((len + 1) * sizeof(char));
    }
    
    char current[len + 1];
    *return_size = 0;
    
    backtrack(digits, 0, current, result, return_size);
    
    return result;
}

/**
 * @brief 打印字符串数组
 * @param arr 字符串数组
 * @param size 数组大小
 */
void print_string_array(char **arr, int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("\"%s\"", arr[i]);
        if (i < size - 1)
        {
            printf(", ");
        }
    }
    printf("]");
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
    
    printf("=== 电话号码的字母组合 ===\n");
    printf("题目：给定数字组合，返回对应的全部字母组合\n\n");
    
    // 测试用例
    char *test_cases[] = {
        "55",
        "3",
        "23",
        "",
        "78"
    };
    int test_count = sizeof(test_cases) / sizeof(test_cases[0]);
    
    for (int i = 0; i < test_count; i++)
    {
        int return_size;
        char **result = letter_combinations(test_cases[i], &return_size);
        
        printf("测试用例%d: \"%s\" → ", i + 1, test_cases[i]);
        print_string_array(result, return_size);
        printf("\n");
        
        // 释放内存
        if (result)
        {
            for (int j = 0; j < return_size; j++)
            {
                free(result[j]);
            }
            free(result);
        }
    }
    
    return 0;
}