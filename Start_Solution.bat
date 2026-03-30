
set WORK_DIR=%~dp0
set DEPENDENCY=%WORK_DIR%dependency\
set LIB_DIR=%WORK_DIR%lib\
set OUT_DIR=%WORK_DIR%bin\
set MID_DIR=%WORK_DIR%build\
set SOURCE_DIR=%WORK_DIR%source\

set INCLUDE_DIR=%SOURCE_DIR%;%DEPENDENCY%Acis\include\;
set LIBRARY_DIR_Release=%LIB_DIR%Release\;
set LIBRARY_DIR_Debug=%LIB_DIR%Debug\;
set Acis_LIB_DIR_Debug=%DEPENDENCY%Acis\NT_DLLD;
set Acis_LIB_DIR_Release=%DEPENDENCY%Acis\NT_DLL;

set VS2022_EXE="D:\VisualStudio2022\VS2022\Common7\IDE\devenv.exe"
start %VS2022_EXE% %WORK_DIR%\libTest.sln



