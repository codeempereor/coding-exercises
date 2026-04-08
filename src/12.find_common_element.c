/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 12.find_common_element.c
 * 作    者: 三道渊
 * 创建日期: 2026-03-29
 * 最后修改: 2026-04-04
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 查找公共元素：查找两个数组中的所有公共元素（去重）
 * 算法描述:
 *   - 双重循环法：遍历第一个数组的每个元素
 *   - 在第二个数组中查找该元素是否存在
 *   - 检查是否已经在结果数组中，避免重复
 *   - 时间复杂度O(n1*n2)，空间复杂度O(min(n1,n2))
 * 适用场景:
 *   - 数组交集问题
 *   - 元素匹配问题
 *   - 集合操作场景
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-04-04 三道渊: 补充算法描述和适用场景
 *   - 2026-03-29 三道渊: 初始化文件
 * ============================================================================ */

#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif

#define MAX_N 100

/**
 * @brief 在数组中查找元素
 * @param arr 数组
 * @param n 数组长度
 * @param target 目标元素
 * @return 1表示找到，0表示未找到
 */
int find_in_array(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return 1;
        }
    }
    return 0;
}

/**
 * @brief 查找两个数组的公共元素
 * @param arr1 第一个数组
 * @param n1 第一个数组长度
 * @param arr2 第二个数组
 * @param n2 第二个数组长度
 * @param result 存储公共元素的数组
 * @return 公共元素个数
 */
int find_common_elements(int arr1[], int n1, int arr2[], int n2, int result[])
{
    int count = 0;
    for (int i = 0; i < n1; i++)
    {
        // 检查arr1[i]是否在arr2中，且不在result中（去重）
        if (find_in_array(arr2, n2, arr1[i]))
        {
            // 检查是否已经在result中
            int already_in_result = 0;
            for (int j = 0; j < count; j++)
            {
                if (result[j] == arr1[i])
                {
                    already_in_result = 1;
                    break;
                }
            }
            if (!already_in_result)
            {
                result[count++] = arr1[i];
            }
        }
    }
    return count;
}

/**
 * @brief 打印数组
 * @param arr 数组
 * @param n 数组长度
 */
void print_array(int arr[], int n)
{
    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i < n - 1)
        {
            printf(", ");
        }
    }
    printf("]");
}

/**
 * @brief 查找公共元素
 * @return void
 */
;
    int arr2[] = {4, 5, 6, 7, 8};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int result[MAX_N];
    
    printf("测试用例1：\n");
    printf("数组1：");
    print_array(arr1, n1);
    printf("\n数组2：");
    print_array(arr2, n2);
    printf("\n");
    
    int count1 = find_common_elements(arr1, n1, arr2, n2, result);
    printf("公共元素：");
    print_array(result, count1);
    printf("\n公共元素个数：%d\n", count1);
    printf("预期：[4, 5]，个数：2\n\n");
    
    // 测试用例2：无公共元素
    int arr3[] = {1, 2, 3};
    int arr4[] = {4, 5, 6};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    
    printf("测试用例2：\n");
    printf("数组1：");
    print_array(arr3, n3);
    printf("\n数组2：");
    print_array(arr4, n4);
    printf("\n");
    
    int count2 = find_common_elements(arr3, n3, arr4, n4, result);
    printf("公共元素：");
    print_array(result, count2);
    printf("\n公共元素个数：%d\n", count2);
    printf("预期：[]，个数：0\n\n");
    
    // 测试用例3：有重复元素
    int arr5[] = {1, 2, 2, 3, 3, 3};
    int arr6[] = {2, 2, 3, 4};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    int n6 = sizeof(arr6) / sizeof(arr6[0]);
    
    printf("测试用例3：\n");
    printf("数组1：");
    print_array(arr5, n5);
    printf("\n数组2：");
    print_array(arr6, n6);
    printf("\n");
    
    int count3 = find_common_elements(arr5, n5, arr6, n6, result);
    printf("公共元素：");
    print_array(result, count3);
    printf("\n公共元素个数：%d\n", count3);
    printf("预期：[2, 3]，个数：2（去重）\n");
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

printf("=== 查找公共元素 ===\n");
    printf("题目：查找两个数组中的所有公共元素（去重）\n\n");
    
    // 测试用例1：有公共元素
    int arr1[] = {1, 2, 3, 4, 5

return 0;
}
