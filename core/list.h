//------------------------------------------------------------------------------
// 헤더 파일 목록.
//------------------------------------------------------------------------------
#pragma once
#include "core.h"


//------------------------------------------------------------------------------
// 노드.
//------------------------------------------------------------------------------
struct __node__ {
	struct __node__* previous;
	struct __node__* next;
	unknown_instance data;
};


//------------------------------------------------------------------------------
// 형식 재정의.
//------------------------------------------------------------------------------
typedef struct __node__ node;
typedef struct __node__* node_instance;
typedef struct __node__** node_instance_ptr;


//------------------------------------------------------------------------------
// 리스트.
//------------------------------------------------------------------------------
struct __list__ {
	node_instance head;
	node_instance tail;
};


//------------------------------------------------------------------------------
// 형식 재정의.
//------------------------------------------------------------------------------
typedef struct __list__ list;
typedef struct __list__* list_instance;
typedef struct __list__** list_instance_ptr;


//------------------------------------------------------------------------------
// 리스트 함수 목록.
//------------------------------------------------------------------------------
list_instance list_create();
void list_destroy(list_instance_ptr instance_ptr);
void list_add(list_instance instance, unknown_instance value);
void list_remove(list_instance instance, unknown_instance value);
void list_set_value(list_instance instance, uint32_t index, unknown_instance value);
unknown_instance list_get_value(list_instance instance, uint32_t index);
int32_t list_index_of(list_instance instance, unknown_instance element);