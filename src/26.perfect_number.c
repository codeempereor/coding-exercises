/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 26.perfect_number.c
 * 作    者: 三道渊
 * 创建日期: 2026-03-30
 * 最后修改: 2026-03-30
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 完数
 * 算法描述:
 *   - 因数分解：完数是指一个数恰好等于它的真因数之和
 *   - 步骤1：计算一个数的所有真因数之和
 *   - 步骤2：判断该和是否等于原数
 *   - 步骤3：找出范围内的所有完数
 *   - 时间复杂度O(n√n)，空间复杂度O(1)
 * 适用场景:
 *   - 数学问题
 *   - 因数分解
 *   - 数字性质研究
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-03-30 三道渊: 初始化文件
 * ============================================================================ */

#include <stdio.h>
#include <stdbool.h>

/**
 * @brief 判断一个数是否为完数
 * @param num 待判断的数
 * @return 是否为完数
 */
bool is_perfect_number(int num)
{
    if (num <= 1)
    {
        return false;
    }
    
    int sum = 1; // 1是所有正整数的因数
    
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            sum += i;
            if (i != num / i)
            {
                sum += num / i;
            }
        }
    }
    
    return sum == num;
}

/**
 * @brief 找出范围内的所有完数
 * @param n 上限
 */
void find_perfect_numbers(int n)
{
    printf("1到%d之间的完数：", n);
    bool found = false;
    
    for (int i = 2; i <= n; i++)
    {
        if (is_perfect_number(i))
        {
            if (found)
            {
                printf(" ");
            }
            printf("%d", i);
            found = true;
        }
    }
    
    if (!found)
    {
        printf("无");
    }
    printf("\n");
}

/**
 * @brief 完数
 * @return void
 */
void solve()
{
    printf("=== 完数 ===\n");
    printf("题目：完数是指一个数恰好等于它的真因数之和\n\n");
    
    // 测试用例1：判断单个数
    int num1 = 6;
    printf("测试用例1：\n");
    printf("判断%d是否为完数：%s\n", num1, is_perfect_number(num1) ? "是" : "否");
    printf("预期结果：是（1+2+3=6）\n\n");
    
    // 测试用例2：判断另一个数
    int num2 = 28;
    printf("测试用例2：\n");
    printf("判断%d是否为完数：%s\n", num2, is_perfect_number(num2) ? "是" : "否");
    printf("预期结果：是（1+2+4+7+14=28）\n\n");
    
    // 测试用例3：找出范围内的完数
    printf("测试用例3：\n");
    find_perfect_numbers(1000);
    printf("预期结果：6 28 496\n");
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
