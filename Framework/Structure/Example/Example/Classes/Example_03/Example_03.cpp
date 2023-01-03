#include "Example_03.h"
#include "../Global/Utility/Structure/ArrayList.h"

#define MAX_NUM_VALS			(15)

namespace E03 {
	/** 값을 비교한다 */
	int CompareVal(void* a_pvVal01, void* a_pvVal02) {
		return (int)a_pvVal01 - (int)a_pvVal02;
	}

	int Example_03(int argc, char* args[]) {
		Global::STArrayList stArrayList;
		Global::ALInit(&stArrayList, CompareVal);

		for(int i = 0; i < MAX_NUM_VALS; ++i) {
			Global::ALAddVal(&stArrayList, (void*)(i + 1));
		}

		printf("=====> 배열 리스트 요소 <=====\n");

		for(int i = 0; i < Global::ALGetNumVals(&stArrayList); ++i) {
			printf("%d, ", (int)Global::ALGetVal(&stArrayList, i));
		}

		Global::ALInsertVal(&stArrayList, 5, (void*)100);
		printf("\n\n=====> 배열 리스트 요소 - 추가 후 <=====\n");

		for(int i = 0; i < Global::ALGetNumVals(&stArrayList); ++i) {
			printf("%d, ", (int)Global::ALGetVal(&stArrayList, i));
		}

		Global::ALRemoveVal(&stArrayList, (void*)5);
		printf("\n\n=====> 배열 리스트 요소 - 제거 후 <=====\n");

		for(int i = 0; i < Global::ALGetNumVals(&stArrayList); ++i) {
			printf("%d, ", (int)Global::ALGetVal(&stArrayList, i));
		}

		printf("\n");
		Global::ALDestroy(&stArrayList);

		return 0;
	}
}
