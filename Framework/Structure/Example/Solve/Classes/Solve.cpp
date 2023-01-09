#include "Solve_01/Solve_01.h"
#include "Solve_02/Solve_02.h"

/** 메인 함수 */
int main(int argc, char* args[]) {
	srand((unsigned int)time(NULL));

	//return S01::Solve_01(argc, args);
	return S02::Solve_02(argc, args);
}
