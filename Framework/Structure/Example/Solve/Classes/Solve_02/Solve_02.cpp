//#define S02_01
#define S02_02

#include "Solve_02.h"
#include "../Global/Utility/Structure/Queue.h"
#include "../Global/Utility/Structure/Dequeue.h"

#define MAX_NUM_VALS			(15)

namespace S02 {
#if defined S02_01

#elif defined S02_02

#endif // #if defined S02_01

	int Solve_02(int argc, char* args[]) {
#if defined S02_01
		Global::STQueue stQueue;
		Global::QInit(&stQueue);

		printf("=====> 데이터 입력 순서 <=====\n");

		for(int i = 0; i < MAX_NUM_VALS; ++i) {
			printf("%d, ", i + 1);
			Global::QEnqueue(&stQueue, (void*)(i + 1));
		}

		printf("\n\n=====> 데이터 출력 순서 <=====\n");

		while(!Global::QIsEmpty(&stQueue)) {
			printf("%d, ", (int)Global::QDequeue(&stQueue));
		}

		printf("\n");
		Global::QDestroy(&stQueue);
#elif defined S02_02
		Global::STDequeue stDequeue01;
		Global::STDequeue stDequeue02;

		Global::DInit(&stDequeue01);
		Global::DInit(&stDequeue02);

		printf("=====> 데이터 입력 순서 <=====\n");

		for(int i = 0; i < MAX_NUM_VALS; ++i) {
			int nVal = rand() % 100;

			Global::DEnqueueRear(&stDequeue01, (void*)nVal);
			Global::DEnqueueFront(&stDequeue02, (void*)nVal);

			printf("%d, ", nVal);
		}

		printf("\n\n=====> 데이터 출력 순서 - 1 <=====\n");

		while(!Global::DIsEmpty(&stDequeue01)) {
			printf("%d, ", (int)Global::DDequeueFront(&stDequeue01));
		}

		printf("\n\n=====> 데이터 출력 순서 - 2 <=====\n");

		while(!Global::DIsEmpty(&stDequeue02)) {
			printf("%d, ", (int)Global::DDequeueRear(&stDequeue02));
		}

		printf("\n");

		Global::DDestroy(&stDequeue01);
		Global::DDestroy(&stDequeue02);
#endif // #if defined S02_01

		return 0;
	}
}
