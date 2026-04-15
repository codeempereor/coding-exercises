/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 16.memory_copy.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 内存复制
 * 算法描述:
 *   - 内存复制：通过指针操作，逐字节复制内存
 * 适用场景:
 *   - 内存管理
 *   - 系统编程
 *   - 性能优化
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
 * @brief 自定义内存拷贝函数（处理内存重叠）
 * @param dest 目标地址
 * @param src 源地址
 * @param n 拷贝字节数
 * @return 目标地址
 */
void *my_memmove(void *dest, const void *src, size_t n)
{
    char *d = dest;
    const char *s = src;
    
    // 如果源地址和目标地址相同，直接返回
    if (d == s)
{
        return dest;
    }
    
    // 如果目标地址在源地址之前，或没有重叠，从前向后拷贝
    if (d < s || d >= s + n)
{
        for (size_t i = 0; i < n; i++)
        {
            d[i] = s[i];
        }
    }
    else
    {
        // 有重叠，从后向前拷贝
        for (size_t i = n; i > 0; i--)
{
            d[i - 1] = s[i - 1];
        }
    }
    
    return dest;
}

/**
 * @brief 打印数组
 * @param arr 数组
 * @param n 数组长度
 */
void print_int_array(int arr[], int n)
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
 * @brief 内存拷贝
 * @return void
 */
;
    int dest1[5];
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    
    printf("测试用例1：正常拷贝\n");
    printf("源数组：");
    print_int_array(arr1, n1);
    printf("\n");
    
    my_memmove(dest1, arr1, sizeof(arr1));
    
    printf("目标数组：");
    print_int_array(dest1, n1);
    printf("\n");
    printf("预期：[1, 2, 3, 4, 5]\n\n");
    
    // 测试用例2：内存重叠（向后拷贝）
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    printf("测试用例2：内存重叠（向后拷贝）\n");
    printf("原数组：");
    print_int_array(arr2, n2);
    printf("\n");
    
    // 将arr2[0..3]拷贝到arr2[2..5]
    my_memmove(&arr2[2], &arr2[0], 4 * sizeof(int));
    
    printf("拷贝后数组：");
    print_int_array(arr2, n2);
    printf("\n");
    printf("预期：[1, 2, 1, 2, 3, 4, 7, 8]\n\n");
    
    // 测试用例3：内存重叠（向前拷贝）
    int arr3[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    
    printf("测试用例3：内存重叠（向前拷贝）\n");
    printf("原数组：");
    print_int_array(arr3, n3);
    printf("\n");
    
    // 将arr3[4..7]拷贝到arr3[2..5]
    my_memmove(&arr3[2], &arr3[4], 4 * sizeof(int));
    
    printf("拷贝后数组：");
    print_int_array(arr3, n3);
    printf("\n");
    printf("预期：[1, 2, 5, 6, 7, 8, 7, 8]\n\n");
    
    // 测试用例4：字符数组拷贝
    char str1[] = "Hello, World!";
    char dest2[20];
    
    printf("测试用例4：字符数组拷贝\n");
    printf("源字符串：%s\n", str1);
    
    my_memmove(dest2, str1, strlen(str1) + 1);
    
    printf("目标字符串：%s\n", dest2);
    printf("预期：Hello, World!\n");
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

printf("=== 内存拷贝 ===\n");
    printf("题目：实现内存拷贝函数，处理内存重叠情况\n\n");
    
    // 测试用例1：正常拷贝
    int arr1[] = {1, 2, 3, 4, 5

return 0;
}
