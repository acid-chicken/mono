:: Set up VS MSVC environment depending on installed VS versions.
:: Script will setup environment variables directly in callers environment.

:: Make sure we can restore current working directory after setting up environment.
:: Some of the VS scripts can change the current working directory.
set CALLER_WD=%CD%

:: Get path for current running script.
set RUN_SETUP_VS_MSVCBUILD_ENV_SCRIPT_PATH=%~dp0

:: NOTE, MSVC build Mono full AOT tooling currently support 64-bit AMD codegen. Below will only setup
:: amd64 versions of VS MSVC build environment and corresponding Clang compiler.
set VS_2015_TOOLCHAIN_ARCH=amd64
set VS_2015_VCVARS_ARCH=%VS_2015_TOOLCHAIN_ARCH%\vcvars64.bat
set VS_2015_CLANG_ARCH=%VS_2015_TOOLCHAIN_ARCH%
set VS_2017_VCVARS_ARCH=vcvars64.bat
set VS_2017_CLANG_ARCH=HostX64
set VS_2019_VCVARS_ARCH=%VS_2017_VCVARS_ARCH%

:: 32-bit AOT toolchains for MSVC build mono-sgen.exe is currently not supported.
:: set VS_2015_TOOLCHAIN_ARCH=x86
:: set VS_2015_VCVARS_ARCH=vcvars32.bat
:: set VS_2015_CLANG_ARCH=%VS_2015_TOOLCHAIN_ARCH%
:: set VS_2017_VCVARS_ARCH=vcvars32.bat
:: set VS_2017_CLANG_ARCH=HostX86
:: set VS_2019_VCVARS_ARCH=%VS_2017_VCVARS_ARCH%

set VS_CLANG_TOOLS_BIN_PATH=

:: VS2019/VS2017 includes vswhere.exe that can be used to locate current VS installation.
set VSWHERE_TOOLS_BIN=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe

:: Visual Studio 2015 == 14.0
if "%VisualStudioVersion%" == "14.0" (
    goto SETUP_VS_2015
)

:: Visual Studio 2017 == 15.0
if "%VisualStudioVersion%" == "15.0" (
    goto SETUP_VS_2017
)

:: Visual Studio 2019 == 16.0
if "%VisualStudioVersion%" == "16.0" (
    goto SETUP_VS_2019
)

:SETUP_VS_2019

set VS_2019_VCINSTALL_DIR=

:: Try to locate installed VS2019 VC environment.
if exist "%VSWHERE_TOOLS_BIN%" (
    for /f "tokens=*" %%a in ('"%VSWHERE_TOOLS_BIN%" -version [16.0^,17.0] -property installationPath') do (
        set VS_2019_VCINSTALL_DIR=%%a\VC\
    )
)

:: Try to locate installed VS2019 Clang.
set VS_2019_CLANG_TOOLS_BIN_PATH=%VS_2019_VCINSTALL_DIR%Tools\llvm\bin\
set VS_2019_CLANG_TOOLS_BIN=%VS_2019_CLANG_TOOLS_BIN_PATH%clang.exe
if not exist "%VS_2019_CLANG_TOOLS_BIN%" (
	goto SETUP_VS_2017
)

:SETUP_VS_2019_BUILD_TOOLS

:: Try to locate VS2019 build tools installation.
set VS_2019_BUILD_TOOLS_INSTALL_DIR=%ProgramFiles(x86)%\Microsoft Visual Studio\2019\BuildTools\
set VS_2019_BUILD_TOOLS_CMD=%VS_2019_BUILD_TOOLS_INSTALL_DIR%VC\Auxiliary\Build\%VS_2019_VCVARS_ARCH%

:: Setup VS2019 VC development environment using build tools installation.
call :setup_build_env "%VS_2019_BUILD_TOOLS_CMD%" "" "%CALLER_WD%" && (
    set "VS_CLANG_TOOLS_BIN_PATH=%VS_2019_CLANG_TOOLS_BIN_PATH%"
    set VS_DEFAULT_PLATFORM_TOOL_SET=v142
    goto ON_EXIT
)

:SETUP_VS_2019_VC

:: Try to locate installed VS2019 VC environment.
set VS_2019_DEV_CMD=%VS_2019_VCINSTALL_DIR%Auxiliary\Build\%VS_2019_VCVARS_ARCH%

:: Setup VS2019 VC development environment using VS installation.
call :setup_build_env "%VS_2019_DEV_CMD%" "" "%CALLER_WD%" && (
    set "VS_CLANG_TOOLS_BIN_PATH=%VS_2017_CLANG_TOOLS_BIN_PATH%"
    set VS_DEFAULT_PLATFORM_TOOL_SET=v142
    goto ON_EXIT
)

:SETUP_VS_2017

set VS_2017_VCINSTALL_DIR=

:: Try to locate installed VS2017 VC environment.
if exist "%VSWHERE_TOOLS_BIN%" (
    for /f "tokens=*" %%a in ('"%VSWHERE_TOOLS_BIN%" -version [15.0^,16.0] -property installationPath') do (
        set VS_2017_VCINSTALL_DIR=%%a\VC\
    )
)

