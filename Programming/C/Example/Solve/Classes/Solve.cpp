#include "Solve_01/Solve_01.h"
#include "Solve_02/Solve_02.h"
#include "Solve_04/Solve_04.h"
#include "Solve_05/Solve_05.h"
#include "Solve_06/Solve_06.h"
#include "Solve_07/Solve_07.h"
#include "Solve_08/Solve_08.h"

/** 메인 함수 */
int main(int argc, char* args[]) {
	srand((unsigned int)time(NULL));

	//return S01::Solve_01(argc, args);
	//return S02::Solve_02(argc, args);
	//return S04::Solve_04(argc, args);
	//return S05::Solve_05(argc, args);
	//return S06::Solve_06(argc, args);
	//return S07::Solve_07(argc, args);
	return S08::Solve_08(argc, args);
}
