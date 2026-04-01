#!/usr/bin/env python3
# 批处理脚本：为所有.c文件添加编码格式处理代码

import os

# 定义源目录
src_dir = "F:\myproject\coding-exercises\src"

# 遍历所有.c文件
for root, dirs, files in os.walk(src_dir):
    for file in files:
        if file.endswith(".c"):
            file_path = os.path.join(root, file)
            print(f"处理文件: {file}")
            
            # 读取文件内容
            with open(file_path, 'r', encoding='utf-8') as f:
                content = f.read()
            
            # 检查是否已经包含windows.h
            if "#include <windows.h>" not in content:
                # 找到第一个#include语句
                include_pos = content.find("#include")
                
                if include_pos != -1:
                    # 找到该行的结束位置
                    line_end = content.find("\n", include_pos)
                    if line_end == -1:
                        line_end = len(content)
                    
                    # 插入windows.h包含
                    new_content = content[:line_end] + "\n#ifdef _WIN32\n#include <windows.h>\n#endif" + content[line_end:]
                    
                    # 找到main函数
                    main_pos = new_content.find("int main()")
                    
                    if main_pos != -1:
                        # 找到左大括号
                        brace_pos = new_content.find("{", main_pos)
                        
                        if brace_pos != -1:
                            # 插入编码设置
                            final_content = new_content[:brace_pos + 1] + "\n    #ifdef _WIN32\n    // 设置控制台输出为UTF-8\n    SetConsoleOutputCP(CP_UTF8);\n    #endif" + new_content[brace_pos + 1:]
                            
                            # 保存文件
                            with open(file_path, 'w', encoding='utf-8') as f:
                                f.write(final_content)
                            print("  已添加编码处理代码")
            else:
                print("  文件已包含windows.h")

print("处理完成！")
