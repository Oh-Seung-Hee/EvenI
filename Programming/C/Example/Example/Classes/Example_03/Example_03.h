#pragma once

#include "../Global/Define/KGDefine.h"

/*
* 연산자란?
* - 프로그램 동작함에 있어서 특정 역할을 수행하는 기호를 의미한다. (즉, 연산자를 활용함으로써 데이터를 목적에 맞게 처리하는 것이
* 가능하다.)
* 
* C 연산자 종류
* - 대입 연산자 : =, +=, -=, ...
* - 산술 연산자 : +, -, *, /, %
* - 증감 연산자 : a++, a--, ++a, --a
* - 관계 연산자 : <, >, <=, >=, ==, !=
* - 논리 연산자 : &&, ||, !
* - 비트 연산자 : &, |, ^, ~, <<, >>
* - 기타 연산자 : *, &, ->, 형변환 연산자, sizeof, 우선 순위 연산자, 조건 (삼항) 연산자, 등등...
* 
* 증감 연산자는 증감 연산자의 위치에 따라 전위/후위 증감 연산자로 구분된다. 전위 증감 연산자는 선 증감 후 연산의 특징을 지니고
* 있으며, 후위 증감 연산자는 선 연산 후 증감의 특징을 지닌다.
* 
* 모든 연산자는 우선 순위가 존재하며, 해당 순서는 ( ) (우선 순위 연산자) 를 사용해서 연산 순서를 제어하는 것이 가능하다.
*/
namespace E03 {
	/** Example 3 */
	int Example_03(int argc, char* args[]);
}
