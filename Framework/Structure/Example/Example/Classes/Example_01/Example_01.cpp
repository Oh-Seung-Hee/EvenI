#include "Example_01.h"
#include "../Global/Utility/Structure/Stack.h"

#define MAX_NUM_VALS			(15)

namespace E01 {
	int Example_01(int argc, char* args[]) {
		Global::STStack stStack;
		Global::SInit(&stStack);

		printf("=====> 스택 입력 순서 <=====\n");

		for(int i = 0; i < MAX_NUM_VALS; ++i) {
			printf("%d, ", i + 1);
			Global::SPush(&stStack, (void*)(i + 1));
		}

		printf("\n\n=====> 스택 출력 순서 <=====\n");

		while(!Global::SIsEmpty(&stStack)) {
			printf("%d, ", (int)Global::SPop(&stStack));
		}

		printf("\n");
		Global::SDestroy(&stStack);

		return 0;
	}
}
