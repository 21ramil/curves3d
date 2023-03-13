@echo off

:: Set build path
set ROOT_PATH="%~dp0"
set BUILD_PATH="%ROOT_PATH%build\"

:: Remove previous cmake build
if exist %BUILD_PATH% rmdir /s /q %BUILD_PATH% 

mkdir %BUILD_PATH% && cd %BUILD_PATH% 
cmake -G "Visual Studio 16 2019" -DBUILD_SHARED_LIBS=ON -DCMAKE_INSTALL_PREFIX=./install -DCMAKE_BUILD_TYPE=Release ../ 
cmake --build . --config Release
cmake --install . --config Release
pause