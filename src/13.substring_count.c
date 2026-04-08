/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 13.substring_count.c
 * 作    者: 三道渊
 * 创建日期: 2026-03-29
 * 最后修改: 2026-04-04
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 子串出现次数：计算子串在主串中出现的次数（允许重叠）
 * 算法描述:
 *   - 滑动窗口法：遍历主串，在每个位置尝试匹配子串
 *   - 计算主串和子串长度
 *   - 从主串的每个位置开始，检查是否匹配子串
 *   - 时间复杂度O(n*m)，其中n是主串长度，m是子串长度
 * 适用场景:
 *   - 字符串匹配问题
 *   - 文本搜索场景
 *   - 模式匹配应用
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-04-04 三道渊: 补充算法描述和适用场景
 *   - 2026-03-29 三道渊: 初始化文件
 * ============================================================================ */

#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif

#define MAX_N 100

/**
 * @brief 计算子串在主串中出现的次数
 * @param str 主串
 * @param substr 子串
 * @return 出现次数
 */
int substring_count(const char *str, const char *substr)
{
    if (substr[0] == '\0')
    {
        return 0; // 空子串不计数
    }
    
    int count = 0;
    int str_len = 0;
    int substr_len = 0;
    
    // 计算字符串长度
    while (str[str_len] != '\0')
{
        str_len++;
    }
    while (substr[substr_len] != '\0')
    {
        substr_len++;
    }
    
    // 遍历主串，查找子串
    for (int i = 0; i <= str_len - substr_len; i++)
{
        int match = 1;
        for (int j = 0; j < substr_len; j++)
        {
            if (str[i + j] != substr[j])
            {
                match = 0;
                break;
            }
        }
        if (match)
        {
            count++;
        }
    }
    
    return count;
}

/**
 * @brief 子串出现次数
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

printf("=== 子串出现次数 ===\n");
    printf("题目：计算子串在主串中出现的次数\n\n");
    
    // 测试用例1：子串出现多次
    char str1[] = "abababab";
    char substr1[] = "aba";
    
    printf("测试用例1：\n");
    printf("主串：%s\n", str1);
    printf("子串：%s\n", substr1);
    int count1 = substring_count(str1, substr1);
    printf("出现次数：%d\n", count1);
    printf("预期：3（位置0, 2, 4）\n\n");
    
    // 测试用例2：子串出现一次
    char str2[] = "hello world";
    char substr2[] = "world";
    
    printf("测试用例2：\n");
    printf("主串：%s\n", str2);
    printf("子串：%s\n", substr2);
    int count2 = substring_count(str2, substr2);
    printf("出现次数：%d\n", count2);
    printf("预期：1\n\n");
    
    // 测试用例3：子串不出现
    char str3[] = "abcdef";
    char substr3[] = "xyz";
    
    printf("测试用例3：\n");
    printf("主串：%s\n", str3);
    printf("子串：%s\n", substr3);
    int count3 = substring_count(str3, substr3);
    printf("出现次数：%d\n", count3);
    printf("预期：0\n\n");
    
    // 测试用例4：子串为空
    char str4[] = "abc";
    char substr4[] = "";
    
    printf("测试用例4：\n");
    printf("主串：%s\n", str4);
    printf("子串：%s（空串）\n", substr4);
    int count4 = substring_count(str4, substr4);
    printf("出现次数：%d\n", count4);
    printf("预期：0\n\n");
    
    // 测试用例5：重叠出现
    char str5[] = "aaaa";
    char substr5[] = "aa";
    
    printf("测试用例5：\n");
    printf("主串：%s\n", str5);
    printf("子串：%s\n", substr5);
    int count5 = substring_count(str5, substr5);
    printf("出现次数：%d\n", count5);
    printf("预期：3（位置0, 1, 2，允许重叠）\n");

return 0;
}
