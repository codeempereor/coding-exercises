/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 37.is_subsequence.c
 * 作    者: 三道渊
 * 创建日期: 2026-03-29
 * 最后修改: 2026-04-08
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 子序列判断
 * 算法描述:
 *   - 双指针法：使用两个指针分别遍历s和t
 *   - 当s和t的字符匹配时，s的指针前进
 *   - t的指针始终前进
 *   - 时间复杂度：O(n)
 *   - 空间复杂度：O(1)
 * 适用场景:
 *   - 字符串处理：子序列判断
 *   - 模式匹配：字符串包含关系
 *   - 面试常见算法题
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-04-08 三道渊: 实现子序列判断功能，添加测试用例
 *   - 2026-03-29 三道渊: 初始化文件
 * ============================================================================ */

#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif

#define MAX_N 100

/**
 * @brief 判断s是否是t的子序列
 * @param s 子序列字符串
 * @param t 目标字符串
 * @return int 1表示是子序列，0表示不是
 */
int is_subsequence(char *s, char *t)
{
    int i = 0;  // s的指针
    int j = 0;  // t的指针
    
    while (s[i] != '\0' && t[j] != '\0')
    {
        if (s[i] == t[j])
        {
            i++;
        }
        j++;
    }
    
    return s[i] == '\0';
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
    
    printf("=== 子序列判断 ===\n");
    printf("题目：判断字符串s是否是字符串t的子序列\n\n");
    
    // 测试用例
    char test_cases_s[][50] = {
        "abc",
        "axc",
        "",
        "ace",
        "aec"
    };
    char test_cases_t[][50] = {
        "ahbgdc",
        "ahbgdc",
        "abc",
        "abcde",
        "abcde"
    };
    int test_count = sizeof(test_cases_s) / sizeof(test_cases_s[0]);
    
    for (int i = 0; i < test_count; i++)
    {
        int result = is_subsequence(test_cases_s[i], test_cases_t[i]);
        printf("测试用例%d: s=\"%s\", t=\"%s\" → %s\n", 
               i + 1, test_cases_s[i], test_cases_t[i], 
               result ? "是" : "否");
    }
    
    // 用户输入
    char s[50], t[100];
    printf("\n请输入子序列s: ");
    scanf("%s", s);
    printf("请输入目标字符串t: ");
    scanf("%s", t);
    
    int result = is_subsequence(s, t);
    printf("结果: %s\n", result ? "是" : "否");
    
    return 0;
}
