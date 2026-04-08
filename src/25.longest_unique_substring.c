/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 25.longest_unique_substring.c
 * 作    者: 三道渊
 * 创建日期: 2026-03-30
 * 最后修改: 2026-03-30
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h, string.h
 * 功能描述:
 *   1. 最长无重复子串
 * 算法描述:
 *   - 滑动窗口法：使用滑动窗口来寻找最长无重复子串
 *   - 步骤1：初始化左右指针，左指针指向窗口开始，右指针向右移动
 *   - 步骤2：使用哈希表记录字符最后一次出现的位置
 *   - 步骤3：如果右指针指向的字符已经在窗口中，移动左指针到重复字符的下一个位置
 *   - 步骤4：更新最长子串的长度和起始位置
 *   - 时间复杂度O(n)，空间复杂度O(min(m, n))，其中m是字符集大小
 * 适用场景:
 *   - 字符串处理
 *   - 滑动窗口技巧
 *   - 子串查找
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-03-30 三道渊: 初始化文件
 * ============================================================================ */

#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif
#include <string.h>

#define MAX_LEN 256

/**
 * @brief 寻找最长无重复子串
 * @param s 输入字符串
 * @param result 存储结果的字符串
 * @return 最长无重复子串的长度
 */
int longest_unique_substring(const char *s, char *result)
{
    int n = strlen(s);
    if (n == 0)
    {
        result[0] = '\0';
        return 0;
    }
    
    int last_pos[MAX_LEN];
    for (int i = 0; i < MAX_LEN; i++)
    {
        last_pos[i] = -1;
    }
    
    int left = 0;
    int max_len = 0;
    int start = 0;
    
    for (int right = 0; right < n; right++)
    {
        char c = s[right];
        // 如果字符已经在窗口中，移动左指针
        if (last_pos[c] >= left)
{
            left = last_pos[c] + 1;
        }
        // 更新字符位置
        last_pos[c] = right;
        // 更新最长子串
        int current_len = right - left + 1;
        if (current_len > max_len)
        {
            max_len = current_len;
            start = left;
        }
    }
    
    strncpy(result, s + start, max_len);
    result[max_len] = '\0';
    return max_len;
}

/**
 * @brief 最长无重复子串
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

printf("=== 最长无重复子串 ===\n");
    printf("题目：给定一个字符串，请你找出其中不含有重复字符的最长子串的长度\n\n");
    
    // 测试用例1：基本情况
    char s1[] = "abcabcbb";
    char result1[100];
    
    printf("测试用例1：\n");
    printf("输入字符串：%s\n", s1);
    int len1 = longest_unique_substring(s1, result1);
    printf("最长无重复子串：%s\n", result1);
    printf("长度：%d\n", len1);
    printf("预期结果：abc，长度3\n\n");
    
    // 测试用例2：全相同字符
    char s2[] = "bbbbb";
    char result2[100];
    
    printf("测试用例2：\n");
    printf("输入字符串：%s\n", s2);
    int len2 = longest_unique_substring(s2, result2);
    printf("最长无重复子串：%s\n", result2);
    printf("长度：%d\n", len2);
    printf("预期结果：b，长度1\n\n");
    
    // 测试用例3：无重复字符
    char s3[] = "pwwkew";
    char result3[100];
    
    printf("测试用例3：\n");
    printf("输入字符串：%s\n", s3);
    int len3 = longest_unique_substring(s3, result3);
    printf("最长无重复子串：%s\n", result3);
    printf("长度：%d\n", len3);
    printf("预期结果：wke，长度3\n");

return 0;
}
