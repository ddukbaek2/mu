//------------------------------------------------------------------------------
// 헤더 파일 목록.
//------------------------------------------------------------------------------
#pragma once
#include "cxl_type.h"
#include "cxl_bytes.h"
#include "cxl_array.h"
#include "cxl_string.h"

/*
*  Standard C17 Data Type:
*	- typedef void* cx_object
*	- typedef uint_8* cx_byte
* 
*  CX Data Value Type:
*	- cx_type
*	- cx_bytes
*	- cx_boolean
*	- cx_number
*	- cx_float
*	- cx_string
* 
*  CX Data Container Type:
*	- cx_list
*	- cx_dictionary
*	- cx_queue
*	- cx_stack
*	- cx_set
*
*  CX Data Extra Type:
*	- cx_datetime
*	- cx_spantime
*	- cx_class
*	- cx_function
*	- cx_thread
*	- cx_task
* 
* 
*  Additive CX Class And Functions:
*	- cx_memorymap(cx_object)
*	- cx_objectmanager(cx_object)
*	- cx_meta(cx_object)
*	- cx_garbagecollection(cx_object)
*	- cx_typeof(cx_object)
*	- cx_sizeof(cx_object)
*	- cx_length(cx_object)
*/
