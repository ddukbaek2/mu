//------------------------------------------------------------------------------
// 헤더 파일 목록.
//------------------------------------------------------------------------------
#include <stdio.h> // getchar
#include "runtime.h"
#include "list.h"
#include "object.h"
#include "mulang.h"
#include <locale.h> // setlocale, LC_ALL


//------------------------------------------------------------------------------
// 프로그램 진입점.
//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
	
	//list_instance instance = list_create();
	//list_add(instance, NULL);

	//printf("Hello, World!");

	// 콘솔 언어설정 한글 로케일.
	// utf8-nobom 설정 빌드시 사용 필요.
	setlocale(LC_ALL, ".UTF-8");

	printf("안녕하세요!");

	while (getchar() != '\n');
	return 0;
}



