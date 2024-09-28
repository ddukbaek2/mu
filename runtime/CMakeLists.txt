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
target_link_libraries(runtime PRIVATE core)
target_link_libraries(runtime PRIVATE mulang)

# 추가된 소스에 버전 설정.
if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET runtime PROPERTY C_STANDARD 17)
endif()