#include "Example_06.h"
#include "../Global/Utility/Structure/PQueue.h"

#define MAX_NUM_VALS			(15)

namespace E06 {
	/** 오른 차순으로 비교한다 */
	int CompareByAscending(void* a_pvVal01, void* a_pvVal02) {
		return (int)a_pvVal01 - (int)a_pvVal02;
	}

	/** 내림 차순으로 비교한다 */
	int CompareByDescending(void* a_pvVal01, void* a_pvVal02) {
		return (int)a_pvVal02 - (int)a_pvVal01;
	}

	int Example_06(int argc, char* args[]) {
		Global::STPQueue stPQueue;
		Global::PQInit(&stPQueue, CompareByAscending);

		printf("=====> 우선 순위 큐 입력 순서 <=====\n");

		for(int i = 0; i < MAX_NUM_VALS; ++i) {
			int nVal = rand() % 100;
			printf("%d, ", nVal);

			Global::PQEnqueue(&stPQueue, (void*)nVal);
		}

		printf("\n\n=====> 우선 순위 큐 출력 순서 <=====\n");

		while(!Global::PQIsEmpty(&stPQueue)) {
			printf("%d, ", (int)Global::PQDequeue(&stPQueue));
		}

		printf("\n");
		Global::PQDestroy(&stPQueue);

		return 0;
	}
}
