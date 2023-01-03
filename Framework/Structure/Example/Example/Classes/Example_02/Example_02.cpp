#include "Example_02.h"
#include "../Global/Utility/Structure/Queue.h"

#define MAX_NUM_VALS			(15)

namespace E02 {
	int Example_02(int argc, char* args[]) {
		Global::STQueue stQueue;
		Global::QInit(&stQueue);

		for(int i = 0; i < MAX_NUM_VALS; ++i) {
			Global::QEnqueue(&stQueue, (void*)(i + 1));
		}

		printf("=====> 큐 요소 <=====\n");

		while(!Global::QIsEmpty(&stQueue)) {
			printf("%d, ", (int)Global::QDequeue(&stQueue));
		}

		printf("\n");
		Global::QDestroy(&stQueue);

		return 0;
	}
}
