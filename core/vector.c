//------------------------------------------------------------------------------
// 헤더 파일 목록.
//------------------------------------------------------------------------------
#include <stdlib.h> // malloc, realloc, free, size_t
#include <stdint.h> // size_t
#include <string.h> // memcpy
#include "vector.h"


//------------------------------------------------------------------------------
// 정의 목록.
//------------------------------------------------------------------------------
#define VECTOR_DEFAULT_CAPACITY 4


//------------------------------------------------------------------------------
// 벡터 생성.
//------------------------------------------------------------------------------
vector_instance vector_create() {
	vector_instance instance = (vector_instance)malloc(sizeof(vector));
	if (instance != NULL) {
		instance->element_size = pointer_size_of();
		instance->data = (unknown_instance)malloc(instance->element_size * VECTOR_DEFAULT_CAPACITY);
		instance->size = 0;
		instance->capacity = VECTOR_DEFAULT_CAPACITY;
	}

	return instance;
}


//------------------------------------------------------------------------------
// 벡터 파괴.
//------------------------------------------------------------------------------
void vector_destroy(vector_instance_ptr instance_ptr) {
	if (instance_ptr == NULL)
		return;

	vector_instance instance = (vector_instance)(*instance_ptr);
	if (instance != NULL) {
		free(instance);
		instance = NULL;
		*instance_ptr = NULL;
	}
}


//------------------------------------------------------------------------------
// 벡터 크기 조정.
//------------------------------------------------------------------------------
void vector_resize(vector_instance instance, size_t new_capacity) {
	if (instance != NULL) {
		instance->capacity = new_capacity;
		if (instance->data != NULL) {
			instance->data = (unknown_instance)realloc(instance->data, instance->capacity * instance->element_size);
		}
	}
}


//------------------------------------------------------------------------------
// 벡터 맨 뒤에 요소 추가.
//------------------------------------------------------------------------------
void vector_pushback(vector_instance instance, unknown_instance value) {
	if (instance != NULL) {
		if (instance->size >= instance->capacity) {
			vector_resize(instance, instance->capacity * 2);
		}
		unknown_instance target = (char*)instance->data + (instance->size * instance->element_size);
		memcpy(target, value, instance->element_size);
		instance->size++;
	}
}


//------------------------------------------------------------------------------
// 벡터 맨 뒤 요소 제거.
//------------------------------------------------------------------------------
void vector_popback(vector_instance instance) {
	if (instance != NULL) {
		instance->size--;
	}
}


//------------------------------------------------------------------------------
// 벡터 요소 추가.
//------------------------------------------------------------------------------
void vector_add(vector_instance instance, unknown_instance value) {

}


//------------------------------------------------------------------------------
// 벡터 요소 추가.
//------------------------------------------------------------------------------
void vector_insert(vector_instance instance, uint32_t index, unknown_instance value) {

}


//------------------------------------------------------------------------------
// 벡터 요소 제거.
//------------------------------------------------------------------------------
void vector_remove(vector_instance instance, unknown_instance value) {

}

//------------------------------------------------------------------------------
// 벡터 요소 제거.
//------------------------------------------------------------------------------
void vector_remove_at(vector_instance instance, uint32_t index) {

}


//------------------------------------------------------------------------------
// 벡터 요소 재설정.
//------------------------------------------------------------------------------
void vector_set_value(vector_instance instance, uint32_t index, unknown_instance value) {
	if (instance != NULL) {
		if (index < instance->size) {
			unknown_instance target = (char*)instance->data + (index * instance->element_size);
			memcpy(target, value, instance->element_size);
		}
	}
}


//------------------------------------------------------------------------------
// 벡터 요소 반환.
//------------------------------------------------------------------------------
unknown_instance vector_get_value(vector_instance instance, uint32_t index) {
	if (instance != NULL) {
		if (index < instance->size) {
			unknown_instance value = malloc(instance->element_size);
			unknown_instance source = (char*)instance->data + (index * instance->element_size);
			if (value != NULL) {
				memcpy(value, source, instance->element_size);
				return value;
			}
		}
	}

	return NULL;
}


//------------------------------------------------------------------------------
// 벡터 요소의 위치 반환.
//------------------------------------------------------------------------------
int32_t vector_index_of(vector_instance instance, unknown_instance value) {
	return 0;
}


//------------------------------------------------------------------------------
// 벡터의 크기 반환.
//------------------------------------------------------------------------------
size_t vector_size_of(vector_instance instance) {
	if (instance != NULL) {
		return instance->size;
	}
	return 0;
}


//------------------------------------------------------------------------------
// 벡터의 할당량 반환.
//------------------------------------------------------------------------------
size_t vector_capacity_of(vector_instance instance) {
	if (instance != NULL) {
		return instance->capacity;
	}
	return 0;
}



