# 최소 요구 CMAKE 버전 설정.
cmake_minimum_required (VERSION 3.12)

# 프로젝트 설정.
project(runtime)

# 플랫폼 별 분기.
if (WIN32)
	message("Building for Windows")
 	set(PLATFORM_NAME "windows")
elseif (APPLE)
	 message("Building for macOS")
	 set(PLATFORM_NAME "macos")
elseif (UNIX)
	message("Building for Linux")
	set(PLATFORM_NAME "linux")
else ()
	message(FATAL_ERROR "Unsupported platform")
endif()

# 실행 파일 생성.
file(GLOB RUNTIME_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.c")
add_executable (runtime ${RUNTIME_SOURCES})

# 정적 라이브러리 링크.
target_link_libraries(runtime PRIVATE cxl)
target_link_libraries(runtime PRIVATE mulang)

# 컴파일러 설정.
# Visual Studio.
if (MSVC)
	# 신기하게도 한글 깨짐.
	# setlocale(LC_ALL, ".UTF-8") 사용해야 문제 없어짐.
	target_compile_options(runtime PRIVATE /utf-8)
	# 한글 안깨짐.
	# 하지만 bom 없는 utf8이 일반적이므로 사용하는게 문제가 될 수 있음.
	# target_compile_options(runtime PRIVATE /utf-8BOM)
# GCC or CLANG.
else ()
	target_compile_options(runtime PRIVATE -finput-charset=UTF-8 -fexec-charset=UTF-8)
endif()

# 추가된 소스에 버전 설정.
if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET runtime PROPERTY C_STANDARD 17)
endif()
