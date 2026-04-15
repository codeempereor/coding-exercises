/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 49.valid_ip_address.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h, string.h
 * 功能描述:
 *   1. 有效的 IP 地址
 * 算法描述:
 *   - 有效的 IP 地址：验证 IP 地址的格式和范围
 * 适用场景:
 *   - 网络编程
 *   - 数据验证
 *   - 字符串处理
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
 * @brief 验证IPv4地址
 * @param IP IP地址字符串
 * @return int 1表示有效，0表示无效
 */
int is_valid_ipv4(char *IP)
{
    int parts = 0;
    int num = 0;
    int digits = 0;
    
    for (int i = 0; IP[i]; i++)
    {
        if (IP[i] == '.')
        {
            if (digits == 0 || digits > 3 || num > 255)
            {
                return 0;
            }
            parts++;
            num = 0;
            digits = 0;
        }
        else if (IP[i] >= '0' && IP[i] <= '9')
        {
            if (digits == 0 && IP[i] == '0' && IP[i + 1] && IP[i + 1] != '.')
            {
                return 0; // 前导零
            }
            num = num * 10 + (IP[i] - '0');
            digits++;
        }
        else
        {
            return 0;
        }
    }
    
    return parts == 3 && digits > 0 && num <= 255;
}

/**
 * @brief 验证IPv6地址
 * @param IP IP地址字符串
 * @return int 1表示有效，0表示无效
 */
int is_valid_ipv6(char *IP)
{
    int parts = 0;
    int hex_digits = 0;
    int double_colon = 0;
    
    for (int i = 0; IP[i]; i++)
    {
        if (IP[i] == ':')
        {
            if (hex_digits == 0)
            {
                if (double_colon)
                {
                    return 0; // 多个双冒号
                }
                double_colon = 1;
            }
            else if (hex_digits > 4)
            {
                return 0; // 每个部分超过4位
            }
            parts++;
            hex_digits = 0;
        }
        else if ((IP[i] >= '0' && IP[i] <= '9') ||
                 (IP[i] >= 'a' && IP[i] <= 'f') ||
                 (IP[i] >= 'A' && IP[i] <= 'F'))
        {
            hex_digits++;
        }
        else
        {
            return 0;
        }
    }
    
    return parts <= 7 && hex_digits > 0 && hex_digits <= 4;
}

/**
 * @brief 判断IP地址是否有效
 * @param IP IP地址字符串
 * @return char* 结果字符串
 */
char* validIPAddress(char *IP)
{
    if (is_valid_ipv4(IP))
    {
        return "IPv4";
    }
    else if (is_valid_ipv6(IP))
    {
        return "IPv6";
    }
    else
    {
        return "Neither";
    }
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
    
    printf("=== 有效IP地址 ===\n");
    printf("题目：判断IP地址是否有效\n\n");
    
    // 测试用例
    char *test_cases[] = {
        "172.16.254.1",
        "256.256.256.256",
        "2001:0db8:85a3:0:0:8A2E:0370:7334",
        "2001:0db8:85a3::8A2E:0370:7334",
        "2001:0db8:85a3:0:0:8A2E:0370:7334:123",
        "192.168.1.1",
        "192.168.1.01",
        "2001:db8:85a3:0:0:8A2E:0370:7334",
        "2001:db8:85a3:0::8a2e:370:7334",
        "invalid"
    };
    int test_count = sizeof(test_cases) / sizeof(test_cases[0]);
    
    for (int i = 0; i < test_count; i++)
    {
        char *result = validIPAddress(test_cases[i]);
        printf("测试用例%d: %s → %s\n", i + 1, test_cases[i], result);
    }
    
    return 0;
}
