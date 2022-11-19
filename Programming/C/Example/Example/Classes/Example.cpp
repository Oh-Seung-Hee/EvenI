#include "Example_01/Example_01.h"
#include "Example_02/Example_02.h"
#include "Example_03/Example_03.h"
#include "Example_04/Example_04.h"
#include "Example_05/Example_05.h"
#include "Example_06/Example_06.h"
#include "Example_07/Example_07.h"
#include "Example_08/Example_08.h"

/** 메인 함수 */
int main(int argc, char* args[]) {
	srand((unsigned int)time(NULL));

	//return E01::Example_01(argc, args);
	//return E02::Example_02(argc, args);
	//return E03::Example_03(argc, args);
	//return E04::Example_04(argc, args);
	//return E05::Example_05(argc, args);
	//return E06::Example_06(argc, args);
	//return E07::Example_07(argc, args);
	return E08::Example_08(argc, args);
}
