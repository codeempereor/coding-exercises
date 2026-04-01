/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 8.string_left_rotate.c
 * 作    者: 三道渊
 * 创建日期: 2026-03-29
 * 最后修改: 2026-03-29
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 字符串左旋转
 * 算法描述:
 *   - 三次反转法：通过三次字符串反转实现左旋转
 *   - 步骤1：反转前k个字符
 *   - 步骤2：反转剩余的字符
 *   - 步骤3：反转整个字符串
 *   - 时间复杂度O(n)，空间复杂度O(1)
 * 适用场景:
 *   - 字符串操作
 *   - 数据旋转
 *   - 文本处理 文本编辑、排版、加密
 * 版权声明: © 2026 三道渊. All rights reserved.
 *   - 2026-03-29 三道渊: 添加了Windows API调用，设置控制台编码为UTF-8
 * 变更记录:
 *   - 2026-03-29 三道渊: 初始化文件
 * ============================================================================ */

#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif

#define MAX_N 100

/**
 * @brief 反转字符串的指定部分
 * @param str 字符串
 * @param start 起始位置
 * @param end 结束位置
 */
void reverse(char *str, int start, int end)
{
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

/**
 * @brief 字符串左旋转
 * @param str 字符串
 * @param k 左旋转的位数
 */
void left_rotate_string(char *str, int k)
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    
    // 处理k大于字符串长度的情况
    k = k % len;
    if (k == 0)
    {
        return; // 不需要旋转
    }
    
    // 三次反转法
    reverse(str, 0, k - 1);       // 反转前k个字符
    reverse(str, k, len - 1);      // 反转剩余的字符
    reverse(str, 0, len - 1);      // 反转整个字符串
}

/**
 * @brief 字符串左旋转
 * @return void
 */
void solve()
{
    printf("=== 字符串左旋转 ===\n");
    printf("题目：把字符串前面的若干个字符移动到字符串的尾部\n\n");
    
    // 测试用例1：基本情况
    char str1[] = "abcdef";
    int k1 = 2;
    
    printf("测试用例1：");
    printf("原字符串：%s，左旋转%d位\n", str1, k1);
    
    left_rotate_string(str1, k1);
    
    printf("旋转后：%s\n", str1);
    printf("预期：cdefab\n\n");
    
    // 测试用例2：k等于字符串长度
    char str2[] = "hello";
    int k2 = 5;
    
    printf("测试用例2：");
    printf("原字符串：%s，左旋转%d位\n", str2, k2);
    
    left_rotate_string(str2, k2);
    
    printf("旋转后：%s\n", str2);
    printf("预期：hello\n\n");
    
    // 测试用例3：k大于字符串长度
    char str3[] = "world";
    int k3 = 7;
    
    printf("测试用例3：");
    printf("原字符串：%s，左旋转%d位\n", str3, k3);
    
    left_rotate_string(str3, k3);
    
    printf("旋转后：%s\n", str3);
    printf("预期：rldwo\n\n");
    
    // 测试用例4：空字符串
    char str4[] = "";
    int k4 = 2;
    
    printf("测试用例4：");
    printf("原字符串：%s，左旋转%d位\n", str4, k4);
    
    left_rotate_string(str4, k4);
    
    printf("旋转后：%s\n", str4);
    printf("预期：\n");
}

/**
 * @brief 主函数
 * @return int 程序退出状态码
 */
int main() {
    #ifdef _WIN32
    // 设置控制台输出为UTF-8
    SetConsoleOutputCP(CP_UTF8);
    #endif
    solve();
    return 0;
}
