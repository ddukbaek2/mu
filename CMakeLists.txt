# 최소 요구 CMAKE 버전 설정.
cmake_minimum_required (VERSION 3.12)

# 비주얼스튜디오 디버깅 설정.
if (POLICY CMP0141)
    cmake_policy (SET CMP0141 NEW)
    if (CMAKE_C_COMPILER_ID STREQUAL "MSVC" AND CMAKE_BUILD_TYPE STREQUAL "Debug")
        if (CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
            set (CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "EditAndContinue")
        else()
            set (CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "ProgramDatabase") # PDB
        endif()
    else()
        set (CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "ProgramDatabase") # PDB
    endif()
endif()

# 프로젝트 설정.
project ("mu" C)

# 서브 프로젝트 설정.
add_subdirectory ("core")
add_subdirectory ("mulang")
add_subdirectory ("runtime")

