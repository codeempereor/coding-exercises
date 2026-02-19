@echo off
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
cl.exe /nologo brother_string.c /Fe:brother_string.exe
