/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 6.majority_element.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 多数元素
 * 算法描述:
 *   - 多数元素：使用摩尔投票算法，快速找出多数元素
 * 适用场景:
 *   - 投票系统
 *   - 数据统计
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
 * @brief 寻找多数元素（出现次数超过数组长度一半的元素）
 * @param nums 输入数组
 * @param n 数组长度
 * @return 多数元素
 */
int find_majority_element(int nums[], int n)
{
    // 摩尔投票算法
    int candidate = 0;  // 初始化候选元素
    int count = 0;      // 初始化计数器
    
    // 第一遍：找出候选元素
    for (int i = 0; i < n; i++)
{
        if (count == 0)
        {
            candidate = nums[i];
            count = 1;
        }
        else if (nums[i] == candidate)
{
            count++;
        }
        else
        {
            count--;
        }
    }
    
    // 第二遍：验证候选元素是否是多数元素
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == candidate)
        {
            count++;
        }
    }
    
    if (count > n / 2)
    {
        return candidate;
    }
    else
    {
        return -1; // 不存在多数元素
    }
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
 * @brief 主函数
 * @return int 程序退出状态码
 */
int main()
{
    #ifdef _WIN32
    // 设置控制台输出为UTF-8
    SetConsoleOutputCP(CP_UTF8);
    #endif

    printf("=== 多数元素 ===\n");
    printf("题目：找出数组中出现次数超过数组长度一半的数字\n\n");
    
    // 测试用例1：基本情况
    int nums1[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    
    printf("测试用例1:");
    print_array(nums1, n1);
    printf("数组长度：%d,超过一半的数量：%d\n", n1, n1 / 2 + 1);
    
    int result1 = find_majority_element(nums1, n1);
    printf("多数元素：%d\n", result1);
    printf("预期:2\n\n");
    
    // 测试用例2：连续的多数元素
    int nums2[] = {3, 3, 3, 3, 2, 2, 2};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    
    printf("测试用例2:");
    print_array(nums2, n2);
    printf("数组长度：%d,超过一半的数量：%d\n", n2, n2 / 2 + 1);    
    
    int result2 = find_majority_element(nums2, n2);
    printf("多数元素：%d\n", result2);
    printf("预期:3\n\n");
    
    // 测试用例3：单个元素
    int nums3[] = {5};
    int n3 = sizeof(nums3) / sizeof(nums3[0]);
    
    printf("测试用例3:");
    print_array(nums3, n3);
    printf("数组长度：%d,超过一半的数量：%d\n", n3, n3 / 2 + 1);
    
    int result3 = find_majority_element(nums3, n3);
    printf("多数元素：%d\n", result3);
    printf("预期:5\n\n");
    
    // 测试用例4：偶数长度
    int nums4[] = {2, 2, 2, 2, 1, 1};
    int n4 = sizeof(nums4) / sizeof(nums4[0]);
    
    printf("测试用例4:");
    print_array(nums4, n4);
    printf("数组长度：%d,超过一半的数量：%d\n", n4, n4 / 2 + 1);
    
    int result4 = find_majority_element(nums4, n4);
    printf("多数元素：%d\n", result4);
    printf("预期:2\n\n");

    return 0;
}
