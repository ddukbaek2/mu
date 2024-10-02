//------------------------------------------------------------------------------
// ��� ���� ���.
//------------------------------------------------------------------------------
//#include <stdio.h> // fprintf, stderr
#include <stdlib.h> // malloc, realloc, free
#include <string.h> // memmove
#include "cxl_number.h"
#include "cxl_bytes.h"


//------------------------------------------------------------------------------
// ����.
//------------------------------------------------------------------------------
struct __cxl_number__ {
	cxl_bytes value;
};


cxl_number cxl_number_create() {
	size_t object_size = sizeof(struct __cxl_number__);
	cxl_number number = malloc(object_size);
	if (number) {
		number->value = cxl_byte_create(1);
	}

	return number;
}


//------------------------------------------------------------------------------
// �ı�.
//------------------------------------------------------------------------------
void cxl_number_destroy(cxl_number* numberReference) {
	if (numberReference && *numberReference) {
		cxl_number number = *numberReference;
		cxl_bytes_destroy(&number->value);
		free(*numberReference);
		*numberReference = NULL;
	}
}