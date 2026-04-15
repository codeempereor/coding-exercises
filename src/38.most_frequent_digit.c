/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 38.most_frequent_digit.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 最常见数字
 * 算法描述:
 *   - 最常见数字：统计每个数字的出现次数，找出最常见的
 * 适用场景:
 *   - 数据统计
 *   - 频率分析
 *   - 模式识别
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
 * @brief 找出数字中最常见的数字
 * @param num 输入数字
 * @param result 存储结果的数组
 * @return int 最常见数字的数量
 */
int most_frequent_digit(long long num, int *result)
{
    int count[10] = {0};  // 统计每个数字出现的次数
    int max_count = 0;
    
    // 处理0的情况
    if (num == 0)
    {
        result[0] = 0;
        return 1;
    }
    
    // 统计每个数字的出现次数
    while (num > 0)
    {
        int digit = num % 10;
        count[digit]++;
        if (count[digit] > max_count)
        {
            max_count = count[digit];
        }
        num /= 10;
    }
    
    // 收集出现次数最多的数字
    int res_count = 0;
    for (int i = 0; i < 10; i++)
    {
        if (count[i] == max_count)
        {
            result[res_count++] = i;
        }
    }
    
    return res_count;
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
    
    printf("=== 最常见数字 ===\n");
    printf("题目：找出一个数字中出现次数最多的数字\n\n");
    
    // 测试用例
    long long test_cases[] = {123456789, 112233, 999999, 121212, 0, 1234567890};
    int test_count = sizeof(test_cases) / sizeof(test_cases[0]);
    
    for (int i = 0; i < test_count; i++)
    {
        int result[10];
        int count = most_frequent_digit(test_cases[i], result);
        
        printf("测试用例%d: %lld → ", i + 1, test_cases[i]);
        for (int j = 0; j < count; j++)
        {
            printf("%d", result[j]);
            if (j < count - 1)
            {
                printf("、");
            }
        }
        printf("\n");
    }
    
    // 用户输入
    long long num;
    printf("\n请输入一个数字: ");
    scanf("%lld", &num);
    
    int result[10];
    int count = most_frequent_digit(num, result);
    
    printf("结果: ");
    for (int j = 0; j < count; j++)
    {
        printf("%d", result[j]);
        if (j < count - 1)
        {
            printf("、");
        }
    }
    printf("\n");
    
    return 0;
}
