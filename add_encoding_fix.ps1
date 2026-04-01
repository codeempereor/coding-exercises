# 批处理脚本：为所有.c文件添加编码格式处理代码

# 定义源目录
$srcDir = "F:\myproject\coding-exercises\src"

# 获取所有.c文件
$cFiles = Get-ChildItem -Path $srcDir -Filter "*.c" -Recurse

# 遍历每个文件
foreach ($file in $cFiles) {
    Write-Host "处理文件: $($file.Name)"
    
    # 读取文件内容
    $content = Get-Content -Path $file.FullName -Encoding UTF8
    $contentStr = $content -join "`n"
    
    # 检查是否已经包含windows.h
    if (-not ($contentStr -contains "#include <windows.h>")) {
        # 找到第一个#include语句的位置
        $includePos = $contentStr.IndexOf("#include")
        
        if ($includePos -ge 0) {
            # 找到该行的结束位置
            $lineEnd = $contentStr.IndexOf("`n", $includePos)
            if ($lineEnd -lt 0) {
                $lineEnd = $contentStr.Length
            }
            
            # 插入windows.h包含
            $newContent = $contentStr.Substring(0, $lineEnd) + "`n#ifdef _WIN32`n#include <windows.h>`n#endif" + $contentStr.Substring($lineEnd)
            
            # 找到main函数
            $mainPos = $newContent.IndexOf("int main()")
            
            if ($mainPos -ge 0) {
                # 找到左大括号
                $bracePos = $newContent.IndexOf("{", $mainPos)
                
                if ($bracePos -ge 0) {
                    # 插入编码设置
                    $finalContent = $newContent.Substring(0, $bracePos + 1) + "`n    #ifdef _WIN32`n    // 设置控制台输出为UTF-8`n    SetConsoleOutputCP(CP_UTF8);`n    #endif" + $newContent.Substring($bracePos + 1)
                    
                    # 保存文件
                    $finalContent | Set-Content -Path $file.FullName -Encoding UTF8
                    Write-Host "  已添加编码处理代码"
                }
            }
        }
    } else {
        Write-Host "  文件已包含windows.h"
    }
}

Write-Host "处理完成！"
