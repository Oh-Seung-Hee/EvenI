#pragma once

#include "../Global/Define/KGDefine.h"

/*
 * 배열 리스트란?
 * - 배열을 기반으로 데이터의 순차성을 만들어내는 자료구조를 의미한다. (즉, 배열의 원리를 통해 데이터의 순서가 만들어지기 때문에 특정 위치에 존재하는
 * 데이터에 임의 접근하는 것이 가능하다.)
 * 
 * 배열 리스트 장점
 * - 임의 접근이 가능하기 때문에 특정 데이터의 위치를 알고 있다면 상수 (O(1)) 시간에 접근하는 것이 가능하다. (즉, 데이터 탐색을 빠른 시간에 처리하는 것이
 * 가능하다.)
 * 
 * 배열 리스트 단점
 * - 메모리의 순서를 통해 데이터의 순차성을 만들어내기 때문에 특정 위치에 데이터가 삽입 또는 삭제가 되었을 경우 데이터의 이동이 발생한다. (즉, 삽입/삭제 시
 * 성능이 떨어진다는 것을 의미한다.)
 * 
 * 또한, 배열을 통해 구현되기 때문에 할당 된 공간이 부족 할 경우 새로운 공간을 할당 및 데이터를 복사하는 연산이 필요하다.
 */
namespace E03 {
	/** Example 3 */
	int Example_03(int argc, char* args[]);
}
