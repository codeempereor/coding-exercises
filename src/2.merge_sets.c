/* =============================================================================
 * 项目名称: 编程练习题
 * 文件名称: 2.merge_sets.c
 * 作    者: 三道渊
 * 创建日期: 2026-04-15
 * 最后修改: 2026-04-15
 * 版    本: v1.0.0
 * 适用平台: Windows x64
 * 编译依赖: GCC 15.2.0, stdio.h
 * 功能描述:
 *   1. 合并集合
 * 算法描述:
 *   - 集合合并：使用哈希表存储集合元素，实现快速查找和合并
 * 适用场景:
 *   - 集合操作
 *   - 数据去重
 *   - 合并数据
 * 版权声明: © 2026 三道渊. All rights reserved.
 * 变更记录:
 *   - 2026-04-15 三道渊: 初始化文件
 * ============================================================================ */
#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif
#include <string.h>

#define MAX_N 100
#define MAX_STR_LEN 10

/**
 * @brief 并查集结构
 */
typedef struct UnionFind
{
    int parent[MAX_N];
    char elements[MAX_N][MAX_STR_LEN];
    int size;
} UnionFind;

/**
 * @brief 初始化并查集
 * @param uf 并查集指针
 */
void init_union_find(UnionFind *uf)
{
    uf->size = 0;
    for (int i = 0; i < MAX_N; i++)
    {
        uf->parent[i] = i;
        uf->elements[i][0] = '\0';
    }
}

/**
 * @brief 查找根节点
 * @param uf 并查集指针
 * @param x 元素索引
 * @return 根节点索引
 */
int find(UnionFind *uf, int x)
{
    if (uf->parent[x] != x)
    {
        uf->parent[x] = find(uf, uf->parent[x]);
    }
    return uf->parent[x];
}

/**
 * @brief 合并两个集合
 * @param uf 并查集指针
 * @param x 第一个元素索引
 * @param y 第二个元素索引
 */
void unite(UnionFind *uf, int x, int y)
{
    x = find(uf, x);
    y = find(uf, y);
    if (x != y)
    {
        uf->parent[y] = x;
    }
}

/**
 * @brief 查找元素在并查集中的索引
 * @param uf 并查集指针
 * @param str 元素字符串
 * @return 元素索引，-1表示未找到
 */
int find_element(UnionFind *uf, const char *str)
{
    for (int i = 0; i < uf->size; i++)
    {
        if (strcmp(uf->elements[i], str) == 0)
        {
            return i;
        }
    }
    return -1;
}

/**
 * @brief 添加元素到并查集
 * @param uf 并查集指针
 * @param str 元素字符串
 * @return 元素索引
 */
int add_element(UnionFind *uf, const char *str)
{
    int idx = find_element(uf, str);
    if (idx != -1)
    {
        return idx;
    }
    
    if (uf->size < MAX_N)
    {
        strcpy(uf->elements[uf->size], str);
        uf->parent[uf->size] = uf->size;
        return uf->size++;
    }
    return -1;
}

/**
 * @brief 合并集合
 * @return void
 */
, {bbb ddd}, {eee fff}, {ggg}, {ddd hhh}
    char sets[5][100] = 
    {
        "aaa bbb ccc",
        "bbb ddd",
        "eee fff",
        "ggg",
        "ddd hhh"
    };
    
    // 处理每个集合
    for (int i = 0; i < 5; i++)
{
        char *token = strtok(sets[i], " ");
        int first_idx = -1;
        
        while (token != NULL)
        {
            int idx = add_element(&uf, token);
            if (first_idx == -1)
            {
                first_idx = idx;
            }
            else
            {
                unite(&uf, first_idx, idx);
            }
            token = strtok(NULL, " ");
        }
    }
    
    // 收集合并后的集合
    int group[MAX_N] = {0};
    int group_count = 0;
    
    for (int i = 0; i < uf.size; i++)
    {
        int root = find(&uf, i);
        if (!group[root])
        {
            group[root] = 1;
            group_count++;
        }
    }
    
    // 输出合并后的集合
    printf("合并后的集合：\n");
    for (int i = 0; i < uf.size; i++)
    {
        int root = find(&uf, i);
        if (group[root])
        {
            group[root] = 0;
            printf("{");
            for (int j = 0; j < uf.size; j++)
            {
                if (find(&uf, j) == root)
                {
                    printf("%s ", uf.elements[j]);
                }
            }
            printf("}\n");
        }
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

printf("=== 合并集合 ===\n");
    
    UnionFind uf;
    init_union_find(&uf);
    
    // 测试用例：{aaa bbb ccc

return 0;
}
