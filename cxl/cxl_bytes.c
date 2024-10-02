//------------------------------------------------------------------------------
// ��� ���� ���.
//------------------------------------------------------------------------------
//#include <stdio.h> // fprintf, stderr
#include <stdlib.h> // malloc, realloc, free
#include <string.h> // memmove
#include <stdint.h> // size_t, uint8_t
#include "cxl_bytes.h"


//------------------------------------------------------------------------------
// ��������Ʈ�迭.
//------------------------------------------------------------------------------
struct __cxl_bytes__ {
	uint8_t* begin;
	size_t capacity;
	size_t size;
};


//------------------------------------------------------------------------------
// ����.
//------------------------------------------------------------------------------
cxl_bytes cxl_bytes_create(size_t capacity) {
	if (capacity < 1)
		capacity = 1;

	size_t object_size = sizeof(struct __cxl_bytes__);
	cxl_bytes bytes = malloc(object_size);
	if (bytes) {
		size_t element_size = sizeof(object);
		bytes->begin = malloc(element_size * capacity);
		bytes->capacity = capacity;
		bytes->size = 0;
	}
	return bytes;
}


//------------------------------------------------------------------------------
// �ı�.
//------------------------------------------------------------------------------
void cxl_bytes_destroy(cxl_bytes* bytes) {
	if (bytes && *bytes) {
		if ((*bytes)->begin) {
			free((*bytes)->begin);
		}
		free(*bytes);
		(*bytes) = NULL;
	}
}


//------------------------------------------------------------------------------
// �޸� �Ҵ緮 ������.
//------------------------------------------------------------------------------
void cxl_bytes_resize(cxl_bytes bytes, size_t capacity) {
	object* new_items = realloc(bytes->begin, sizeof(object) * capacity);
	if (new_items) {
		bytes->begin = new_items;
		bytes->capacity = capacity;
	}
}


//------------------------------------------------------------------------------
// ��� �߰�.
//------------------------------------------------------------------------------
void cxl_bytes_add(cxl_bytes bytes, object item) {
	if (bytes->size == bytes->capacity) {
		cxl_bytes_resize(bytes, bytes->capacity * 2);
	}
	bytes->begin[bytes->size++] = item;
}


//------------------------------------------------------------------------------
// ��� ����.
//------------------------------------------------------------------------------
object cxl_bytes_remove(cxl_bytes bytes, size_t index) {
	object obj = cxl_bytes_get(bytes, index);
	if (obj) {
		memmove(&bytes->begin[index], &bytes->begin[index + 1],
			(bytes->size - index - 1) * sizeof(void*));
		bytes->size--;
		return obj;
	}

	return NULL;
}


//------------------------------------------------------------------------------
// ��� ����.
//------------------------------------------------------------------------------
void cxl_bytes_set(cxl_bytes bytes, size_t index, object item) {
	if (index >= bytes->size) {
		//fprintf(stderr, "index out of bounds\n");
		return;
	}
	bytes->begin[index] = item;
}


//------------------------------------------------------------------------------
// ��� ��ȯ.
//------------------------------------------------------------------------------
object cxl_bytes_get(cxl_bytes bytes, size_t index) {
	if (index >= bytes->size) {
		return NULL;
	}
	return bytes->begin[index];
}