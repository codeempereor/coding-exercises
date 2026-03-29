#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os

# 题目信息列表
topics = [
    # 1-10
    (1, "brother_string", "兄弟字符串"),
    (2, "merge_sets", "合并集合"),
    (3, "rotate_matrix", "矩阵旋转"),
    (4, "array_product", "数组乘积"),
    (5, "find_pivot_elements", "寻找中间元素"),
    (6, "majority_element", "多数元素"),
    (7, "single_number", "只出现一次的数字"),
    (8, "string_left_rotate", "字符串左旋转"),
    (9, "two_sum_sorted", "有序数组两数之和"),
    (10, "minimize_sum_difference", "最小化和差"),
    # 11-20
    (11, "max_partition_equality", "最大等和分割"),
    (12, "find_common_element", "查找公共元素"),
    (13, "substring_count", "子串出现次数"),
    (14, "longest_palindrome", "最长回文子串"),
    (15, "coin_combinations", "硬币组合数"),
    (16, "memory_copy", "内存拷贝"),
    (17, "string_insert", "字符串插入"),
    (18, "string_to_int", "字符串转整数"),
    (19, "josephus_problem", "约瑟夫环问题"),
    (20, "memcpy_implementation", "memcpy实现"),
    # 21-30
    (21, "float_to_string", "浮点数转字符串"),
    (22, "staircase_climbing", "爬楼梯"),
    (23, "count_ones", "数字1出现次数"),
    (24, "reorder_odd_even", "奇偶重排"),
    (25, "longest_substring_no_repeat", "最长无重复子串"),
    (26, "perfect_numbers", "完数"),
    (27, "min_subarray_sum", "最小子数组和"),
    (28, "jump_game", "跳跃游戏"),
    (29, "array_rotate_right", "数组右旋转"),
    (30, "string_elimination", "字符串消除"),
    # 31-40
    (31, "prime_factorization", "质因数分解"),
    (32, "sum_of_aaa", "连数求和"),
    (33, "string_deformation", "字符串变形"),
    (34, "count_binary_substrings", "二进制子串计数"),
    (35, "subset_sum_count", "子集和计数"),
    (36, "amicable_numbers", "亲密数"),
    (37, "is_subsequence", "子序列判断"),
    (38, "most_frequent_digit", "最常见数字"),
    (39, "prime_range", "区间素数"),
    (40, "isomorphic_strings", "同构字符串"),
    # 41-50
    (41, "first_missing_positive", "缺失的第一个正数"),
    (42, "palindrome_primes", "回文素数"),
    (43, "linked_list_cycle", "链表环入口"),
    (44, "string_multiply", "字符串相乘"),
    (45, "ip_addresses", "IP地址生成"),
    (46, "reverse_linked_list_range", "链表区间反转"),
    (47, "remove_duplicates", "移除重复元素"),
    (48, "find_median_sorted_arrays", "两个有序数组的中位数"),
    (49, "valid_ip_address", "有效IP地址"),
    (50, "odd_even_linked_list", "奇偶链表"),
    # 51-60
    (51, "find_kth_largest", "第k大元素"),
    (52, "first_missing_positive_2", "缺失的第一个正数（第二版）"),
    (53, "longest_common_substring", "最长公共子串"),
    (54, "string_add", "字符串相加"),
    (55, "trailing_zeros", "阶乘尾随零"),
    (56, "binary_add", "二进制相加"),
    (57, "sum_without_operators", "无运算符求和"),
    (58, "letter_combinations", "字母组合"),
    (59, "number_to_chinese", "数字转中文"),
    (60, "max_xor", "最大异或值"),
    # 61-70
    (61, "partition_k_subsets", "划分为k个等和子集"),
    (62, "calculator", "整数计算器"),
    (63, "generate_parentheses", "生成括号"),
    (64, "merge_intervals", "合并区间"),
    (65, "add_two_numbers", "两数相加（链表）"),
    (66, "ugly_number", "丑数"),
    (67, "max_product_subarray", "最大乘积子数组"),
    (68, "egg_drop", "鸡蛋掉落"),
    (69, "array_cyclic_shift", "数组循环移位"),
    (70, "integer_partition", "整数分拆")
]

src_dir = "src"

# 确保src目录存在
if not os.path.exists(src_dir):
    os.makedirs(src_dir)

for number, filename, description in topics:
    file_path = os.path.join(src_dir, f"{number}.{filename}.c")
    
    # 生成文件内容
    content = "/* =============================================================================\n"
    content += f" * 项目名称: 编程练习题\n"
    content += f" * 文件名称: {number}.{filename}.c\n"
    content += " * 作    者: 三道渊\n"
    content += " * 创建日期: 2026-03-29\n"
    content += " * 最后修改: 2026-03-29\n"
    content += " * 版    本: v1.0.0\n"
    content += " * 适用平台: Windows x64\n"
    content += " * 编译依赖: GCC 15.2.0, stdio.h\n"
    content += " * 功能描述:\n"
    content += f" *   1. {description}\n"
    content += " * 版权声明: © 2026 三道渊. All rights reserved.\n"
    content += " * 变更记录:\n"
    content += " *   - 2026-03-29 三道渊: 初始化文件\n"
    content += " * ============================================================================ */\n\n"
    content += "#include <stdio.h>\n\n"
    content += "#define MAX_N 100\n\n"
    content += "/**\n"
    content += f" * @brief {description}\n"
    content += " * @return void\n"
    content += " */\n"
    content += "void solve() {\n"
    content += f"    // TODO: 实现{description}的解决方案\n"
    content += f"    printf(\"=== {description} ===\\n\");\n"
    content += "    printf(\"Solution to be implemented...\\n\");\n"
    content += "}\n\n"
    content += "/**\n"
    content += " * @brief 主函数\n"
    content += " * @return int 程序退出状态码\n"
    content += " */\n"
    content += "int main() {\n"
    content += "    solve();\n"
    content += "    return 0;\n"
    content += "}\n"
    
    # 写入文件
    with open(file_path, 'w', encoding='utf-8') as f:
        f.write(content)
    
    print(f"Created: {file_path}")

print("\nAll files generated successfully!")
