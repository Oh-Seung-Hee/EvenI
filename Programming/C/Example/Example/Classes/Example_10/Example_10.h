#pragma once

#include "../Global/Define/KGDefine.h"

/*
* 동적 할당이란?
* - 프로그램이 실행 중에 필요에 따라 메모리를 할당 및 제어 할 수 있는 기능을 의미한다. (즉, 동적 할당을 활용하면 프로그램이 
* 구동 될 때 메모리를 자유롭게 할당하는 것이 가능하다.) 단, 동적으로 할당 된 메모리는 사용자 (프로그래머) 에 의해서 관리되는 
* 메모리이기 때문에 해당 메모리가 더이상 필요 없을 경우 직접 제거해 줄 필요가 있다. (즉, 동적으로 할당 된 메모리는 시스템에 
* 의해서 자동으로 관리되지 않기 때문에 사용지 완료 된 메모리는 사용자가 직접 명시적으로 제거해주어야한다.) 만약, 사용이 완료 된
* 메모리를 제거하지 않았을 경우 해당 메모리는 불 필요하게 메모리 공간을 자치하며, 이를 메모리 릭이 발생했다고 한다.
* 
* C 동적 할당하는 방법
* - malloc
* - calloc
* - realloc
* 
* Ex)
* int* pnValp1 = (int*)malloc(sizeof(int));
* int* pnVal02 = (int*)calloc(1, sizeof(int));
* int* pnVal02 = (int*)realloc(pnVal02, sizeof(int));
* 
* malloc vs calloc
* - calloc 함수는 malloc 함수와 달리 동적으로 할당 된 메모리를 초기화해주는 특징이 존재한다. (즉, malloc 함수로 할당 된 
* 메모리는 초기화가 생략되어있기 때문에 해당 메모리는 쓰레기 값들이 존재한다는 것을 알수 있다.)
*/
namespace E10 {
	/** Example 10 */
	int Example_10(int argc, char* args[]);
}