:: Try to locate installed VS2017 Clang.
SET VS_2017_CLANG_VERSION_FILE=%VS_2017_VCINSTALL_DIR%Auxiliary/Build/Microsoft.ClangC2Version.default.txt
if not exist "%VS_2017_CLANG_VERSION_FILE%" (
	goto SETUP_VS_2015
)

set /p VS_2017_CLANG_VERSION=<"%VS_2017_CLANG_VERSION_FILE%"
set VS_2017_CLANG_TOOLS_BIN_PATH=%VS_2017_VCINSTALL_DIR%Tools\ClangC2\%VS_2017_CLANG_VERSION%\bin\%VS_2017_CLANG_ARCH%\
set VS_2017_CLANG_TOOLS_BIN=%VS_2017_CLANG_TOOLS_BIN_PATH%clang.exe
if not exist "%VS_2017_CLANG_TOOLS_BIN%" (
	goto SETUP_VS_2015
)

:SETUP_VS_2017_BUILD_TOOLS

:: Try to locate VS2017 build tools installation.
set VS_2017_BUILD_TOOLS_INSTALL_DIR=%ProgramFiles(x86)%\Microsoft Visual Studio\2017\BuildTools\
set VS_2017_BUILD_TOOLS_CMD=%VS_2017_BUILD_TOOLS_INSTALL_DIR%VC\Auxiliary\Build\%VS_2017_VCVARS_ARCH%

:: Setup VS2017 VC development environment using build tools installation.
call :setup_build_env "%VS_2017_BUILD_TOOLS_CMD%" "" "%CALLER_WD%" && (
    set "VS_CLANG_TOOLS_BIN_PATH=%VS_2017_CLANG_TOOLS_BIN_PATH%"
    set VS_DEFAULT_PLATFORM_TOOL_SET=v141
    goto ON_EXIT
)

:SETUP_VS_2017_VC

:: Try to locate installed VS2017 VC environment.
set VS_2017_DEV_CMD=%VS_2017_VCINSTALL_DIR%Auxiliary\Build\%VS_2017_VCVARS_ARCH%

:: Setup VS2017 VC development environment using VS installation.
call :setup_build_env "%VS_2017_DEV_CMD%" "" "%CALLER_WD%" && (
    set "VS_CLANG_TOOLS_BIN_PATH=%VS_2017_CLANG_TOOLS_BIN_PATH%"
    set VS_DEFAULT_PLATFORM_TOOL_SET=v141
    goto ON_EXIT
)

:SETUP_VS_2015

set VS_2015_VCINSTALL_DIR=%ProgramFiles(x86)%\Microsoft Visual Studio 14.0\VC\

:: Try to locate installed VS2015 Clang.
SET VS_2015_CLANG_TOOLS_BIN_PATH=%VS_2015_VCINSTALL_DIR%ClangC2\bin\%VS_2015_CLANG_ARCH%\
SET VS_2015_CLANG_TOOLS_BIN=%VS_2015_CLANG_TOOLS_BIN_PATH%clang.exe

if not exist "%VS_2015_CLANG_TOOLS_BIN%" (
    goto ON_ENV_ERROR
)

:SETUP_VS_2015_BUILD_TOOLS

:: Try to locate VS2015 build tools installation.
set VS_2015_BUILD_TOOLS_INSTALL_DIR=%ProgramFiles(x86)%\Microsoft Visual C++ Build Tools\
set VS_2015_BUILD_TOOLS_CMD=%VS_2015_BUILD_TOOLS_INSTALL_DIR%vcbuildtools.bat

:: Setup VS2015 VC development environment using build tools installation.
call :setup_build_env "%VS_2015_BUILD_TOOLS_CMD%" "%VS_2015_TOOLCHAIN_ARCH%" "%CALLER_WD%" && (
    set "VS_CLANG_TOOLS_BIN_PATH=%VS_2015_CLANG_TOOLS_BIN_PATH%"
    set VS_DEFAULT_PLATFORM_TOOL_SET=v140
    goto ON_EXIT
)

:SETUP_VS_2015_VC

:: Try to locate installed VS2015 VC environment.
set VS_2015_DEV_CMD=%VS_2015_VCINSTALL_DIR%bin\%VS_2015_VCVARS_ARCH%

call :setup_build_env "%VS_2015_DEV_CMD%" "" "%CALLER_WD%" && (
    set "VS_CLANG_TOOLS_BIN_PATH=%VS_2015_CLANG_TOOLS_BIN_PATH%"
    set VS_DEFAULT_PLATFORM_TOOL_SET=v140
    goto ON_EXIT
)

:ON_ENV_ERROR

echo Warning, failed to setup VS build environment needed by VS tooling.
echo Incomplete build environment can cause build error's due to missing compiler,
echo linker and platform libraries.

exit /b 1

:ON_EXIT

:: Add Clang folders to PATH
set "PATH=%VS_CLANG_TOOLS_BIN_PATH%;%PATH%"

exit /b 0

:setup_build_env

:: Check if VS build environment script exists.
if not exist "%~1" (
    goto setup_build_env_error
)

:: Run VS build environment script.
call "%~1" %~2 > NUL

:: Restore callers working directory in case it has been changed by VS scripts.
cd /d "%~3"

goto setup_build_env_exit

:setup_build_env_error
exit /b 1

:setup_build_env_exit
goto :EOF
