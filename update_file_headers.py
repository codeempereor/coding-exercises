#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
更新所有代码文件的文件头格式
"""

import os
import re

# 标准文件头模板
HEADER_TEMPLATE = """/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: {file_name}
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, {dependencies}
 * 功能描述:
 *   1. {description}
 * 算法描述:
 *   - {algorithm}
 * 适用场景:
 *   - {scenario}
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-04-15 三道渊: 初始化文件
 * ============================================================================ */
"""

# 文件描述映射
descriptions = {
    "1.brother_string.c": "兄弟字符串",
    "2.merge_sets.c": "合并集合",
    "3.rotate_matrix.c": "旋转矩阵",
    "4.array_product.c": "数组乘积",
    "5.find_pivot_elements.c": "寻找 pivot 元素",
    "6.majority_element.c": "多数元素",
    "7.single_number.c": "只出现一次的数字",
    "8.string_left_rotate.c": "字符串左旋转",
    "9.two_sum_sorted.c": "两数之和（有序数组）",
    "10.minimize_sum_difference.c": "最小化和差",
    "11.max_partition_equality.c": "最大分区相等和",
    "12.find_common_element.c": "寻找共同元素",
    "13.substring_count.c": "子串计数",
    "14.longest_palindrome.c": "最长回文子串",
    "15.coin_combination.c": "硬币组合",
    "16.memory_copy.c": "内存复制",
    "17.string_insert.c": "字符串插入",
    "18.string_to_integer.c": "字符串转整数",
    "19.josephus_problem.c": "约瑟夫环问题",
    "20.memcpy_implementation.c": "memcpy 实现",
    "21.float_to_string.c": "浮点数转字符串",
    "22.staircase_climbing.c": "爬楼梯",
    "22.climb_stairs.c": "爬楼梯",
    "23.count_ones.c": "1 的个数",
    "23.count_digit_one.c": "1 的个数",
    "24.reorder_odd_even.c": "奇偶重排",
    "24.reorder_array.c": "奇偶重排",
    "25.longest_unique_substring.c": "最长无重复子串",
    "25.longest_substring_no_repeat.c": "最长无重复子串",
    "26.perfect_numbers.c": "完全数",
    "26.perfect_number.c": "完全数",
    "27.min_subarray_sum.c": "最小子数组和",
    "28.jump_game.c": "跳跃游戏",
    "29.array_rotate_right.c": "数组右旋转",
    "29.array_right_rotate.c": "数组右旋转",
    "30.string_elimination.c": "字符串消除",
    "31.prime_factorization.c": "质因数分解",
    "32.sum_of_aaa.c": "连数求和",
    "33.string_deformation.c": "字符串变形",
    "34.count_binary_substrings.c": "二进制子串计数",
    "35.subset_sum_count.c": "子集和计数",
    "36.amicable_numbers.c": "亲密数",
    "37.is_subsequence.c": "子序列判断",
    "38.most_frequent_digit.c": "最常见数字",
    "39.prime_range.c": "区间素数",
    "40.isomorphic_strings.c": "同构字符串",
    "41.first_missing_positive.c": "缺失的第一个正数",
    "42.palindrome_primes.c": "回文素数",
    "43.linked_list_cycle.c": "链表环检测",
    "44.string_multiply.c": "字符串相乘",
    "45.ip_addresses.c": "IP 地址生成",
    "46.reverse_linked_list_range.c": "链表区间反转",
    "47.remove_duplicates.c": "删除排序数组中的重复项",
    "48.find_median_sorted_arrays.c": "寻找两个有序数组的中位数",
    "49.valid_ip_address.c": "有效的 IP 地址",
    "50.odd_even_linked_list.c": "奇偶链表",
    "51.find_kth_largest.c": "第 k 大的数",
    "52.first_missing_positive_2.c": "缺失的第一个正数",
    "53.longest_common_substring.c": "最长公共子串",
    "54.string_addition.c": "字符串相加",
    "54.string_add.c": "字符串相加",
    "55.factorial_trailing_zeros.c": "阶乘末尾零的个数",
    "55.trailing_zeros.c": "阶乘末尾零的个数",
    "56.binary_addition.c": "二进制字符串相加",
    "56.binary_add.c": "二进制字符串相加",
    "57.sum_1_to_n.c": "求 1+2+...+n",
    "57.sum_without_operators.c": "求 1+2+...+n",
    "58.letter_combinations.c": "电话号码的字母组合",
    "59.chinese_number.c": "整数的中文读法",
    "60.max_xor.c": "最大异或值",
    "61.partition_k_subsets.c": "划分为 k 个相等的子集",
    "62.calculator.c": "计算器",
    "63.generate_parentheses.c": "生成括号",
    "64.merge_intervals.c": "合并区间",
    "65.add_two_numbers.c": "两数相加",
    "66.ugly_number.c": "丑数",
    "67.max_product_subarray.c": "最大乘积子数组",
    "68.egg_drop.c": "鸡蛋掉落",
    "69.array_cyclic_shift.c": "数组循环移位",
    "70.integer_partition.c": "整数划分"
}

# 算法描述映射
algorithms = {
    "1.brother_string.c": "素数乘积法：为每个字母分配唯一素数，计算字符串中字符对应素数的乘积，若两个字符串的素数乘积相等，则它们是兄弟字符串",
    "2.merge_sets.c": "集合合并：使用哈希表存储集合元素，实现快速查找和合并",
    "3.rotate_matrix.c": "矩阵旋转：通过分层旋转的方法，逐层处理矩阵元素",
    "4.array_product.c": "数组乘积：使用左右乘积数组，避免使用除法",
    "5.find_pivot_elements.c": "寻找 pivot 元素：通过遍历数组，计算左右和并比较",
    "6.majority_element.c": "多数元素：使用摩尔投票算法，快速找出多数元素",
    "7.single_number.c": "只出现一次的数字：使用异或运算，相同数字异或结果为 0",
    "8.string_left_rotate.c": "字符串左旋转：通过三次反转实现",
    "9.two_sum_sorted.c": "两数之和（有序数组）：使用双指针法，从两端向中间移动",
    "10.minimize_sum_difference.c": "最小化和差：通过排序和双指针法，寻找最优解",
    "11.max_partition_equality.c": "最大分区相等和：使用前缀和和哈希表，寻找可能的分区点",
    "12.find_common_element.c": "寻找共同元素：使用哈希表统计元素出现次数",
    "13.substring_count.c": "子串计数：通过遍历字符串，统计符合条件的子串",
    "14.longest_palindrome.c": "最长回文子串：使用中心扩展法，遍历所有可能的回文中心",
    "15.coin_combination.c": "硬币组合：使用动态规划，计算不同金额的组合数",
    "16.memory_copy.c": "内存复制：通过指针操作，逐字节复制内存",
    "17.string_insert.c": "字符串插入：通过字符串操作，在指定位置插入子串",
    "18.string_to_integer.c": "字符串转整数：处理符号、数字和边界情况",
    "19.josephus_problem.c": "约瑟夫环问题：使用循环链表或数学公式求解",
    "20.memcpy_implementation.c": "memcpy 实现：通过指针操作，高效复制内存",
    "21.float_to_string.c": "浮点数转字符串：处理整数部分和小数部分，格式化输出",
    "22.staircase_climbing.c": "爬楼梯：使用动态规划，计算到达每阶楼梯的方法数",
    "22.climb_stairs.c": "爬楼梯：使用动态规划，计算到达每阶楼梯的方法数",
    "23.count_ones.c": "1 的个数：通过位运算，统计二进制中 1 的个数",
    "23.count_digit_one.c": "1 的个数：通过数学方法，计算从 1 到 n 中 1 的个数",
    "24.reorder_odd_even.c": "奇偶重排：使用双指针法，将奇数和偶数分开",
    "24.reorder_array.c": "奇偶重排：使用双指针法，将奇数和偶数分开",
    "25.longest_unique_substring.c": "最长无重复子串：使用滑动窗口和哈希表，记录字符位置",
    "25.longest_substring_no_repeat.c": "最长无重复子串：使用滑动窗口和哈希表，记录字符位置",
    "26.perfect_numbers.c": "完全数：通过遍历可能的因子，计算因子和并判断",
    "26.perfect_number.c": "完全数：通过遍历可能的因子，计算因子和并判断",
    "27.min_subarray_sum.c": "最小子数组和：使用动态规划，记录当前最小和",
    "28.jump_game.c": "跳跃游戏：贪心算法，记录最远可达位置",
    "29.array_rotate_right.c": "数组右旋转：通过三次反转实现",
    "29.array_right_rotate.c": "数组右旋转：通过三次反转实现",
    "30.string_elimination.c": "字符串消除：使用栈，模拟消除过程",
    "31.prime_factorization.c": "质因数分解：使用试除法，分解质因数",
    "32.sum_of_aaa.c": "连数求和：通过循环生成连数并累加",
    "33.string_deformation.c": "字符串变形：通过字符串操作，实现大小写转换和空格处理",
    "34.count_binary_substrings.c": "二进制子串计数：统计连续相同字符的长度，计算可形成的子串数",
    "35.subset_sum_count.c": "子集和计数：使用动态规划，计算可能的和的个数",
    "36.amicable_numbers.c": "亲密数：计算每个数的真因子和，判断是否为亲密数对",
    "37.is_subsequence.c": "子序列判断：使用双指针法，遍历两个字符串",
    "38.most_frequent_digit.c": "最常见数字：统计每个数字的出现次数，找出最常见的",
    "39.prime_range.c": "区间素数：使用筛法，筛选出区间内的素数",
    "40.isomorphic_strings.c": "同构字符串：使用哈希表，建立字符映射关系",
    "41.first_missing_positive.c": "缺失的第一个正数：使用原地哈希，标记出现的正数",
    "42.palindrome_primes.c": "回文素数：判断素数和回文数",
    "43.linked_list_cycle.c": "链表环检测：使用快慢指针，判断是否存在环",
    "44.string_multiply.c": "字符串相乘：模拟手工乘法，处理每一位的乘积",
    "45.ip_addresses.c": "IP 地址生成：使用回溯法，生成所有可能的 IP 地址",
    "46.reverse_linked_list_range.c": "链表区间反转：通过指针操作，反转指定区间的链表",
    "47.remove_duplicates.c": "删除排序数组中的重复项：使用双指针法，原地删除重复元素",
    "48.find_median_sorted_arrays.c": "寻找两个有序数组的中位数：使用二分查找，确保时间复杂度 O(log(min(m,n)))",
    "49.valid_ip_address.c": "有效的 IP 地址：验证 IP 地址的格式和范围",
    "50.odd_even_linked_list.c": "奇偶链表：将链表节点按奇偶位置分开",
    "51.find_kth_largest.c": "第 k 大的数：使用快速选择算法，高效找到第 k 大元素",
    "52.first_missing_positive_2.c": "缺失的第一个正数：使用原地哈希，标记出现的正数",
    "53.longest_common_substring.c": "最长公共子串：使用动态规划，记录最长公共子串的长度",
    "54.string_addition.c": "字符串相加：模拟手工加法，处理进位",
    "54.string_add.c": "字符串相加：模拟手工加法，处理进位",
    "55.factorial_trailing_zeros.c": "阶乘末尾零的个数：计算 5 的因子个数",
    "55.trailing_zeros.c": "阶乘末尾零的个数：计算 5 的因子个数",
    "56.binary_addition.c": "二进制字符串相加：模拟二进制加法，处理进位",
    "56.binary_add.c": "二进制字符串相加：模拟二进制加法，处理进位",
    "57.sum_1_to_n.c": "求 1+2+...+n：使用递归和逻辑短路特性",
    "57.sum_without_operators.c": "求 1+2+...+n：使用递归和逻辑短路特性",
    "58.letter_combinations.c": "电话号码的字母组合：使用回溯法，生成所有可能的组合",
    "59.chinese_number.c": "整数的中文读法：处理各个段位的数字，添加适当的单位",
    "60.max_xor.c": "最大异或值：使用字典树，优化异或值的查找",
    "61.partition_k_subsets.c": "划分为 k 个相等的子集：使用回溯法，尝试将元素分配到不同子集",
    "62.calculator.c": "计算器：处理表达式的计算，支持加减乘除和括号",
    "63.generate_parentheses.c": "生成括号：使用回溯法，生成有效的括号组合",
    "64.merge_intervals.c": "合并区间：按起始位置排序，然后合并重叠的区间",
    "65.add_two_numbers.c": "两数相加：使用链表，模拟加法过程",
    "66.ugly_number.c": "丑数：通过生成丑数序列，判断是否为丑数",
    "67.max_product_subarray.c": "最大乘积子数组：使用动态规划，记录最大和最小乘积",
    "68.egg_drop.c": "鸡蛋掉落：使用动态规划，计算最少尝试次数",
    "69.array_cyclic_shift.c": "数组循环移位：通过三次反转实现",
    "70.integer_partition.c": "整数划分：使用动态规划，计算整数的划分数"
}

# 适用场景映射
scenarios = {
    "1.brother_string.c": "字符串相似度判断、字符集合比较、快速去重和分组、单词变位词检测",
    "2.merge_sets.c": "集合操作、数据去重、合并数据",
    "3.rotate_matrix.c": "图像处理、矩阵变换、游戏开发",
    "4.array_product.c": "数组处理、数学计算、数据分析",
    "5.find_pivot_elements.c": "数组分析、平衡问题、资源分配",
    "6.majority_element.c": "投票系统、数据统计、模式识别",
    "7.single_number.c": "数据去重、异常检测、位运算优化",
    "8.string_left_rotate.c": "字符串处理、文本编辑、加密算法",
    "9.two_sum_sorted.c": "数组搜索、目标值查找、数据匹配",
    "10.minimize_sum_difference.c": "优化问题、资源分配、平衡问题",
    "11.max_partition_equality.c": "数组分割、资源分配、平衡问题",
    "12.find_common_element.c": "数据交集、集合操作、数据匹配",
    "13.substring_count.c": "字符串分析、模式匹配、文本处理",
    "14.longest_palindrome.c": "文本分析、回文检测、字符串处理",
    "15.coin_combination.c": "货币系统、组合问题、动态规划练习",
    "16.memory_copy.c": "内存管理、系统编程、性能优化",
    "17.string_insert.c": "文本编辑、字符串处理、数据格式化",
    "18.string_to_integer.c": "数据转换、输入处理、边界情况处理",
    "19.josephus_problem.c": "游戏开发、循环问题、数学建模",
    "20.memcpy_implementation.c": "系统编程、内存管理、性能优化",
    "21.float_to_string.c": "数据转换、格式化输出、数值处理",
    "22.staircase_climbing.c": "动态规划练习、路径计数、组合问题",
    "22.climb_stairs.c": "动态规划练习、路径计数、组合问题",
    "23.count_ones.c": "位运算优化、性能分析、算法设计",
    "23.count_digit_one.c": "数学问题、计数问题、算法设计",
    "24.reorder_odd_even.c": "数组处理、排序问题、双指针技术",
    "24.reorder_array.c": "数组处理、排序问题、双指针技术",
    "25.longest_unique_substring.c": "文本分析、字符串处理、滑动窗口技术",
    "25.longest_substring_no_repeat.c": "文本分析、字符串处理、滑动窗口技术",
    "26.perfect_numbers.c": "数学问题、因子计算、数论研究",
    "26.perfect_number.c": "数学问题、因子计算、数论研究",
    "27.min_subarray_sum.c": "数组分析、动态规划、优化问题",
    "28.jump_game.c": "游戏开发、贪心算法、路径规划",
    "29.array_rotate_right.c": "数组处理、循环移位、数据重组",
    "29.array_right_rotate.c": "数组处理、循环移位、数据重组",
    "30.string_elimination.c": "字符串处理、栈应用、模拟过程",
    "31.prime_factorization.c": "数学问题、密码学、数论研究",
    "32.sum_of_aaa.c": "数学计算、循环处理、模式识别",
    "33.string_deformation.c": "文本处理、字符串转换、格式化",
    "34.count_binary_substrings.c": "二进制分析、字符串处理、模式计数",
    "35.subset_sum_count.c": "组合问题、动态规划、资源分配",
    "36.amicable_numbers.c": "数学问题、数论研究、因子计算",
    "37.is_subsequence.c": "字符串处理、模式匹配、序列分析",
    "38.most_frequent_digit.c": "数据统计、频率分析、模式识别",
    "39.prime_range.c": "数学问题、素数筛选、数论研究",
    "40.isomorphic_strings.c": "字符串处理、模式匹配、字符映射",
    "41.first_missing_positive.c": "数组处理、原地算法、异常检测",
    "42.palindrome_primes.c": "数学问题、素数判断、回文检测",
    "43.linked_list_cycle.c": "链表操作、环检测、算法设计",
    "44.string_multiply.c": "大数计算、字符串处理、模拟运算",
    "45.ip_addresses.c": "网络编程、字符串处理、回溯算法",
    "46.reverse_linked_list_range.c": "链表操作、指针技术、算法设计",
    "47.remove_duplicates.c": "数组处理、原地算法、数据去重",
    "48.find_median_sorted_arrays.c": "排序算法、二分查找、中位数计算",
    "49.valid_ip_address.c": "网络编程、数据验证、字符串处理",
    "50.odd_even_linked_list.c": "链表操作、指针技术、数据重组",
    "51.find_kth_largest.c": "排序算法、选择问题、快速选择",
    "52.first_missing_positive_2.c": "数组处理、原地算法、异常检测",
    "53.longest_common_substring.c": "字符串处理、动态规划、模式匹配",
    "54.string_addition.c": "大数计算、字符串处理、模拟运算",
    "54.string_add.c": "大数计算、字符串处理、模拟运算",
    "55.factorial_trailing_zeros.c": "数学问题、阶乘计算、因子分析",
    "55.trailing_zeros.c": "数学问题、阶乘计算、因子分析",
    "56.binary_addition.c": "二进制计算、字符串处理、模拟运算",
    "56.binary_add.c": "二进制计算、字符串处理、模拟运算",
    "57.sum_1_to_n.c": "数学计算、递归算法、逻辑短路",
    "57.sum_without_operators.c": "数学计算、递归算法、逻辑短路",
    "58.letter_combinations.c": "组合问题、回溯算法、字符串处理",
    "59.chinese_number.c": "数字转换、中文表示、格式化输出",
    "60.max_xor.c": "位运算、字典树、优化问题",
    "61.partition_k_subsets.c": "组合问题、回溯算法、优化问题",
    "62.calculator.c": "表达式计算、栈应用、解析器设计",
    "63.generate_parentheses.c": "组合问题、回溯算法、字符串处理",
    "64.merge_intervals.c": "区间处理、排序算法、数据合并",
    "65.add_two_numbers.c": "链表操作、大数计算、模拟运算",
    "66.ugly_number.c": "数学问题、动态规划、序列生成",
    "67.max_product_subarray.c": "数组分析、动态规划、优化问题",
    "68.egg_drop.c": "动态规划、优化问题、风险评估",
    "69.array_cyclic_shift.c": "数组处理、循环移位、数据重组",
    "70.integer_partition.c": "数学问题、动态规划、组合问题"
}

# 依赖项映射
dependencies = {
    "1.brother_string.c": "stdio.h",
    "2.merge_sets.c": "stdio.h",
    "3.rotate_matrix.c": "stdio.h",
    "4.array_product.c": "stdio.h",
    "5.find_pivot_elements.c": "stdio.h",
    "6.majority_element.c": "stdio.h",
    "7.single_number.c": "stdio.h",
    "8.string_left_rotate.c": "stdio.h, string.h",
    "9.two_sum_sorted.c": "stdio.h",
    "10.minimize_sum_difference.c": "stdio.h, stdlib.h",
    "11.max_partition_equality.c": "stdio.h",
    "12.find_common_element.c": "stdio.h",
    "13.substring_count.c": "stdio.h",
    "14.longest_palindrome.c": "stdio.h, string.h",
    "15.coin_combination.c": "stdio.h",
    "16.memory_copy.c": "stdio.h",
    "17.string_insert.c": "stdio.h, string.h",
    "18.string_to_integer.c": "stdio.h, string.h",
    "19.josephus_problem.c": "stdio.h",
    "20.memcpy_implementation.c": "stdio.h",
    "21.float_to_string.c": "stdio.h, string.h",
    "22.staircase_climbing.c": "stdio.h",
    "22.climb_stairs.c": "stdio.h",
    "23.count_ones.c": "stdio.h",
    "23.count_digit_one.c": "stdio.h",
    "24.reorder_odd_even.c": "stdio.h",
    "24.reorder_array.c": "stdio.h",
    "25.longest_unique_substring.c": "stdio.h, string.h",
    "25.longest_substring_no_repeat.c": "stdio.h, string.h",
    "26.perfect_numbers.c": "stdio.h, math.h",
    "26.perfect_number.c": "stdio.h, math.h",
    "27.min_subarray_sum.c": "stdio.h",
    "28.jump_game.c": "stdio.h",
    "29.array_rotate_right.c": "stdio.h",
    "29.array_right_rotate.c": "stdio.h",
    "30.string_elimination.c": "stdio.h, string.h",
    "31.prime_factorization.c": "stdio.h, math.h",
    "32.sum_of_aaa.c": "stdio.h",
    "33.string_deformation.c": "stdio.h, string.h",
    "34.count_binary_substrings.c": "stdio.h, string.h",
    "35.subset_sum_count.c": "stdio.h",
    "36.amicable_numbers.c": "stdio.h, math.h",
    "37.is_subsequence.c": "stdio.h, string.h",
    "38.most_frequent_digit.c": "stdio.h",
    "39.prime_range.c": "stdio.h, math.h",
    "40.isomorphic_strings.c": "stdio.h, string.h",
    "41.first_missing_positive.c": "stdio.h",
    "42.palindrome_primes.c": "stdio.h, math.h",
    "43.linked_list_cycle.c": "stdio.h",
    "44.string_multiply.c": "stdio.h, string.h",
    "45.ip_addresses.c": "stdio.h, string.h",
    "46.reverse_linked_list_range.c": "stdio.h",
    "47.remove_duplicates.c": "stdio.h",
    "48.find_median_sorted_arrays.c": "stdio.h",
    "49.valid_ip_address.c": "stdio.h, string.h",
    "50.odd_even_linked_list.c": "stdio.h",
    "51.find_kth_largest.c": "stdio.h, stdlib.h",
    "52.first_missing_positive_2.c": "stdio.h, stdlib.h",
    "53.longest_common_substring.c": "stdio.h, string.h",
    "54.string_addition.c": "stdio.h, string.h",
    "54.string_add.c": "stdio.h, string.h",
    "55.factorial_trailing_zeros.c": "stdio.h",
    "55.trailing_zeros.c": "stdio.h",
    "56.binary_addition.c": "stdio.h, string.h",
    "56.binary_add.c": "stdio.h, string.h",
    "57.sum_1_to_n.c": "stdio.h",
    "57.sum_without_operators.c": "stdio.h",
    "58.letter_combinations.c": "stdio.h, string.h",
    "59.chinese_number.c": "stdio.h, string.h",
    "60.max_xor.c": "stdio.h, stdlib.h",
    "61.partition_k_subsets.c": "stdio.h",
    "62.calculator.c": "stdio.h, string.h",
    "63.generate_parentheses.c": "stdio.h, string.h",
    "64.merge_intervals.c": "stdio.h, stdlib.h",
    "65.add_two_numbers.c": "stdio.h",
    "66.ugly_number.c": "stdio.h",
    "67.max_product_subarray.c": "stdio.h",
    "68.egg_drop.c": "stdio.h",
    "69.array_cyclic_shift.c": "stdio.h",
    "70.integer_partition.c": "stdio.h"
}

# 读取文件内容
def read_file(file_path):
    with open(file_path, 'r', encoding='utf-8') as f:
        return f.read()

# 写入文件内容
def write_file(file_path, content):
    with open(file_path, 'w', encoding='utf-8') as f:
        f.write(content)

# 提取文件内容（去除旧文件头）
def extract_content(file_content):
    # 查找文件头结束位置
    header_end = file_content.find('*/')
    if header_end != -1:
        return file_content[header_end + 2:].lstrip()
    return file_content

# 生成文件头
def generate_header(file_name):
    file_basename = os.path.basename(file_name)
    desc = descriptions.get(file_basename, "功能描述")
    algo = algorithms.get(file_basename, "算法描述")
    scen = scenarios.get(file_basename, "适用场景")
    deps = dependencies.get(file_basename, "stdio.h")
    
    # 处理适用场景的换行
    scen_lines = scen.split('、')
    scen_formatted = "\n *   - ".join(scen_lines)
    
    return HEADER_TEMPLATE.format(
        file_name=file_basename,
        dependencies=deps,
        description=desc,
        algorithm=algo,
        scenario=scen_formatted
    )

# 更新文件头
def update_file_header(file_path):
    try:
        content = read_file(file_path)
        # 提取文件内容（去除旧文件头）
        new_content = extract_content(content)
        # 生成新文件头
        header = generate_header(file_path)
        # 组合新文件内容
        updated_content = header + new_content
        # 写入文件
        write_file(file_path, updated_content)
        print(f"[OK] 更新文件头: {os.path.basename(file_path)}")
    except Exception as e:
        print(f"[ERROR] 错误更新文件头 {os.path.basename(file_path)}: {e}")

# 主函数
def main():
    src_dir = "src"
    if not os.path.exists(src_dir):
        print("错误: src 目录不存在")
        return
    
    # 获取所有 .c 文件
    c_files = [f for f in os.listdir(src_dir) if f.endswith('.c')]
    
    print(f"找到 {len(c_files)} 个 .c 文件")
    print("开始更新文件头...")
    
    for c_file in c_files:
        file_path = os.path.join(src_dir, c_file)
        update_file_header(file_path)
    
    print("文件头更新完成！")

if __name__ == "__main__":
    main()
