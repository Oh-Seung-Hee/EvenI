#pragma once

#include "../Global/Define/KGDefine.h"

/*
 * 과제 4 - 1
 * - 점수를 입력 받아 해당 점수에 해당하는 학점을 출력하기 (단, if ~ else 조건문만 사용 가능하다.)
 * 
 * +, 0, - 점수 범위
 * - 0 ~ 3 : - 학점
 * - 4 ~ 6 : 0 학점
 * - 7 ~ 9 : + 학점
 * 
 * Ex)
 * 점수 입력 : 67
 * 결과 : D+ 입니다.
 * 
 * 점수 입력 : 81
 * 결과 : B- 입니다.
 * 
 * 
 * 과제 4 - 2
 * - 점수를 입력 받아 해당 점수에 해당하는 학점을 출력하기 (단, switch ~ case 조건문만 사용 가능하다.)
 * 
 * Ex)
 * 점수 입력 : 75
 * 결과 : C0 입니다.
 */
namespace P04 {
	/** Practice 4 */
	int Practice_04(int argc, char* args[]);
}
