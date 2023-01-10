#pragma once

#include "../Global/Define/KGDefine.h"

/*
 * 연결 리스트란?
 * - 배열 리스트와 달리 메모리의 순서를 통해 데이터의 순서를 보장하는 것이 아니라 가상의 순서를 만들어서 데이터를 관리하는 자료구조를 의미한다. (즉, 데이터의 순서가 해당
 * 데이터가 메모리에 할당 된 순서와 일치하지 않을 수 있다는 것을 의미한다.)
 * 
 * 연결 리스트 장점
 * - 배열 리스트와 달리 데이터의 삽입/삭제 시 불필요한 데이터의 이동이 발생하지 않는다. (즉, 삽입/삭제가 배열 리스트에 비해 빠르게 수행된다는 것을 의미한다.)
 * 
 * 연결 리스트 단점
 * - 배열 리스트와 달리 임의 접근이 불가능하기 때문에 특정 데이터의 위치 (순서) 를 알고 있다고 하더라도 항상 처음부터 순차적으로 접근해야된다. (즉, 데이터의 탐색
 * 성능이 떨어진다.)
 * 
 * 연결 리스트 유형
 * - 단일 (단방향) 연결 리스트
 * - 이중 (양방향) 연결 리스트
 * - 원형 연결 리스트
 */ 
namespace E04 {
	/** Example 4 */
	int Example_04(int argc, char* args[]);
}
