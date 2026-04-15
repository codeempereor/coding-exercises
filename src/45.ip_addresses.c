/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 45.ip_addresses.c
 * 作    者: 三道渊
 * 创建日期: 2026-03-29
 * 最后修改: 2026-03-29
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. IP地址生成
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-03-29 三道渊: 初始化文件
 * ============================================================================ */

#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif

#define MAX_N 100

/**
 * @brief 验证IP地址的一段是否有效
 * @param s 字符串
 * @param start 起始位置
 * @param end 结束位置
 * @return int 1表示有效，0表示无效
 */
int is_valid(char *s, int start, int end)
{
    if (end - start + 1 > 3)
    {
        return 0;
    }
    if (s[start] == '0' && end > start)
    {
        return 0;
    }
    int num = 0;
    for (int i = start; i <= end; i++)
    {
        num = num * 10 + (s[i] - '0');
    }
    return num >= 0 && num <= 255;
}

/**
 * @brief 回溯生成IP地址
 * @param s 输入字符串
 * @param start 起始位置
 * @param dots 已添加的点数量
 * @param current 当前生成的IP地址
 * @param result 结果数组
 * @param result_size 结果数量
 */
void backtrack(char *s, int start, int dots, char *current, char **result, int *result_size)
{
    int len = 0;
    while (s[len]) len++;
    
    // 找到4段且遍历完整个字符串
    if (dots == 3)
    {
        if (is_valid(s, start, len - 1))
        {
            int curr_len = 0;
            while (current[curr_len]) curr_len++;
            
            // 添加最后一段
            for (int i = start; i < len; i++)
            {
                current[curr_len++] = s[i];
            }
            current[curr_len] = '\0';
            
            // 复制到结果
            result[*result_size] = (char*)malloc((curr_len + 1) * sizeof(char));
            strcpy(result[*result_size], current);
            (*result_size)++;
        }
        return;
    }
    
    // 尝试每一种可能的分割方式
    for (int i = start; i < len && i < start + 3; i++)
    {
        if (is_valid(s, start, i))
        {
            int curr_len = 0;
            while (current[curr_len]) curr_len++;
            
            // 添加当前段
            for (int j = start; j <= i; j++)
            {
                current[curr_len++] = s[j];
            }
            current[curr_len++] = '.';
            current[curr_len] = '\0';
            
            backtrack(s, i + 1, dots + 1, current, result, result_size);
        }
    }
}

/**
 * @brief 生成所有可能的有效IP地址
 * @param s 输入字符串
 * @return char** 结果数组
 */
char** restore_ip_addresses(char *s, int *return_size)
{
    char **result = (char**)malloc(100 * sizeof(char*));
    *return_size = 0;
    
    if (s == NULL)
    {
        return result;
    }
    
    int len = 0;
    while (s[len]) len++;
    
    if (len < 4 || len > 12)
    {
        return result;
    }
    
    char current[20];
    backtrack(s, 0, 0, current, result, return_size);
    
    return result;
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
    
    printf("=== IP地址生成 ===\n");
    printf("题目：将数字字符串转换为所有可能的有效IP地址\n\n");
    
    // 测试用例
    char *test_cases[] = {
        "25525511135",
        "0000",
        "101023",
        "010010",
        "255255255255"
    };
    int test_count = sizeof(test_cases) / sizeof(test_cases[0]);
    
    for (int i = 0; i < test_count; i++)
    {
        int return_size = 0;
        char **result = restore_ip_addresses(test_cases[i], &return_size);
        
        printf("测试用例%d: %s\n", i + 1, test_cases[i]);
        printf("结果: ");
        if (return_size == 0)
        {
            printf("无有效IP地址\n");
        }
        else
        {
            for (int j = 0; j < return_size; j++)
            {
                printf("%s", result[j]);
                if (j < return_size - 1)
                {
                    printf(", ");
                }
                free(result[j]);
            }
            printf("\n");
        }
        free(result);
    }
    
    return 0;
}
