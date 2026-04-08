/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 34.count_binary_substrings.c
 * 作    者: 三道渊
 * 创建日期: 2026-03-29
 * 最后修改: 2026-04-08
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 二进制子串计数
 * 算法描述:
 *   - 遍历字符串，记录连续相同字符的长度
 *   - 当遇到不同字符时，计算前一段和当前段的最小值，累加到结果
 *   - 时间复杂度：O(n)
 *   - 空间复杂度：O(1)
 * 适用场景:
 *   - 字符串处理：二进制字符串分析
 *   - 模式匹配：连续子串统计
 *   - 面试常见算法题
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-04-08 三道渊: 实现二进制子串计数功能，添加测试用例
 *   - 2026-03-29 三道渊: 初始化文件
 * ============================================================================ */

#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif

#define MAX_N 100

/**
 * @brief 计算二进制子串个数
 * @param s 二进制字符串
 * @return int 符合条件的子串个数
 */
int count_binary_substrings(char *s)
{
    int prev = 0;  // 前一段连续字符的长度
    int curr = 1;  // 当前段连续字符的长度
    int count = 0;  // 符合条件的子串个数
    
    int i = 1;
    while (s[i] != '\0')
    {
        if (s[i] == s[i - 1])
        {
            curr++;
        }
        else
        {
            count += (prev < curr) ? prev : curr;
            prev = curr;
            curr = 1;
        }
        i++;
    }
    
    // 处理最后一段
    count += (prev < curr) ? prev : curr;
    
    return count;
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
    
    printf("=== 二进制子串计数 ===\n");
    printf("题目：统计二进制字符串中具有相同数量0和1的连续子串个数\n\n");
    
    // 测试用例
    char test_cases[][100] = {
        "00110011",
        "10101",
        "01",
        "00110",
        "11001100"
    };
    int test_count = sizeof(test_cases) / sizeof(test_cases[0]);
    
    for (int i = 0; i < test_count; i++)
    {
        int result = count_binary_substrings(test_cases[i]);
        printf("测试用例%d: \"%s\" → %d\n", i + 1, test_cases[i], result);
    }
    
    // 用户输入
    char input[100];
    printf("\n请输入一个二进制字符串: ");
    scanf("%s", input);
    
    int result = count_binary_substrings(input);
    printf("结果: %d\n", result);
    
    return 0;
}
