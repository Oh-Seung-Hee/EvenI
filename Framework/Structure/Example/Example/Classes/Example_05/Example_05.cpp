#include "Example_05.h"
#include "../Global/Utility/Structure/BSearchTree.h"

#define MAX_NUM_VALS			(20)

namespace E05 {
	int Example_05(int argc, char* args[]) {
		Global::STBSearchTree stBSearchTree;
		Global::BSTInit(&stBSearchTree);

		for(int i = 0; i < MAX_NUM_VALS; ++i) {

		}

		Global::BSTDestroy(&stBSearchTree);
		return 0;
	}
}
