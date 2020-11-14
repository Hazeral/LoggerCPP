:: Copyright(c) 2020-present, Muhammad Usman. (https://github.com/Hazeral)
:: Distributed under the MIT License (http://opensource.org/licenses/MIT)
@echo off
set start=%time%

echo Creating directories
if not exist "bin\dll\objects" mkdir "bin\dll\objects"

echo Compiling Logger.cpp to object code
g++ -c -o bin\dll\objects\Logger.o src\Logger.cpp -DHXZ_LOGGER_BUILD_DLL
echo Compiling Colour.cpp to object code
g++ -c -o bin\dll\objects\Colour.o src\Colour.cpp
echo Compiling Time.cpp to object code
g++ -c -o bin\dll\objects\Time.o src\Time.cpp
echo Compiling FileOutput.cpp to object code
g++ -c -o bin\dll\objects\FileOutput.o src\FileOutput.cpp -std=c++17

echo Building shared library
g++ -shared -o bin\dll\Logger.dll bin\dll\objects\Logger.o bin\dll\objects\Colour.o bin\dll\objects\Time.o bin\dll\objects\FileOutput.o

echo Copying header to dll location
copy ".\src\Logger.h" "bin\dll" >nul

:: TIME MEASUREMENT
set end=%time%
set options="tokens=1-4 delims=:.,"
for /f %options% %%a in ("%start%") do set start_h=%%a&set /a start_m=100%%b %% 100&set /a start_s=100%%c %% 100&set /a start_ms=100%%d %% 100
for /f %options% %%a in ("%end%") do set end_h=%%a&set /a end_m=100%%b %% 100&set /a end_s=100%%c %% 100&set /a end_ms=100%%d %% 100

set /a hours=%end_h%-%start_h%
set /a mins=%end_m%-%start_m%
set /a secs=%end_s%-%start_s%
set /a ms=%end_ms%-%start_ms%
if %ms% lss 0 set /a secs = %secs% - 1 & set /a ms = 100%ms%
if %secs% lss 0 set /a mins = %mins% - 1 & set /a secs = 60%secs%
if %mins% lss 0 set /a hours = %hours% - 1 & set /a mins = 60%mins%
if %hours% lss 0 set /a hours = 24%hours%
if 1%ms% lss 100 set ms=0%ms%
set /a totalsecs = %hours%*3600 + %mins%*60 + %secs%
:: ----------------

echo Finished compiling in %totalsecs%.%ms% seconds