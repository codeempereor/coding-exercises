/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 23.count_digit_one.c
 * 作    者: 三道渊
 * 创建日期: 2026-03-30
 * 最后修改: 2026-03-30
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 数字1出现次数
 * 算法描述:
 *   - 数学规律：统计从1到n的所有整数中，数字1出现的次数
 *   - 对于每一位，分别计算该位上1出现的次数
 *   - 时间复杂度O(log n)，空间复杂度O(1)
 * 适用场景:
 *   - 数学问题
 *   - 数字统计
 *   - 规律发现
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-03-30 三道渊: 初始化文件
 * ============================================================================ */

#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif

/**
 * @brief 统计从1到n的所有整数中，数字1出现的次数
 * @param n 上限
 * @return 数字1出现的次数
 */
int count_digit_one(int n)
{
    int count = 0;
    long long factor = 1;
    
    while (factor <= n)
    {
        int lower = n % factor;
        int current = (n / factor) % 10;
        int higher = n / (factor * 10);
        
        if (current == 0)
        {
            count += higher * factor;
        }
        else if (current == 1)
{
            count += higher * factor + lower + 1;
        }
        else
        {
            count += (higher + 1) * factor;
        }
        
        factor *= 10;
    }
    
    return count;
}

/**
 * @brief 数字1出现次数
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

printf("=== 数字1出现次数 ===\n");
    printf("题目：统计从1到n的所有整数中，数字1出现的次数\n\n");
    
    // 测试用例1：基本情况
    int n1 = 13;
    
    printf("测试用例1：\n");
    printf("输入：%d\n", n1);
    int result1 = count_digit_one(n1);
    printf("数字1出现次数:%d\n", result1);
    printf("预期结果：6(1, 10, 11, 12, 13中1出现的次数)\n\n");
    
    // 测试用例2：较大值
    int n2 = 100;
    
    printf("测试用例2：\n");
    printf("输入：%d\n", n2);
    int result2 = count_digit_one(n2);
    printf("数字1出现次数:%d\n", result2);
    printf("预期结果：21(1, 10, 11, 12, 13, 21中1出现的次数)\n\n");

return 0;
}
