//------------------------------------------------------------------------------
// 헤더 파일 목록.
//------------------------------------------------------------------------------
#pragma once
#include <stdint.h> // size_t, uint8_t, int32_t, uint32_t


//------------------------------------------------------------------------------
// 형식 재정의.
//------------------------------------------------------------------------------
typedef void* object;
typedef uint8_t* bytes;
struct __cxl_bytes__;
typedef struct __cxl_bytes__* cxl_bytes;
struct __cxl_array__;
typedef struct __cxl_array__* cxl_array;
struct __cxl_string__;
typedef struct __cxl_string__* cxl_string;
struct __cxl_number__;
typedef struct __cxl_number__* cxl_number;