/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 17.string_insert.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h, string.h
 * 功能描述:
 *   1. 字符串插入
 * 算法描述:
 *   - 字符串插入：通过字符串操作，在指定位置插入子串
 * 适用场景:
 *   - 文本编辑
 *   - 字符串处理
 *   - 数据格式化
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-04-15 三道渊: 初始化文件
 * ============================================================================ */
#include <stdio.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif

#define MAX_N 100

/**
 * @brief 在字符串指定位置插入子串
 * @param str 原字符串
 * @param insert_str 要插入的子串
 * @param pos 插入位置（0-based）
 * @param result 存储结果的数组
 * @return 结果字符串长度
 */
int string_insert(const char *str, const char *insert_str, int pos, char *result)
{
    int str_len = 0;
    int insert_len = 0;
    
    // 计算字符串长度
    while (str[str_len] != '\0')
{
        str_len++;
    }
    while (insert_str[insert_len] != '\0')
    {
        insert_len++;
    }
    
    // 检查插入位置是否有效
    if (pos < 0 || pos > str_len)
{
        // 无效位置，直接复制原字符串
        for (int i = 0; i <= str_len; i++)
{
            result[i] = str[i];
        }
        return str_len;
    }
    
    // 复制原字符串的前pos个字符
    for (int i = 0; i < pos; i++)
{
        result[i] = str[i];
    }
    
    // 插入子串
    for (int i = 0; i < insert_len; i++)
{
        result[pos + i] = insert_str[i];
    }
    
    // 复制原字符串的剩余部分
    for (int i = pos; i <= str_len; i++)
{
        result[pos + insert_len + i - pos] = str[i];
    }
    
    return str_len + insert_len;
}

/**
 * @brief 字符串插入
 * @return void
 */


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

    printf("=== 字符串插入 ===\n");
    printf("题目：在字符串指定位置插入子串\n\n");
    
    char result[MAX_N];
    
    // 测试用例1：在中间插入
    char str1[] = "Hello World";
    char insert1[] = "Beautiful ";
    int pos1 = 6;
    
    printf("测试用例1：在中间插入\n");
    printf("原字符串：%s\n", str1);
    printf("插入子串：%s\n", insert1);
    printf("插入位置：%d\n", pos1);
    string_insert(str1, insert1, pos1, result);
    printf("结果：%s\n", result);
    printf("预期：Hello Beautiful World\n\n");
    
    // 测试用例2：在开头插入
    char str2[] = "World";
    char insert2[] = "Hello ";
    int pos2 = 0;
    
    printf("测试用例2：在开头插入\n");
    printf("原字符串：%s\n", str2);
    printf("插入子串：%s\n", insert2);
    printf("插入位置：%d\n", pos2);
    string_insert(str2, insert2, pos2, result);
    printf("结果：%s\n", result);
    printf("预期：Hello World\n\n");
    
    // 测试用例3：在末尾插入
    char str3[] = "Hello";
    char insert3[] = " World";
    int pos3 = 5;
    
    printf("测试用例3：在末尾插入\n");
    printf("原字符串：%s\n", str3);
    printf("插入子串：%s\n", insert3);
    printf("插入位置：%d\n", pos3);
    string_insert(str3, insert3, pos3, result);
    printf("结果：%s\n", result);
    printf("预期：Hello World\n\n");
    
    // 测试用例4：插入空串
    char str4[] = "Hello";
    char insert4[] = "";
    int pos4 = 2;
    
    printf("测试用例4：插入空串\n");
    printf("原字符串：%s\n", str4);
    printf("插入子串：%s（空串）\n", insert4);
    printf("插入位置：%d\n", pos4);
    string_insert(str4, insert4, pos4, result);
    printf("结果：%s\n", result);
    printf("预期：Hello\n\n");
    
    // 测试用例5：无效位置
    char str5[] = "Hello";
    char insert5[] = " World";
    int pos5 = 10;  // 超出范围
    
    printf("测试用例5：无效位置\n");
    printf("原字符串：%s\n", str5);
    printf("插入子串：%s\n", insert5);
    printf("插入位置：%d（超出范围）\n", pos5);
    string_insert(str5, insert5, pos5, result);
    printf("结果：%s\n", result);
    printf("预期：Hello（保持不变）\n");

    return 0;
}
