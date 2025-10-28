@echo off
echo Compiling project...
g++ main.cpp Book.cpp Library.cpp -o library_app.exe
if %errorlevel%==0 (
    echo Build successful ✅
    echo Running program...
    library_app.exe
) else (
    echo Build failed ❌
)
pause