//------------------------------------------------------------------------------
// 헤더 파일 목록.
//------------------------------------------------------------------------------
#pragma once
#include "core.h"


//------------------------------------------------------------------------------
// 벡터.
//------------------------------------------------------------------------------
struct __vector__ {
	size_t size;
	size_t capacity;
	size_t element_size;

	unknown_instance data;	
};


//------------------------------------------------------------------------------
// 형식 재정의.
//------------------------------------------------------------------------------
typedef struct __vector__ vector;
typedef struct __vector__* vector_instance;
typedef struct __vector__** vector_instance_ptr;


//------------------------------------------------------------------------------
// 벡터 함수 목록.
//------------------------------------------------------------------------------
vector_instance vector_create();
void vector_destroy(vector_instance_ptr instance_ptr);
void vector_resize(vector_instance instance, size_t new_capacity);

void vector_pushback(vector_instance instance, unknown_instance value);
void vector_popback(vector_instance instance);

void vector_add(vector_instance instance, unknown_instance value);
void vector_insert(vector_instance instance, uint32_t index, unknown_instance value);
void vector_remove(vector_instance instance, unknown_instance value);
void vector_remove_at(vector_instance instance, uint32_t index);
void vector_set_value(vector_instance instance, uint32_t index, unknown_instance value);
unknown_instance vector_get_value(vector_instance instance, uint32_t index);
int32_t vector_index_of(vector_instance instance, unknown_instance value);
size_t vector_size_of(vector_instance instance);
size_t vector_capacity_of(vector_instance instance);