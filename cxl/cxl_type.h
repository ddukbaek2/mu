//------------------------------------------------------------------------------
// 헤더 파일 목록.
//------------------------------------------------------------------------------
#pragma once
#include <stdint.h> // int32_t, uint32_t, size_t


//------------------------------------------------------------------------------
// 형식 재정의.
//------------------------------------------------------------------------------
typedef void* object;
struct __cxl_bytes__;
typedef struct __cxl_bytes__* cxl_bytes;
struct __cxl_array__;
typedef struct __cxl_array__* cxl_array;
struct __cxl_string__;
typedef struct __cxl_string__* cxl_string;
struct __cxl_number__;
typedef struct __cxl_number__* cxl_number;