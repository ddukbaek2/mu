# 소스 추가.
add_executable (runtime "runtime.c" "runtime.h")

# 추가된 소스에 버전 설정.
if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET runtime PROPERTY C_STANDARD 17)
endif()