#include "Example_05.h"
#include "../Global/Utility/Structure/BSearchTree.h"

#define MAX_NUM_VALS			(15)

namespace E05 {
	/** 값을 비교한다 */
	int CompareVal(void* a_pvVal01, void* a_pvVal02) {
		return (int)a_pvVal01 - (int)a_pvVal02;
	}

	/** 노드를 출력한다 */
	void PrintNode(Global::STBTreeNode* a_pstNode) {
		printf("[%d]%d, ", (int)a_pstNode->m_pvKey, (int)a_pstNode->m_pvVal);
	}

	int Example_05(int argc, char* args[]) {
		Global::STBSearchTree stBSearchTree;
		Global::BSTInit(&stBSearchTree, CompareVal);

		for(int i = 0; i < MAX_NUM_VALS; ++i) {
			int nKeyVal = rand() % 100;
			Global::BSTAddVal(&stBSearchTree, (void*)nKeyVal, (void*)nKeyVal);
		}

		printf("=====> 이진 탐색 트리 요소 <=====\n");

		Global::BSTEnumerate(&stBSearchTree, Global::EBSTOrder::PRE, PrintNode);

		Global::BSTAddVal(&stBSearchTree, (void*)100, (void*)100);
		printf("\n\n=====> 이진 탐색 트리 요소 - 추가 후 <=====\n");

		Global::BSTEnumerate(&stBSearchTree, Global::EBSTOrder::IN, PrintNode);

		Global::BSTRemoveVal(&stBSearchTree, (void*)100);
		printf("\n\n=====> 이진 탐색 트리 요소 - 삭제 후 <=====\n");

		Global::BSTEnumerate(&stBSearchTree, Global::EBSTOrder::POST, PrintNode);

		printf("\n");
		Global::BSTDestroy(&stBSearchTree);

		return 0;
	}
}
