//------------------------------------------------------------------------------
// 헤더 파일 목록.
//------------------------------------------------------------------------------
#pragma once
#include "cxl_type.h"


//------------------------------------------------------------------------------
// 함수 목록.
//------------------------------------------------------------------------------
cxl_array cxl_array_create(size_t capacity);
void cxl_array_destroy(cxl_array* array);
void cxl_array_resize(cxl_array array, size_t capacity);
void cxl_array_add(cxl_array array, object obj);
object cxl_array_remove(cxl_array array, size_t index);
void cxl_array_set(cxl_array array, size_t index, object obj);
object cxl_array_get(cxl_array array, size_t index);