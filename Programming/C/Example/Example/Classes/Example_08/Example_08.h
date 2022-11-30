#pragma once

#include "../Global/Define/KGDefine.h"

/*
포인터란?
- 메모리 주소를 제어 할 수 있는 기능을 의미한다. (즉, 포인터를 활용하면 변수를 통하지 않고 특정 메모리에 존재하는 데이터를 
제어하는 것이 가능하다.) 단, 포인터를 통해 메모리를 제어하기 위해서는 반드시 특정 메모리에 영역에 대한 접근 권한을 운영체제로부터 
획득 할 필요가 있다. (즉, 포인터를 통해 허용되지 않는 메모리에 접근하는 것은 불가능하다.)

C 포인터 (변수) 선언 방법
- 자료형 + * (포인터 연산자) + 포인터 (변수) 이름

Ex)
int* pnVal = NULL;
float* pfVal = NULL;
*/
namespace E08 {
	/** Example 8 */
	int Example_08(int argc, char* args[]);
}
