#pragma once

#include "../Global/Define/KGDefine.h"

/*
 * 조건문이란?
 * - 특정 조건에 따라 프로그램의 흐름을 분기시키는 구문을 의미한다. (즉, 조건문을 활용하면 주어진 조건에 따라 다양한 결과를
 * 만들어내는 프로그램을 제작하는 것이 가능하다.)
 * 
 * 프로그램의 흐름이란?
 * - 프로그램이 실행되는 순서를 의미한다. (즉, 컴퓨터에 의해서 현재 실행되고 있는 명령어의 순서를 의미한다.)
 * 
 * C 조건문의 종류
 * - if ~ esle
 * - switch ~ case
 * 
 * Ex)
 * if(조건문 1) {
 *		// Do Something
 * } else if(조건문 2) {
 *		// Do Something
 * } else {
 *		// Do Something
 * }
 * 
 * switch(데이터) {
 * case 조건 1: // Do Something
 * case 조건 2: // Do Something
 * default: // Do Something
 * }
 */
namespace E04 {
	/** Example 4 */
	int Example_04(int argc, char* args[]);
}
