/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 10.minimize_sum_difference.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h, stdlib.h
 * 功能描述:
 *   1. 最小化和差
 * 算法描述:
 *   - 最小化和差：通过排序和双指针法，寻找最优解
 * 适用场景:
 *   - 优化问题
 *   - 资源分配
 *   - 平衡问题
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-04-15 三道渊: 初始化文件
 * ============================================================================ */
#include <stdio.h>  // 输入输出函数
#include <stdlib.h> // 动态内存分配函数
#ifdef _WIN32
#include <windows.h>
#endif
#define MAX_N 100

/**
 * @brief 计算数组和
 * @param arr 数组
 * @param n 数组长度
 * @return 数组和
 */
int calculate_sum(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

/**
 * @brief 最小化两个序列的和差
 * @param a 序列a
 * @param b 序列b
 * @param n 序列长度
 * @return 最小和差
 */
int minimize_sum_difference(int a[], int b[], int n)
{
    // 计算总和
    int sumA = calculate_sum(a, n);
    int sumB = calculate_sum(b, n);
    int total_sum = sumA + sumB;
    int target = total_sum / 2;
    
    // 动态规划：dp[i]表示是否可以得到和为i
    int max_possible = sumA + sumB;
    int dp[max_possible + 1];
    for (int i = 0; i <= max_possible; i++)
    {
        dp[i] = 0;
    }
    dp[sumA] = 1; // 初始状态：a的和为sumA，b的和为sumB
    
    // 遍历所有可能的交换
    for (int i = 0; i < n; i++)
{
        // 计算交换a[i]和b[i]后的和变化
        int delta = b[i] - a[i];
        
        // 正向或反向遍历，避免重复计算
        if (delta > 0)
{
            // 正向遍历
            for (int j = max_possible; j >= delta; j--)
{
                if (dp[j - delta])
                {
                    dp[j] = 1;
                }
            }
        }
        else
        {
            // 反向遍历
            for (int j = 0; j <= max_possible + delta; j++)
{
                if (dp[j - delta])
                {
                    dp[j] = 1;
                }
            }
        }
    }
    
    // 找到最接近target的可能和
    int best_sum = 0;
    int min_diff = total_sum;
    
    for (int i = 0; i <= max_possible; i++)
    {
        if (dp[i])
        {
            int diff = abs(total_sum - 2 * i);
            if (diff < min_diff)
            {
                min_diff = diff;
                best_sum = i;
            }
        }
    }
    
    return min_diff;
}

/**
 * @brief 打印数组
 * @param arr 数组
 * @param n 数组长度
 */
void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * @brief 最小化和差
 * @return void
 */
;
    int b1[] = {6, 7, 8, 9, 10};
    int n1 = sizeof(a1) / sizeof(a1[0]);
    
    printf("测试用例1：");
    printf("a = ");
    print_array(a1, n1);
    printf("b = ");
    print_array(b1, n1);
    
    int min_diff1 = minimize_sum_difference(a1, b1, n1);
    
    printf("最小和差：%d\n", min_diff1);
    printf("预期：接近0\n\n");
    
    // 测试用例2：相同元素
    int a2[] = {1, 1, 1, 1};
    int b2[] = {1, 1, 1, 1};
    int n2 = sizeof(a2) / sizeof(a2[0]);
    
    printf("测试用例2：");
    printf("a = ");
    print_array(a2, n2);
    printf("b = ");
    print_array(b2, n2);
    
    int min_diff2 = minimize_sum_difference(a2, b2, n2);
    
    printf("最小和差：%d\n", min_diff2);
    printf("预期：0\n\n");
    
    // 测试用例3：不同长度
    int a3[] = {2, 3, 5};
    int b3[] = {1, 4, 6};
    int n3 = sizeof(a3) / sizeof(a3[0]);
    
    printf("测试用例3：");
    printf("a = ");
    print_array(a3, n3);
    printf("b = ");
    print_array(b3, n3);
    
    int min_diff3 = minimize_sum_difference(a3, b3, n3);
    
    printf("最小和差：%d\n", min_diff3);
    printf("预期：0\n");
}

/**
 * @brief 主函数
 * @return int 程序退出状态码
 */
int main()
{#ifdef _WIN32
    // 设置控制台输出为UTF-8
    SetConsoleOutputCP(CP_UTF8);
    #endif

printf("=== 最小化和差 ===\n");
    printf("题目：通过交换a,b中的元素，使[序列a元素的和]与[序列b元素的和]之间的差最小\n\n");
    
    // 测试用例1：基本情况
    int a1[] = {1, 2, 3, 4, 5

return 0;
}
