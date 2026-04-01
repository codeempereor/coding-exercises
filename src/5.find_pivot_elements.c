/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 5.find_pivot_elements.c
 * 作    者: 三道渊
 * 创建日期: 2026-03-29
 * 最后修改: 2026-03-29
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 寻找中间元素
 * 算法描述:
 *   - 双数组法：分别计算每个位置左侧的最大值和右侧的最小值
 *   - 从左到右计算leftMax[i]，表示i位置左侧的最大值
 *   - 从右到左计算rightMin[i]，表示i位置右侧的最小值
 *   - 如果leftMax[i] <= nums[i] <= rightMin[i]，则nums[i]是中间元素
 *   - 时间复杂度O(n)，空间复杂度O(n)
 * 适用场景:
 *   - 寻找数组中的"枢纽"元素
 *   - 数据流中的中位数查找
 *   - 数组分区问题
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-03-29 三道渊: 初始化文件
 * ============================================================================ */

#include <stdio.h>

#define MAX_N 100

/**
 * @brief 寻找中间元素
 * @param nums 输入数组
 * @param n 数组长度
 */
void find_pivot_elements(int nums[], int n)
{
    if (n <= 0)
    {
        printf("数组为空\n");
        return;
    }
    
    // 分配辅助数组
    int leftMax[n];
    int rightMin[n];
    
    // 计算leftMax：leftMax[i]表示i位置左侧的最大值
    leftMax[0] = nums[0];  // 第一个元素左侧没有元素，设为自身
    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] > leftMax[i - 1])
        {
            leftMax[i] = nums[i - 1];
        }
        else
        {
            leftMax[i] = leftMax[i - 1];
        }
    }
    
    // 计算rightMin：rightMin[i]表示i位置右侧的最小值
    rightMin[n - 1] = nums[n - 1];  // 最后一个元素右侧没有元素，设为自身
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i + 1] < rightMin[i + 1])
        {
            rightMin[i] = nums[i + 1];
        }
        else
        {
            rightMin[i] = rightMin[i + 1];
        }
    }
    
    // 寻找中间元素
    printf("中间元素：");
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        // 检查是否满足条件：左侧最大值 <= 当前元素 <= 右侧最小值
        if (leftMax[i] <= nums[i] && nums[i] <= rightMin[i])
        {
            printf("%d ", nums[i]);
            found = 1;
        }
    }
    
    if (!found)
    {
        printf("无");
    }
    printf("\n");
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
 * @brief 寻找中间元素
 * @return void
 */
void solve()
{
    printf("=== 寻找中间元素 ===\n");
    printf("题目：找出数组中满足左边所有数都小于等于它，右边所有数都大于等于它的元素\n\n");
    
    // 测试用例1：基本情况
    int nums1[] = {1, 2, 3, 4, 5};
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    
    printf("测试用例1:");
    print_array(nums1, n1);
    printf("说明：每个元素都满足条件（升序数组）\n");
    find_pivot_elements(nums1, n1);
    printf("预期:1 2 3 4 5\n\n");
    
    // 测试用例2：降序数组
    int nums2[] = {5, 4, 3, 2, 1};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    
    printf("测试用例2:");
    print_array(nums2, n2);
    printf("说明：只有最后一个元素满足条件\n");
    find_pivot_elements(nums2, n2);
    printf("预期:1\n\n");
    
    // 测试用例3：普通情况
    int nums3[] = {1, 3, 2, 4, 5};
    int n3 = sizeof(nums3) / sizeof(nums3[0]);
    
    printf("测试用例3:");
    print_array(nums3, n3);
    printf("说明:1, 4, 5满足条件\n");
    find_pivot_elements(nums3, n3);
    printf("预期:1 4 5\n\n");
    
    // 测试用例4：包含重复元素
    int nums4[] = {2, 2, 2, 2, 2};
    int n4 = sizeof(nums4) / sizeof(nums4[0]);
    
    printf("测试用例4:");
    print_array(nums4, n4);
    printf("说明:所有元素都相等，都满足条件\n");
    find_pivot_elements(nums4, n4);
    printf("预期:2 2 2 2 2\n\n");
    
    // 测试用例5：只有一个元素
    int nums5[] = {42};
    int n5 = sizeof(nums5) / sizeof(nums5[0]);
    
    printf("测试用例5:");
    print_array(nums5, n5);
    printf("说明:只有一个元素，自然满足条件\n");
    find_pivot_elements(nums5, n5);
    printf("预期:42\n");
}

/**
 * @brief 主函数
 * @return int 程序退出状态码
 */
int main() {
    solve();
    return 0;
}
