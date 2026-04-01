/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 3.rotate_matrix.c
 * 作    者: 三道渊
 * 创建日期: 2026-03-29
 * 最后修改: 2026-03-29
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 矩阵旋转
 * 算法描述:
 *   - 按层旋转法：从外到内逐层处理矩阵
 *   - 每层元素按顺时针方向交换，使用临时变量保存中间值
 *   - 对于N*N矩阵，需要处理N/2层
 * 适用场景:
 *   - 图像处理中的旋转操作
 *   - 游戏开发中的视角变换
 *   - 矩阵运算中的变换操作
 *   - 数据可视化中的坐标转换
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-03-29 三道渊: 初始化文件
 * ============================================================================ */

#include <stdio.h>

#define MAX_N 100

/**
 * @brief 打印矩阵
 * @param matrix 输入矩阵
 * @param n 矩阵大小
 */
void print_matrix(int matrix[][MAX_N], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief 旋转矩阵
 * @param matrix 输入矩阵
 * @param n 矩阵大小
 */
void rotate_matrix(int matrix[][MAX_N], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = i; j < n - i - 1; j++)
        {
            // 保存左上角元素
            int temp = matrix[i][j];
            
            // 左上角 = 左下角
            matrix[i][j] = matrix[n - 1 - j][i];
            
            // 左下角 = 右下角
            matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
            
            // 右下角 = 右上角
            matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
            
            // 右上角 = 左上角（临时变量）
            matrix[j][n - 1 - i] = temp;
        }
    }
}

/**
 * @brief 矩阵旋转
 * @return void
 */
void solve()
{
    printf("=== 矩阵旋转 ===\n");
    
    // 测试用例1：2x2矩阵
    int matrix1[2][MAX_N] = 
    {
        {1, 2},
        {3, 4}
    };
    
    printf("原始矩阵1 (2x2):\n");
    print_matrix(matrix1, 2);
    
    rotate_matrix(matrix1, 2);
    
    printf("旋转后矩阵1 (2x2):\n");
    print_matrix(matrix1, 2);
    
    // 测试用例2：3x3矩阵
    int matrix2[3][MAX_N] = 
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    printf("\n原始矩阵2 (3x3):\n");
    print_matrix(matrix2, 3);
    
    rotate_matrix(matrix2, 3);
    
    printf("旋转后矩阵2 (3x3):\n");
    print_matrix(matrix2, 3);
    
    // 测试用例3：4x4矩阵
    int matrix3[4][MAX_N] = 
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    
    printf("\n原始矩阵3 (4x4):\n");
    print_matrix(matrix3, 4);
    
    rotate_matrix(matrix3, 4);
    
    printf("旋转后矩阵3 (4x4):\n");
    print_matrix(matrix3, 4);
}

/**
 * @brief 主函数
 * @return int 程序退出状态码
 */
int main() {
    solve();
    return 0;
}
