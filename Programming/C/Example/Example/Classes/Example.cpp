#include "Example_01/Example_01.h"
#include "Example_02/Example_02.h"
#include "Example_03/Example_03.h"
#include "Example_04/Example_04.h"
#include "Example_05/Example_05.h"
#include "Example_06/Example_06.h"
#include "Example_07/Example_07.h"
#include "Example_08/Example_08.h"
#include "Example_09/Example_09.h"
#include "Example_10/Example_10.h"
#include "Example_11/Example_11.h"
#include "Example_12/Example_12.h"

/*
* extern 키워드를 활용하면 다른 파일에 선언 된 전역 변수를 가져오는 것이 가능하다. 단, 해당 키워드로 선언 된 전역 변수가 정적
* 전역 변수 일 경우 링크 단계에서 에러가 발생한다.
*/
extern int g_nVal01;
//extern int g_nVal02;

/*
* 메인 함수란?
* - C 로 작성 된 프로그램이 구동 될 때 가장 먼저 호출되는 함수를 의미한다. (즉, 프로그램이 실행 되었다는 것은 메인 함수가 실행
* 되고 있다는 것을 의미한다.) 따라서, 해당 함수는 Entry (진입) 함수라고도 하며 메인 함수는 운영체제에 의해서 자동으로 호출되기
* 때문에 반드시 작성해야되는 함수이다.
* 
* 또한, 메인 함수가 종료 될 경우 프로그램이 종료된다. (즉, 메인 함수 호출이 완료 되었다는 것은 프로그램이 종료되었다는 것을
* 의미한다.)
* 
* C 메인 함수 종류
* - void main(void);					<- 입력 X, 출력 X
* - void main(int argc, char* args[]);	<- 입력 O, 출력 X
* - int main(void);						<- 입력 X, 출력 O
* - int main(int argc, char* args[]);	<- 입력 O, 출력 O
*/
/** 메인 함수 */
int main(int argc, char* args[]) {
	g_nVal01 = 10;
	srand((unsigned int)time(NULL));

	//return E01::Example_01(argc, args);
	//return E02::Example_02(argc, args);
	//return E03::Example_03(argc, args);
	//return E04::Example_04(argc, args);
	//return E05::Example_05(argc, args);
	//return E06::Example_06(argc, args);
	//return E07::Example_07(argc, args);
	//return E08::Example_08(argc, args);
	//return E09::Example_09(argc, args);
	//return E10::Example_10(argc, args);
	return E11::Example_11(argc, args);
	//return E12::Example_12(argc, args);
}
