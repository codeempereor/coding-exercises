/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 19.josephus_problem.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 约瑟夫环问题
 * 算法描述:
 *   - 约瑟夫环问题：使用循环链表或数学公式求解
 * 适用场景:
 *   - 游戏开发
 *   - 循环问题
 *   - 数学建模
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
 * @brief 约瑟夫环问题（递归解法）
 * @param n 总人数
 * @param k 报数到k的人出列
 * @return 最后剩下的人的编号（1-based）
 */
int josephus_recursive(int n, int k)
{
    if (n == 1)
    {
        return 1;
    }
    return (josephus_recursive(n - 1, k) + k - 1) % n + 1;
}

/**
 * @brief 约瑟夫环问题（迭代解法）
 * @param n 总人数
 * @param k 报数到k的人出列
 * @return 最后剩下的人的编号（1-based）
 */
int josephus_iterative(int n, int k)
{
    int result = 1; // f(1, k) = 1
    
    for (int i = 2; i <= n; i++)
{
        result = (result + k - 1) % i + 1;
    }
    
    return result;
}

/**
 * @brief 约瑟夫环问题（模拟解法）
 * @param n 总人数
 * @param k 报数到k的人出列
 * @return 最后剩下的人的编号（1-based）
 */
int josephus_simulation(int n, int k)
{
    int people[MAX_N];
    for (int i = 0; i < n; i++)
    {
        people[i] = i + 1; // 1, 2, 3, ..., n
    }
    
    int alive = n;  // 存活人数
    int index = 0;  // 当前索引
    
    while (alive > 1)
{
        // 找到第k个存活的人
        int count = 0;
        while (count < k)
        {
            if (people[index] != 0)
            {
                count++;
            }
            if (count < k)
            {
                index = (index + 1) % n;
            }
        }
        
        // 标记为出列
        people[index] = 0;
        alive--;
        
        // 移动到下一个位置
        index = (index + 1) % n;
    }
    
    // 找到最后剩下的人
    for (int i = 0; i < n; i++)
{
        if (people[i] != 0)
        {
            return people[i];
        }
    }
    
    return -1; // 错误情况
}

/**
 * @brief 约瑟夫环问题
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

printf("=== 约瑟夫环问题 ===\n");
    printf("题目：n个人围成一圈，从第一个人开始报数，报到k的人出列，求最后剩下的人的编号\n\n");
    
    // 测试用例1：基本情况
    int n1 = 5, k1 = 2;
    
    printf("测试用例1：n=%d, k=%d\n", n1, k1);
    printf("递归解法结果：%d\n", josephus_recursive(n1, k1));
    printf("迭代解法结果：%d\n", josephus_iterative(n1, k1));
    printf("模拟解法结果：%d\n", josephus_simulation(n1, k1));
    printf("预期：3\n\n");
    
    // 测试用例2：k=1（每次第一个人出列）
    int n2 = 5, k2 = 1;
    
    printf("测试用例2：n=%d, k=%d（每次第一个人出列）\n", n2, k2);
    printf("递归解法结果：%d\n", josephus_recursive(n2, k2));
    printf("迭代解法结果：%d\n", josephus_iterative(n2, k2));
    printf("模拟解法结果：%d\n", josephus_simulation(n2, k2));
    printf("预期：5（最后一个人）\n\n");
    
    // 测试用例3：n=1
    int n3 = 1, k3 = 5;
    
    printf("测试用例3：n=%d, k=%d\n", n3, k3);
    printf("递归解法结果：%d\n", josephus_recursive(n3, k3));
    printf("迭代解法结果：%d\n", josephus_iterative(n3, k3));
    printf("模拟解法结果：%d\n", josephus_simulation(n3, k3));
    printf("预期：1\n\n");
    
    // 测试用例4：较大规模
    int n4 = 10, k4 = 3;
    
    printf("测试用例4：n=%d, k=%d\n", n4, k4);
    printf("递归解法结果：%d\n", josephus_recursive(n4, k4));
    printf("迭代解法结果：%d\n", josephus_iterative(n4, k4));
    printf("模拟解法结果：%d\n", josephus_simulation(n4, k4));
    printf("预期：4\n\n");
    
    // 测试用例5：k大于n
    int n5 = 4, k5 = 7;
    
    printf("测试用例5：n=%d, k=%d（k大于n）\n", n5, k5);
    printf("递归解法结果：%d\n", josephus_recursive(n5, k5));
    printf("迭代解法结果：%d\n", josephus_iterative(n5, k5));
    printf("模拟解法结果：%d\n", josephus_simulation(n5, k5));
    printf("预期：2\n");

return 0;
}
