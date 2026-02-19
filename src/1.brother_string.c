/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 1.brother_string.c
 * 作    者: 三道渊
 * 创建日期: 2026-03-29
 * 最后修改: 2026-03-29
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h, string.h
 * 功能描述:
 *   1. 兄弟字符串判断
 * 算法描述:
 *   - 素数乘积法：为每个字母分配唯一素数，计算字符串中所有字符对应素数的乘积
 *   - 步骤1：为每个字母（a-z/A-Z）分配一个唯一的素数
 *   - 步骤2：计算两个字符串的素数乘积
 *   - 步骤3：比较两个乘积是否相等，若相等则为兄弟字符串
 *   - 时间复杂度O(n)，空间复杂度O(1)
 * 适用场景:
 *   - 字符串相似度判断
 *   - 字符集合比较
 *   - 字符串排序
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-03-29 三道渊: 初始化文件
 * ============================================================================ */

#include <stdio.h>
#include <string.h>

#define MAX_N 100

/**
 * @brief 26个字母对应的素数表
 */
const unsigned long long primes[] = 
{
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
    43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101
};

/**
 * @brief 计算字符串的素数乘积
 * @param str 输入字符串
 * @return 素数乘积
 */
unsigned long long calculate_product(const char *str)
{
    unsigned long long product = 1;
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        char c = str[i];
        if (c >= 'a' && c <= 'z')
        {
            product *= primes[c - 'a'];
        }
        else if (c >= 'A' && c <= 'Z')
        {
            product *= primes[c - 'A'];
        }
    }
    return product;
}

/**
 * @brief 判断两个字符串是否为兄弟字符串
 * @param str1 第一个字符串
 * @param str2 第二个字符串
 * @return 1表示是兄弟字符串，0表示不是
 */
int is_brother_string(const char *str1, const char *str2)
{
    return calculate_product(str1) == calculate_product(str2);
}

/**
 * @brief 兄弟字符串判断
 * @return void
 */
void solve()
{
    printf("=== 兄弟字符串判断 ===\n");
    printf("题目：如果两个字符串的字符一样，但是顺序不一样，被认为是兄弟字符串\n\n");
    
    // 测试用例1：兄弟字符串
    char str1[] = "bad";
    char str2[] = "adb";
    printf("测试用例1：\n");
    printf("字符串1: %s\n", str1);
    printf("字符串2: %s\n", str2);
    printf("结果: %s\n\n", is_brother_string(str1, str2) ? "是兄弟字符串" : "不是兄弟字符串");
    
    // 测试用例2：非兄弟字符串
    char str3[] = "hello";
    char str4[] = "world";
    printf("测试用例2：\n");
    printf("字符串1: %s\n", str3);
    printf("字符串2: %s\n", str4);
    printf("结果: %s\n\n", is_brother_string(str3, str4) ? "是兄弟字符串" : "不是兄弟字符串");
    
    // 测试用例3：大小写不敏感
    char str5[] = "Bad";
    char str6[] = "ADB";
    printf("测试用例3：\n");
    printf("字符串1: %s\n", str5);
    printf("字符串2: %s\n", str6);
    printf("结果: %s\n\n", is_brother_string(str5, str6) ? "是兄弟字符串" : "不是兄弟字符串");
    
    // 测试用例4：空字符串
    char str7[] = "";
    char str8[] = "";
    printf("测试用例4：\n");
    printf("字符串1: \"\"\n");
    printf("字符串2: \"\"\n");
    printf("结果: %s\n", is_brother_string(str7, str8) ? "是兄弟字符串" : "不是兄弟字符串");
}

/**
 * @brief 主函数
 * @return int 程序退出状态码
 */
int main()
{
    solve();
    return 0;
}
