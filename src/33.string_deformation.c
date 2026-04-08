/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 33.string_deformation.c
 * 作    者: 三道渊
 * 创建日期: 2026-03-29
 * 最后修改: 2026-04-08
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 字符串变形
 * 算法描述:
 *   - 两次反转法：先反转整个字符串，再反转每个单词
 *   - 时间复杂度：O(n)
 *   - 空间复杂度：O(1)
 * 适用场景:
 *   - 字符串处理：单词顺序反转
 *   - 文本处理：句子结构调整
 *   - 面试常见算法题
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-04-08 三道渊: 实现字符串变形功能，添加测试用例
 *   - 2026-03-29 三道渊: 初始化文件
 * ============================================================================ */

#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif

#define MAX_N 100

/**
 * @brief 反转字符串的子区间
 * @param str 字符串
 * @param start 起始位置
 * @param end 结束位置
 */
void reverse_substring(char *str, int start, int end)
{
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
 * @brief 字符串变形：反转单词顺序
 * @param str 输入字符串
 * @return char* 变形后的字符串
 */
char* string_deformation(char *str)
{
    // 首先反转整个字符串
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    
    if (len == 0)
    {
        return str;
    }
    
    reverse_substring(str, 0, len - 1);
    
    // 然后反转每个单词
    int start = 0;
    for (int i = 0; i <= len; i++)
    {
        if (str[i] == ' ' || str[i] == '\0')
        {
            reverse_substring(str, start, i - 1);
            start = i + 1;
        }
    }
    
    return str;
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
    
    printf("=== 字符串变形 ===\n");
    printf("题目：将字符串中的单词顺序反转，保持每个单词内部顺序不变\n\n");
    
    // 测试用例
    char test_cases[][100] = {
        "Hello World",
        "I love programming",
        "C programming is fun",
        "   leading and trailing spaces   ",
        "singleword"
    };
    int test_count = sizeof(test_cases) / sizeof(test_cases[0]);
    
    for (int i = 0; i < test_count; i++)
    {
        char str[100];
        // 复制字符串，避免修改原测试用例
        int j = 0;
        while (test_cases[i][j] != '\0')
        {
            str[j] = test_cases[i][j];
            j++;
        }
        str[j] = '\0';
        
        printf("测试用例%d: \"%s\"\n", i + 1, test_cases[i]);
        string_deformation(str);
        printf("变形结果: \"%s\"\n\n", str);
    }
    
    // 用户输入
    char input[100];
    printf("请输入一个字符串: ");
    fgets(input, sizeof(input), stdin);
    
    // 去除换行符
    int len = 0;
    while (input[len] != '\0' && input[len] != '\n')
    {
        len++;
    }
    input[len] = '\0';
    
    string_deformation(input);
    printf("变形结果: \"%s\"\n", input);
    
    return 0;
}
