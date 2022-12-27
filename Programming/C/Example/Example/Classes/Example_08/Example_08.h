#pragma once

#include "../Global/Define/KGDefine.h"

/*
 * 포인터란?
 * - 메모리 주소를 제어 할 수 있는 기능을 의미한다. (즉, 포인터를 활용하면 변수를 통하지 않고 특정 메모리에 존재하는 데이터를 
 * 제어하는 것이 가능하다.) 단, 포인터를 통해 메모리를 제어하기 위해서는 반드시 특정 메모리에 영역에 대한 접근 권한을 운영체제로부터 
 * 획득 할 필요가 있다. (즉, 포인터를 통해 허용되지 않는 메모리에 접근하는 것은 불가능하다.)
 * 
 * C 포인터 (변수) 선언 방법
 * - 자료형 + * (포인터 연산자) + 포인터 (변수) 이름
 * 
 * Ex)
 * int* pnVal = NULL;
 * float* pfVal = NULL;
 * 
 * 포인터에 자료형이 존재하는 이유
 * - 포인터를 통해 메모리에 접근 할 때 몇 바이트에 걸쳐서 특정 데이터를 저장 및 읽어들일지를 결정하기 위해서이다. (즉, 컴파일러는
 * 자료형을 통해서 해당 포인터가 가리키는 메모리 위치를 기준으로 해당 자료형 크기에 맞게 데이터를 제어한다는 것을 의미한다.)
 * 
 * 단, 단순히 메모리 주소만 필요 할 경우에는 자료형에 존재가 필요 없기 때문에 해당 경우에는 void 포인터를 사용하는 것이 가능하다.
 * 
 * void 포인터란?
 * - 메모리 주소만을 지닐 수 있는 포인터를 의미한다. (즉, 해당 포인터를 통해서 메모리에 접근하는 것은 불가능하다.)
 * void 포인터에는 자료형에 대한 정보가 없기 때문에 해당 포인터를 통해 직접적으로 메모리에 접근하는 것은 불가능하지만 void 포인터를
 * 활용하면 어떠한 자료형의 포인터도 해당 포인터에 할당하는 것이 가능하다.
 * 
 * 만약, void 포인터를 통해서 해당 포인터가 가리키는 메모리에 접근하기 위해서는 반드시 형변환 연산자를 통해서 특정 자료형에 대한
 * 정보를 지니는 포인터로 변환 할 필요가 있다.
 */
namespace E08 {
	/** Example 8 */
	int Example_08(int argc, char* args[]);
}
