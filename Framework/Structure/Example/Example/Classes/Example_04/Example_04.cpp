#include "Example_04.h"
#include "../Global/Utility/Structure/LinkedList.h"

#define MAX_NUM_VALS			(15)

namespace E04 {
	/** 값을 비교한다 */
	int CompareVal(void* a_pvVal01, void* a_pvVal02) {
		return (int)a_pvVal01 - (int)a_pvVal02;
	}

	int Example_04(int argc, char* args[]) {
		Global::STLinkedList stLinkedList;
		Global::LLInit(&stLinkedList, CompareVal);

		for(int i = 0; i < MAX_NUM_VALS; ++i) {
			Global::LLAddVal(&stLinkedList, (void*)(i + 1));
		}

		printf("=====> 연결 리스트 요소 <=====\n");

		for(int i = 0; i < Global::LLGetNumVals(&stLinkedList); ++i) {
			printf("%d, ", (int)Global::LLGetVal(&stLinkedList, i));
		}

		Global::LLInsertVal(&stLinkedList, 5, (void*)100);
		printf("\n\n=====> 연결 리스트 요소 - 추가 후 <=====\n");

		for(int i = 0; i < Global::LLGetNumVals(&stLinkedList); ++i) {
			printf("%d, ", (int)Global::LLGetVal(&stLinkedList, i));
		}

		Global::LLRemoveVal(&stLinkedList, (void*)5);
		printf("\n\n=====> 연결 리스트 요소 - 제거 후 <=====\n");

		for(int i = 0; i < Global::LLGetNumVals(&stLinkedList); ++i) {
			printf("%d, ", (int)Global::LLGetVal(&stLinkedList, i));
		}

		printf("\n");
		Global::LLDestroy(&stLinkedList);

		return 0;
	}
}
