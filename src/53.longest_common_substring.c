/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 53.longest_common_substring.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h, string.h
 * 功能描述:
 *   1. 最长公共子串
 * 算法描述:
 *   - 最长公共子串：使用动态规划，记录最长公共子串的长度
 * 适用场景:
 *   - 字符串处理
 *   - 动态规划
 *   - 模式匹配
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
 * @brief 计算字符串长度
 * @param s 字符串
 * @return int 字符串长度
 */
int my_strlen(const char *s)
{
    int len = 0;
    while (s[len]) len++;
    return len;
}

/**
 * @brief 最长公共子串
 * @param str1 第一个字符串
 * @param str2 第二个字符串
 * @return char* 最长公共子串
 */
char* longest_common_substring(char *str1, char *str2)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    
    if (len1 == 0 || len2 == 0)
    {
        return "";
    }
    
    // 动态规划表
    int dp[1001][1001] = {0};
    int max_length = 0;
    int end_pos = 0;
    
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > max_length)
                {
                    max_length = dp[i][j];
                    end_pos = i;
                }
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    
    // 提取最长公共子串
    static char result[1001];
    for (int i = 0; i < max_length; i++)
    {
        result[i] = str1[end_pos - max_length + i];
    }
    result[max_length] = '\0';
    
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
    
    printf("=== 最长公共子串 ===\n");
    printf("题目：找出两个字符串的最长公共子串\n\n");
    
    // 测试用例
    char *test_cases1[] = {
        "1AB2345CD",
        "abcdefg",
        "hello world",
        "abc",
        "12345"
    };
    char *test_cases2[] = {
        "12345EF",
        "xyzabcd",
        "world hello",
        "def",
        "54321"
    };
    int test_count = sizeof(test_cases1) / sizeof(test_cases1[0]);
    
    for (int i = 0; i < test_count; i++)
    {
        char *result = longest_common_substring(test_cases1[i], test_cases2[i]);
        printf("测试用例%d: \"%s\" 和 \"%s\" → \"%s\"\n", 
               i + 1, test_cases1[i], test_cases2[i], result);
    }
    
    return 0;
}
