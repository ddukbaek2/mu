# 프로젝트 설정.
project(core)

# 정적 라이브러리 생성.
file(GLOB CORE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.c")
add_library (core STATIC ${CORE_SOURCES})

# 헤더파일 경로 공개.
# 다른 형제 프로젝트에서 헤더 파일 사용 가능.
target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# 정적 라이브러리 프로퍼티 설정.
if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET core PROPERTY C_STANDARD 17)
endif()