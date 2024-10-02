//------------------------------------------------------------------------------
// 헤더 파일 목록.
//------------------------------------------------------------------------------
#pragma once
#include "cxl_type.h"


//------------------------------------------------------------------------------
// 함수 목록.
//------------------------------------------------------------------------------
cxl_bytes cxl_bytes_create(size_t capacity);
void cxl_bytes_destroy(cxl_bytes* bytes);
void cxl_bytes_resize(cxl_bytes bytes, size_t capacity);
void cxl_bytes_add(cxl_bytes bytes, object obj);
object cxl_bytes_remove(cxl_bytes bytes, size_t index);
void cxl_bytes_set(cxl_bytes bytes, size_t index, object obj);
object cxl_bytes_get(cxl_bytes bytes, size_t index);