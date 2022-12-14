#pragma once

#include "../Global/Define/KGDefine.h"

/*
 * 자료형이란?
 * - 컴퓨터에 사용되는 데이터를 해석하기 위한 구문을 의미한다. (즉, 어떤 자료형을 사용하냐에 따라 특정 데이터의 처리 방식이
 * 달라진다는 것을 의미한다.) 또한, 자료형의 데이터의 크기를 나타내는데 사용된다.
 * 
 * C 자료형의 종류
 * // 정수형
 * - short : 2 byte
 * - int : 4 byte
 * - long : 4 or 8 byte <- 컴파일러에 따라 크기가 다르다
 * - long long : 8 byte
 * 
 * // 실수형
 * - float : 4 byte <- 6 ~ 7 자리까지 정밀도 보장
 * - double : 8 byte <- 15 자리까지 정밀도 보장
 * - long double : 8 byte or 12 byte or 16 byte <- 컴파일러에 따라 크기가 다르다
 * 
 * // 문자형
 * - char : 1 byte
 * 
 * C 는 단어 또는 문장을 표현 할 수 있는 자료형이 별도로 존재하지 않기 떄문에 해당 데이터를 표현하기 위해서는 배열을 사용한다. 단,
 * 문자의 배열이 문자열이 되기 위해서는 반드시 마지막 문자에 NULL (널 문자) 를 포함해야한다. (즉, 널 문자가 포함되지 않는 문자의
 * 배열은 순수한 데이터 배열을 의미한다.)
 * 
 * 정수형은 부호 여부에 따라 signed 와 unsigned 로 구분된다. signed 는 양수/음수 를 모두 표현 할 수 있는 반면 부호 여부를
 * 표현하기 위해 1 비트가 소모되기 때문에 표현 할 수 있는 데이터의 범위가 unsigned 에 비해 절반으로 줄어드는 단점이 존재한다.
 * 
 * 변수란?
 * - 데이터를 저장 및 읽어들일 수 있는 공간을 의미한다. (즉, 변수를 활용하면 재사용 가능한 데이터를 처리하는 것이 가능하다.)
 * 
 * C 변수 선언 방법
 * - 자료형 + 변수 이름
 * 
 * Ex)
 * int nVal = 0;
 * float fVal = 3.14f;
 * 
 * 단, 변수 이름은 알파벳 (대/소문자 구분), 숫자, _ (언더 스코어) 만 사용가능하며, 첫 글자에 숫자를 사용하는 것은 불가능하다.
 * 또한, 변수 이름은 특정 공간에 유일해야한다. (즉, 동일한 공간에 중복 된 이름을 지닌 변수를 선언하는 것이 불가능하다.)
 * 
 * 상수란?
 * - 변수와 달리 데이터의 변경이 불가능하고 읽어들일 수 만 있는 공간을 의미한다.
 * 
 * C 상수 종류
 * - 리터널 상수 : 이름이 존재하지 않는 상수를 의미한다. (즉, 한번 활용하고 나면 재사용이 불가능하다.)
 * - 심볼릭 상수 : 이름이 존재하는 상수를 의미한다. (즉, 필요 할 때 재사용이 가능하다.)
 * 
 * C 심볼릭 상수 선언 방법
 * - const + 자료형 + 상수 이름
 * 
 * Ex)
 * const int nVal = 0;
 * const float fVal = 3.14f;
 * 
 * 심볼릭 상수는 초기화를 통해서만 데이터를 설정하는 것이 가능하기 때문에 특정 상수를 선언 할 때는 반드시 필요한 데이터로 초기화
 * 해줘야한다. (즉, 초기화를 하지 않을 경우 쓰레기 데이터로 설정되기 때문에 아무런 의미 없는 상수가 선언된다.)
 */
namespace E02 {
	/** Example 2 */
	int Example_02(int argc, char* args[]);
}
