//------------------------------------------------------------------------------
// ��� ���� ���.
//------------------------------------------------------------------------------
#include <stdlib.h> // malloc, realloc, free, size_t
#include <stdint.h> // size_t
#include <string.h> // memcpy
#include "vector.h"


//------------------------------------------------------------------------------
// ���� ���.
//------------------------------------------------------------------------------
#define VECTOR_DEFAULT_CAPACITY 4


//------------------------------------------------------------------------------
// ���� ����.
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
// ���� �ı�.
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
// ���� ũ�� ����.
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
// ���� �� �ڿ� ��� �߰�.
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
// ���� �� �� ��� ����.
//------------------------------------------------------------------------------
void vector_popback(vector_instance instance) {
	if (instance != NULL) {
		instance->size--;
	}
}


//------------------------------------------------------------------------------
// ���� ��� �߰�.
//------------------------------------------------------------------------------
void vector_add(vector_instance instance, unknown_instance value) {

}


//------------------------------------------------------------------------------
// ���� ��� �߰�.
//------------------------------------------------------------------------------
void vector_insert(vector_instance instance, uint32_t index, unknown_instance value) {

}


//------------------------------------------------------------------------------
// ���� ��� ����.
//------------------------------------------------------------------------------
void vector_remove(vector_instance instance, unknown_instance value) {

}

//------------------------------------------------------------------------------
// ���� ��� ����.
//------------------------------------------------------------------------------
void vector_remove_at(vector_instance instance, uint32_t index) {

}


//------------------------------------------------------------------------------
// ���� ��� �缳��.
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
// ���� ��� ��ȯ.
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
// ���� ����� ��ġ ��ȯ.
//------------------------------------------------------------------------------
int32_t vector_index_of(vector_instance instance, unknown_instance value) {
	return 0;
}


//------------------------------------------------------------------------------
// ������ ũ�� ��ȯ.
//------------------------------------------------------------------------------
size_t vector_size_of(vector_instance instance) {
	if (instance != NULL) {
		return instance->size;
	}
	return 0;
}


//------------------------------------------------------------------------------
// ������ �Ҵ緮 ��ȯ.
//------------------------------------------------------------------------------
size_t vector_capacity_of(vector_instance instance) {
	if (instance != NULL) {
		return instance->capacity;
	}
	return 0;
}