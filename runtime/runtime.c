﻿//------------------------------------------------------------------------------
// 헤더 파일 목록.
//------------------------------------------------------------------------------
#include <stdio.h>
#include <stdint.h>
#include "runtime.h"
#include "list.h"


//------------------------------------------------------------------------------
// 프로그램 진입점.
//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
	
	list_instance instance = list_create();

	printf("Hello, World!\n");
	return 0;
}