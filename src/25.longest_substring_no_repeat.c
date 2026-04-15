/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 25.longest_substring_no_repeat.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h, string.h
 * 功能描述:
 *   1. 最长无重复子串
 * 算法描述:
 *   - 最长无重复子串：使用滑动窗口和哈希表，记录字符位置
 * 适用场景:
 *   - 文本分析
 *   - 字符串处理
 *   - 滑动窗口技术
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
 * @brief 查找最长无重复子串
 * @param str 输入字符串
 * @param result 存储结果的数组
 * @return 最长无重复子串的长度
 */
int longest_substring_no_repeat(const char *str, char *result)
{
    int len = 0;
    while (str[len] != '\0') len++;
    
    if (len == 0)
    {
        result[0] = '\0';
        return 0;
    }
    
    int char_index[256] = {0};
    for (int i = 0; i < 256; i++)
    {
        char_index[i] = -1;
    }
    
    int max_len = 0;
    int start = 0;
    int current_start = 0;
    
    for (int i = 0; i < len; i++)
    {
        unsigned char c = str[i];
        
        if (char_index[c] >= current_start)
        {
            current_start = char_index[c] + 1;
        }
        
        char_index[c] = i;
        
        int current_len = i - current_start + 1;
        if (current_len > max_len)
        {
            max_len = current_len;
            start = current_start;
        }
    }
    
    for (int i = 0; i < max_len; i++)
    {
        result[i] = str[start + i];
    }
    result[max_len] = '\0';
    
    return max_len;
}

/**
 * @brief 最长无重复子串
 * @return void
 */
;
    
    int n = sizeof(test_cases) / sizeof(test_cases[0]);
    
    for (int i = 0; i < n; i++)
    {
        int len = longest_substring_no_repeat(test_cases[i], result);
        printf("测试用例%d: \"%s\"\n", i + 1, test_cases[i]);
        printf("  最长无重复子串: \"%s\"\n", result);
        printf("  长度: %d\n\n", len);
    }
}

/**
 * @brief 主函数
 * @return int 程序退出状态码
 */
int main()
{#ifdef _WIN32
    // 设置控制台输出为UTF-8
    SetConsoleOutputCP(CP_UTF8);
    #endif

printf("=== 最长无重复子串 ===\n");
    printf("题目：查找字符串中不含重复字符的最长子串\n\n");
    
    char result[MAX_N];
    
    const char *test_cases[] = {
        "abcabcbb",
        "bbbbb",
        "pwwkew",
        "",
        "abcdefg",
        "abcaefgh"

return 0;
}
