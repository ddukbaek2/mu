cmake_minimum_required (VERSION 3.12)

if (POLICY CMP0141)
    cmake_policy (SET CMP0141 NEW)

    if (CMAKE_C_COMPILER_ID STREQUAL "MSVC" AND CMAKE_BUILD_TYPE STREQUAL "Debug")
        if (CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
            set (CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "EditAndContinue")
        else()
            set (CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "ProgramDatabase")
        endif()
    else()
        set (CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "ProgramDatabase")
    endif()
endif()

project ("mu" C)
add_subdirectory ("runtime")