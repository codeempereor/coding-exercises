/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 28.jump_game.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 跳跃游戏
 * 算法描述:
 *   - 跳跃游戏：贪心算法，记录最远可达位置
 * 适用场景:
 *   - 游戏开发
 *   - 贪心算法
 *   - 路径规划
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
 * @brief 判断是否能够从起点跳到终点
 * @param nums 跳跃数组
 * @param n 数组长度
 * @return 1表示可以跳到，0表示不能
 */
int can_jump(int nums[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    
    int max_reach = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (i > max_reach)
        {
            return 0;
        }
        
        max_reach = (i + nums[i] > max_reach) ? i + nums[i] : max_reach;
        
        if (max_reach >= n - 1)
        {
            return 1;
        }
    }
    
    return max_reach >= n - 1;
}

/**
 * @brief 跳跃游戏
 * @return void
 */
,
        {3, 2, 1, 0, 4},
        {0},
        {1},
        {2, 0, 0},
        {1, 2, 3}
    };
    
    int test_sizes[] = {5, 5, 1, 1, 3, 3};
    int n = sizeof(test_sizes) / sizeof(test_sizes[0]);
    
    for (int i = 0; i < n; i++)
    {
        int can_reach = can_jump(test_cases[i], test_sizes[i]);
        printf("测试用例%d: [", i + 1);
        for (int j = 0; j < test_sizes[i]; j++)
        {
            printf("%d", test_cases[i][j]);
            if (j < test_sizes[i] - 1)
            {
                printf(", ");
            }
        }
        printf("]\n");
        printf("  能否跳到终点: %s\n\n", can_reach ? "是" : "否");
    }
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

printf("=== 跳跃游戏 ===\n");
    printf("题目：判断是否能够从数组起点跳到终点\n\n");
    
    int test_cases[][10] = {
        {2, 3, 1, 1, 4

return 0;
}
