//------------------------------------------------------------------------------
// ��� ���� ���.
//------------------------------------------------------------------------------
#pragma once
#include <stdint.h> // uint32_t


struct __object__ {
	uint32_t unique_id;
};


typedef struct __object__ object;
typedef struct __object__* object_instance;
typedef struct __object__** object_instance_ptr;