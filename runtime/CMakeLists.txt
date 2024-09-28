# 프로젝트 설정.
project(runtime)

# 실행 파일 생성.
file(GLOB RUNTIME_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.c")
add_executable (runtime ${RUNTIME_SOURCES})

# 정적 라이브러리 링크.
target_link_libraries(runtime PRIVATE core)

# 추가된 소스에 버전 설정.
if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET runtime PROPERTY C_STANDARD 17)
endif()