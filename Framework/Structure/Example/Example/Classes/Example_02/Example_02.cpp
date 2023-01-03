#include "Example_02.h"
#include "../Global/Utility/Structure/Queue.h"

#define MAX_NUM_VALS			(15)

namespace E02 {
	int Example_02(int argc, char* args[]) {
		Global::STQueue stQueue;
		Global::QInit(&stQueue);

		printf("=====> 큐 입력 순서 <=====\n");

		for(int i = 0; i < MAX_NUM_VALS; ++i) {
			printf("%d, ", i + 1);
			Global::QEnqueue(&stQueue, (void*)(i + 1));
		}

		printf("\n\n=====> 큐 출력 순서 <=====\n");

		while(!Global::QIsEmpty(&stQueue)) {
			printf("%d, ", (int)Global::QDequeue(&stQueue));
		}

		printf("\n");
		Global::QDestroy(&stQueue);

		return 0;
	}
}
