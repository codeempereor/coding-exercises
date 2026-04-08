/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 1.brother_string.c
 * 作    者: 三道渊
 * 创建日期: 2026-03-29
 * 最后修改: 2026-03-29
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 兄弟字符串
 * 算法描述:
 *   - 素数乘积法：为每个字母分配唯一素数，计算字符串中字符对应素数的乘积
 *   - 若两个字符串的素数乘积相等，则它们是兄弟字符串
 * 适用场景:
 *   - 字符串相似度判断
 *   - 字符集合比较
 *   - 快速去重和分组
 *   - 单词变位词检测
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-03-29 三道渊: 添加了Windows API调用，设置控制台编码为UTF-8
 *   - 2026-03-29 三道渊: 初始化文件
 * ============================================================================ */

#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

#define MAX_N 100

/**
 * @brief 素数数组，用于映射26个字母
 */
const unsigned long long primes[] = 
{
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
    43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101
};

/**
 * @brief 计算字符串的素数乘积
 * @param str 输入字符串
 * @return 素数乘积值
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
        } else if (c >= 'A' && c <= 'Z')
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
 * @brief 兄弟字符串
 * @return void
 */
 else 
    {
        printf("结果: 不是兄弟字符串\n");
    }
    
    printf("\n测试用例2: %s 和 %s\n", str3, str4);
    if (is_brother_string(str3, str4)) 
    {
        printf("结果: 是兄弟字符串\n");
    } else 
    {
        printf("结果: 不是兄弟字符串\n");
    }
    
    // 手动输入测试
    char input1[MAX_N], input2[MAX_N];
    printf("\n请输入第一个字符串: ");
    scanf("%s", input1);
    printf("请输入第二个字符串: ");
    scanf("%s", input2);
    
    if (is_brother_string(input1, input2)) 
    {
        printf("结果: 是兄弟字符串\n");
    } else 
    {
        printf("结果: 不是兄弟字符串\n");
    }
}

/**
 * @brief 主函数
 * @return int 程序退出状态码
 */
int main()
{#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif

printf("=== 兄弟字符串 ===\n");
    
    // 测试用例
    char str1[] = "bad";
    char str2[] = "adb";
    char str3[] = "abc";
    char str4[] = "def";
    
    printf("测试用例1: %s 和 %s\n", str1, str2);
    if (is_brother_string(str1, str2)) 
    {
        printf("结果: 是兄弟字符串\n");

return 0;
}
