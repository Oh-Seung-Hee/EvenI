#include "Example_06.h"
#include "../Global/Utility/Structure/PQueue.h"

#define MAX_NUM_VALS			(15)

namespace E06 {
	/** 값을 비교한다 */
	int CompareVal(void* a_pvVal01, void* a_pvVal02) {
		return (int)a_pvVal01 - (int)a_pvVal02;
	}

	int Example_06(int argc, char* args[]) {
		Global::STPQueue stPQueue;
		Global::PQInit(&stPQueue, CompareVal);

		for(int i = 0; i < MAX_NUM_VALS; ++i) {
			Global::PQEnqueue(&stPQueue, (void*)(rand() % 100));
		}

		printf("=====> 우선 순위 큐 요소 <=====\n");

		while(!Global::PQIsEmpty(&stPQueue)) {
			printf("%d, ", (int)Global::PQDequeue(&stPQueue));
		}

		printf("\n");
		Global::PQDestroy(&stPQueue);

		return 0;
	}
}
