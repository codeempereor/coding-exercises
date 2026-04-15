/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 14.longest_palindrome.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h, string.h
 * 功能描述:
 *   1. 最长回文子串
 * 算法描述:
 *   - 最长回文子串：使用中心扩展法，遍历所有可能的回文中心
 * 适用场景:
 *   - 文本分析
 *   - 回文检测
 *   - 字符串处理
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
 * @brief 检查字符串是否为回文
 * @param str 字符串
 * @param start 起始位置
 * @param end 结束位置
 * @return 1表示是回文，0表示不是
 */
int is_palindrome(const char *str, int start, int end)
{
    while (start < end)
    {
        if (str[start] != str[end])
        {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

/**
 * @brief 查找最长回文子串
 * @param str 输入字符串
 * @param result 存储结果的数组
 * @return 最长回文子串的长度
 */
int longest_palindrome(const char *str, char *result)
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    
    if (len == 0)
    {
        result[0] = '\0';
        return 0;
    }
    
    int max_len = 1;
    int start = 0;
    
    // 暴力法：检查所有子串
    for (int i = 0; i < len; i++)
{
        for (int j = i; j < len; j++)
        {
            if (is_palindrome(str, i, j))
            {
                int current_len = j - i + 1;
                if (current_len > max_len)
                {
                    max_len = current_len;
                    start = i;
                }
            }
        }
    }
    
    // 复制结果
    for (int i = 0; i < max_len; i++)
{
        result[i] = str[start + i];
    }
    result[max_len] = '\0';
    
    return max_len;
}

/**
 * @brief 最长回文子串
 * @return void
 */


/**
 * @brief 主函数
 * @return int 程序退出状态码
 */
int main()
{#ifdef _WIN32
    // 设置控制台输出为UTF-8
    SetConsoleOutputCP(CP_UTF8);
    #endif

printf("=== 最长回文子串 ===\n");
    printf("题目：查找字符串中的最长回文子串\n\n");
    
    char result[MAX_N];
    
    // 测试用例1：有回文子串
    char str1[] = "babad";
    
    printf("测试用例1：\n");
    printf("字符串：%s\n", str1);
    int len1 = longest_palindrome(str1, result);
    printf("最长回文子串：%s\n", result);
    printf("长度：%d\n", len1);
    printf("预期：bab 或 aba，长度：3\n\n");
    
    // 测试用例2：单个字符
    char str2[] = "a";
    
    printf("测试用例2：\n");
    printf("字符串：%s\n", str2);
    int len2 = longest_palindrome(str2, result);
    printf("最长回文子串：%s\n", result);
    printf("长度：%d\n", len2);
    printf("预期：a，长度：1\n\n");
    
    // 测试用例3：无回文（除单个字符外）
    char str3[] = "abc";
    
    printf("测试用例3：\n");
    printf("字符串：%s\n", str3);
    int len3 = longest_palindrome(str3, result);
    printf("最长回文子串：%s\n", result);
    printf("长度：%d\n", len3);
    printf("预期：a 或 b 或 c，长度：1\n\n");
    
    // 测试用例4：整个字符串是回文
    char str4[] = "racecar";
    
    printf("测试用例4：\n");
    printf("字符串：%s\n", str4);
    int len4 = longest_palindrome(str4, result);
    printf("最长回文子串：%s\n", result);
    printf("长度：%d\n", len4);
    printf("预期：racecar，长度：7\n\n");
    
    // 测试用例5：偶数长度回文
    char str5[] = "abba";
    
    printf("测试用例5：\n");
    printf("字符串：%s\n", str5);
    int len5 = longest_palindrome(str5, result);
    printf("最长回文子串：%s\n", result);
    printf("长度：%d\n", len5);
    printf("预期：abba，长度：4\n");

return 0;
}
