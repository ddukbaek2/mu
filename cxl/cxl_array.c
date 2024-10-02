//------------------------------------------------------------------------------
// 헤더 파일 목록.
//------------------------------------------------------------------------------
//#include <stdio.h> // fprintf, stderr
#include <stdlib.h> // malloc, realloc, free
#include <string.h> // memmove
#include "cxl_array.h"


//------------------------------------------------------------------------------
// 동적배열.
//------------------------------------------------------------------------------
struct __cxl_array__ {
	object* begin;
	size_t capacity;
	size_t size;
};


//------------------------------------------------------------------------------
// 생성.
//------------------------------------------------------------------------------
cxl_array cxl_array_create(size_t capacity) {
	if (capacity < 1)
		capacity = 1;

	size_t object_size = sizeof(struct __cxl_array__);
	cxl_array array = malloc(object_size);
	if (array) {
		size_t element_size = sizeof(object);
		array->begin = malloc(element_size * capacity);
		array->capacity = capacity;
		array->size = 0;
	}
	return array;
}


//------------------------------------------------------------------------------
// 파괴.
//------------------------------------------------------------------------------
void cxl_array_destroy(cxl_array* array) {
	if (array && *array) {
		if ((*array)->begin) {
			free((*array)->begin);
		}
		free(*array);
		(*array) = NULL;
	}
}


//------------------------------------------------------------------------------
// 메모리 할당량 재조정.
//------------------------------------------------------------------------------
void cxl_array_resize(cxl_array array, size_t capacity) {
	object* new_items = realloc(array->begin, sizeof(object) * capacity);
	if (new_items) {
		array->begin = new_items;
		array->capacity = capacity;
	}
}


//------------------------------------------------------------------------------
// 요소 추가.
//------------------------------------------------------------------------------
void cxl_array_add(cxl_array array, object item) {
	if (array->size == array->capacity) {
		cxl_array_resize(array, array->capacity * 2);
	}
	array->begin[array->size++] = item;
}


//------------------------------------------------------------------------------
// 요소 제거.
//------------------------------------------------------------------------------
object cxl_array_remove(cxl_array array, size_t index) {
	object obj = cxl_array_get(array, index);
	if (obj) {
		memmove(&array->begin[index], &array->begin[index + 1],
			(array->size - index - 1) * sizeof(void*));
		array->size--;
		return obj;
	}

	return NULL;
}


//------------------------------------------------------------------------------
// 요소 설정.
//------------------------------------------------------------------------------
void cxl_array_set(cxl_array array, size_t index, object item) {
	if (index >= array->size) {
		//fprintf(stderr, "index out of bounds\n");
		return;
	}
	array->begin[index] = item;
}


//------------------------------------------------------------------------------
// 요소 반환.
//------------------------------------------------------------------------------
object cxl_array_get(cxl_array array, size_t index) {
	if (index >= array->size) {
		return NULL;
	}
	return array->begin[index];
}