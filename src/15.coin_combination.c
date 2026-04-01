/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 15.coin_combination.c
 * 作    者: 三道渊
 * 创建日期: 2026-03-30
 * 最后修改: 2026-03-30
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 硬币组合数
 * 算法描述:
 *   - 动态规划：使用一维数组dp，其中dp[i]表示凑成金额i的组合数
 *   - 步骤1：初始化dp[0] = 1（表示凑成金额0的方法数为1）
 *   - 步骤2：遍历每种硬币，对于每个金额i从硬币面值到目标金额，更新dp[i] += dp[i - coin]
 *   - 时间复杂度O(amount * n)，空间复杂度O(amount)
 * 适用场景:
 *   - 硬币找零问题
 *   - 组合优化问题
 *   - 背包问题
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-03-30 三道渊: 初始化文件
 * ============================================================================ */

#include <stdio.h>

/**
 * @brief 计算凑成目标金额的硬币组合数
 * @param coins 硬币面值数组
 * @param n 硬币种类数
 * @param amount 目标金额
 * @return 组合数
 */
int coin_combination(int coins[], int n, int amount)
{
    int dp[amount + 1];
    for (int i = 0; i <= amount; i++)
    {
        dp[i] = 0;
    }
    dp[0] = 1; // 凑成金额0的方法数为1
    
    for (int i = 0; i < n; i++)
    {
        int coin = coins[i];
        for (int j = coin; j <= amount; j++)
        {
            dp[j] += dp[j - coin];
        }
    }
    
    return dp[amount];
}

/**
 * @brief 打印数组
 * @param arr 输入数组
 * @param len 数组长度
 */
void print_array(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * @brief 硬币组合数
 * @return void
 */
void solve()
{
    printf("=== 硬币组合数 ===\n");
    printf("题目：计算凑成目标金额的硬币组合数\n\n");
    
    // 测试用例1：基本情况
    int coins1[] = {1, 2, 5};
    int n1 = sizeof(coins1) / sizeof(coins1[0]);
    int amount1 = 5;
    
    printf("测试用例1：\n");
    printf("硬币面值：");
    print_array(coins1, n1);
    printf("目标金额：%d\n", amount1);
    int result1 = coin_combination(coins1, n1, amount1);
    printf("组合数：%d\n", result1);
    printf("预期结果：4\n\n");
    
    // 测试用例2：无组合
    int coins2[] = {2};
    int n2 = sizeof(coins2) / sizeof(coins2[0]);
    int amount2 = 3;
    
    printf("测试用例2：\n");
    printf("硬币面值：");
    print_array(coins2, n2);
    printf("目标金额：%d\n", amount2);
    int result2 = coin_combination(coins2, n2, amount2);
    printf("组合数：%d\n", result2);
    printf("预期结果：0\n\n");
    
    // 测试用例3：目标金额为0
    int coins3[] = {1, 2, 5};
    int n3 = sizeof(coins3) / sizeof(coins3[0]);
    int amount3 = 0;
    
    printf("测试用例3：\n");
    printf("硬币面值：");
    print_array(coins3, n3);
    printf("目标金额：%d\n", amount3);
    int result3 = coin_combination(coins3, n3, amount3);
    printf("组合数：%d\n", result3);
    printf("预期结果：1\n");
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
