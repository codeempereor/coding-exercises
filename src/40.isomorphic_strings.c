/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 40.isomorphic_strings.c
 * 作    者: 三道渊
 * 创建日期: 2026-03-29
 * 最后修改: 2026-04-08
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 同构字符串
 * 算法描述:
 *   - 使用两个哈希表记录字符映射关系
 *   - 检查双向映射是否一致
 *   - 时间复杂度：O(n)
 *   - 空间复杂度：O(1)
 * 适用场景:
 *   - 字符串处理：同构判断
 *   - 模式匹配：字符映射验证
 *   - 面试常见算法题
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-04-08 三道渊: 实现同构字符串功能，添加测试用例
 *   - 2026-03-29 三道渊: 初始化文件
 * ============================================================================ */

#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif

#define MAX_N 100

/**
 * @brief 判断两个字符串是否同构
 * @param s 第一个字符串
 * @param t 第二个字符串
 * @return int 1表示同构，0表示不同构
 */
int is_isomorphic(char *s, char *t)
{
    int map_s[256] = {0};  // 记录s中字符到t的映射
    int map_t[256] = {0};  // 记录t中字符到s的映射
    
    int i = 0;
    while (s[i] != '\0' && t[i] != '\0')
    {
        char c1 = s[i];
        char c2 = t[i];
        
        // 如果映射不存在，建立映射
        if (map_s[(unsigned char)c1] == 0 && map_t[(unsigned char)c2] == 0)
        {
            map_s[(unsigned char)c1] = c2;
            map_t[(unsigned char)c2] = c1;
        }
        // 如果映射存在，检查是否一致
        else if (map_s[(unsigned char)c1] != c2 || map_t[(unsigned char)c2] != c1)
        {
            return 0;
        }
        
        i++;
    }
    
    // 检查两个字符串长度是否相同
    return s[i] == '\0' && t[i] == '\0';
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
    
    printf("=== 同构字符串 ===\n");
    printf("题目：判断两个字符串是否同构\n\n");
    
    // 测试用例
    char test_cases_s[][50] = {
        "egg",
        "foo",
        "paper",
        "bar",
        "add"
    };
    char test_cases_t[][50] = {
        "add",
        "bar",
        "title",
        "foo",
        "egg"
    };
    int test_count = sizeof(test_cases_s) / sizeof(test_cases_s[0]);
    
    for (int i = 0; i < test_count; i++)
    {
        int result = is_isomorphic(test_cases_s[i], test_cases_t[i]);
        printf("测试用例%d: s=\"%s\", t=\"%s\" → %s\n", 
               i + 1, test_cases_s[i], test_cases_t[i], 
               result ? "是" : "否");
    }
    
    // 用户输入
    char s[50], t[50];
    printf("\n请输入字符串s: ");
    scanf("%s", s);
    printf("请输入字符串t: ");
    scanf("%s", t);
    
    int result = is_isomorphic(s, t);
    printf("结果: %s\n", result ? "是" : "否");
    
    return 0;
}
