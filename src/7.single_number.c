/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 7.single_number.c
 * 作    者: 三道渊
 * 创建日期: 2026-03-29
 * 最后修改: 2026-03-29
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 只出现一次的数字
 * 算法描述:
 *   - 位运算法：利用异或操作的特性找出只出现一次的数字
 *   - 异或操作原理：
 *     - 任何数异或自身等于0：a ^ a = 0
 *     - 任何数异或0等于自身：a ^ 0 = a
 *     - 异或操作满足交换律和结合律：a ^ b ^ c = a ^ c ^ b
 *   - 成对出现的数字异或后相互抵消：a ^ a = 0
 *   - 只出现一次的数字异或后保留：a ^ b ≠ 0（因为b只出现一次）
 *   - 所有数字异或后，两个只出现一次数字的异或结果保留
 *   - 找到异或结果中最低位的1：
 *     - 两个只出现一次的数字在某一位上必然不同
 *     - 最低位的1可以作为分组标准
 *   - 分组原理：
 *     - 根据mask将数组分为两组
 *     - 一组包含其中一个只出现一次的数字和成对出现的数字
 *     - 另一组包含另一个只出现一次的数字和成对出现的数字
 *   - 异或后成对数字相互抵消：
 *     - 每组的异或结果就是该组中只出现一次的数字
 *   - 时间复杂度O(n)，空间复杂度O(1)
 * 适用场景:
 *   - 寻找数组中唯一出现的元素
 *   - 数据去重 数据库去重、日志分析、用户行为分析
 *   - 位运算优化
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-03-29 三道渊: 初始化文件
 * ============================================================================ */

#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif

#define MAX_N 100

/**
 * @brief 找出数组中只出现一次的两个数字
 * @param nums 输入数组
 * @param n 数组长度
 * @param single1 存储第一个只出现一次的数字
 * @param single2 存储第二个只出现一次的数字
 */
void find_single_numbers(int nums[], int n, int *single1, int *single2)
{
    // 1. 计算所有数字的异或，得到两个只出现一次数字的异或
    // 原理：成对出现的数字异或后相互抵消，只出现一次的数字保留
    int xor_result = 0;
    for (int i = 0; i < n; i++)
    {
        xor_result ^= nums[i];
    }
    
    // 2. 找到xor_result中最低位的1，作为分组标准
    // 原理：两个只出现一次的数字在某一位上必然不同
    int mask = 1;
    while ((xor_result & mask) == 0)
    {
        mask <<= 1;
    }
    
    // 3. 根据mask将数组分为两组，分别异或
    // 原理：成对数字异或后相互抵消，每组的异或结果就是只出现一次的数字
    *single1 = 0;
    *single2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] & mask)
        {
            *single1 ^= nums[i];
        }
        else
        {
            *single2 ^= nums[i];
        }
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

    printf("\n");
    printf("=== 只出现一次的数字 ===\n");
    printf("题目：找出数组中只出现一次的两个数字，其他数字都出现了两次\n\n");
    
    // 测试用例1：基本情况
    int nums1[] = {1, 2, 3, 4, 5, 1, 2, 3};
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    int single1, single2;
    
    printf("测试用例1:");
    print_array(nums1, n1);
    
    find_single_numbers(nums1, n1, &single1, &single2);
    
    printf("只出现一次的数字：%d 和 %d\n", single1, single2);
    printf("预期:4 和 5\n\n");
    
    // 测试用例2：包含0的情况
    int nums2[] = {0, 1, 2, 3, 0, 1};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    
    printf("测试用例2:");
    print_array(nums2, n2);
    
    find_single_numbers(nums2, n2, &single1, &single2);
    
    printf("只出现一次的数字：%d 和 %d\n", single1, single2);
    printf("预期:2 和 3\n\n");
    
    // 测试用例3：包含负数的情况
    int nums3[] = {-1, -2, -3, -4, -1, -2};
    int n3 = sizeof(nums3) / sizeof(nums3[0]);
    
    printf("测试用例3:");
    print_array(nums3, n3);
    
    find_single_numbers(nums3, n3, &single1, &single2);
    
    printf("只出现一次的数字：%d 和 %d\n", single1, single2);
    printf("预期：-3 和 -4\n\n");
    
    // 测试用例4：两个数字相邻的情况
    int nums4[] = {10, 20, 30, 40, 30, 20, 10, 50};
    int n4 = sizeof(nums4) / sizeof(nums4[0]);
    
    printf("测试用例4:");
    print_array(nums4, n4);
    
    find_single_numbers(nums4, n4, &single1, &single2);
    
    printf("只出现一次的数字：%d 和 %d\n", single1, single2);
    printf("预期:40 和 50\n\n");

return 0;
}
