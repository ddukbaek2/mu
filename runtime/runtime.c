﻿//------------------------------------------------------------------------------
// 헤더 파일 목록.
//------------------------------------------------------------------------------
#include <stdio.h> // getchar
#include "runtime.h"
#include "list.h"
#include "object.h"


//------------------------------------------------------------------------------
// 프로그램 진입점.
//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
	
	//list_instance instance = list_create();
	//list_add(instance, NULL);

	printf("Hello, World!");

	while (getchar() != '\n');
	return 0;
}