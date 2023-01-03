#include "BSearchTree.h"
#include "Queue.h"
#include "../../Function/GFunc.h"

namespace Global {
	/** 노드를 탐색한다 */
	static STBTreeNode** BSTFindNode(STBTreeNode** a_pstNode, void* a_pvKey, COMPARE_FUNC a_pfnCompare) {
		// 노드가 없거나 키가 존재 할 경우
		if(*a_pstNode == NULL || a_pfnCompare(a_pvKey, (*a_pstNode)->m_pvKey) == 0) {
			return a_pstNode;
		}

		return BSTFindNode((a_pfnCompare(a_pvKey, (*a_pstNode)->m_pvKey) < 0) ? &(*a_pstNode)->m_pstLChildNode : &(*a_pstNode)->m_pstRChildNode, a_pvKey, a_pfnCompare);
	}

	/** 전위 순회한다 */
	static void BSTPreEnumerate(STBTreeNode* a_pstNode, void(*a_pfnCallback)(STBTreeNode*)) {
		// 노드가 존재 할 경우
		if(a_pstNode != NULL) {
			a_pfnCallback(a_pstNode);

			BSTPreEnumerate(a_pstNode->m_pstLChildNode, a_pfnCallback);
			BSTPreEnumerate(a_pstNode->m_pstRChildNode, a_pfnCallback);
		}
	}

	/** 중위 순회한다 */
	static void BSTInEnumerate(STBTreeNode* a_pstNode, void(*a_pfnCallback)(STBTreeNode*)) {
		// 노드가 존재 할 경우
		if(a_pstNode != NULL) {
			BSTInEnumerate(a_pstNode->m_pstLChildNode, a_pfnCallback);

			a_pfnCallback(a_pstNode);
			BSTInEnumerate(a_pstNode->m_pstRChildNode, a_pfnCallback);
		}
	}

	/** 후위 순회한다 */
	static void BSTPostEnumerate(STBTreeNode* a_pstNode, void(*a_pfnCallback)(STBTreeNode*)) {
		// 노드가 존재 할 경우
		if(a_pstNode != NULL) {
			BSTPostEnumerate(a_pstNode->m_pstLChildNode, a_pfnCallback);
			BSTPostEnumerate(a_pstNode->m_pstRChildNode, a_pfnCallback);

			a_pfnCallback(a_pstNode);
		}
	}

	/** 레벨 순회한다 */
	static void BSTLevelEnumerate(STBTreeNode* a_pstNode, void(*a_pfnCallback)(STBTreeNode*)) {
		STQueue stQueue;
		QInit(&stQueue);

		QEnqueue(&stQueue, a_pstNode);

		while(!QIsEmpty(&stQueue)) {
			STBTreeNode* pstNode = (STBTreeNode*)QDequeue(&stQueue);
			a_pfnCallback(pstNode);

			// 왼쪽 자식 노드가 존재 할 경우
			if(pstNode->m_pstLChildNode != NULL) {
				QEnqueue(&stQueue, pstNode->m_pstLChildNode);
			}

			// 오른쪽 자식 노드가 존재 할 경우
			if(pstNode->m_pstRChildNode != NULL) {
				QEnqueue(&stQueue, pstNode->m_pstRChildNode);
			}
		}
	}

	void BSTInit(STBSearchTree* a_pstBSearchTree, COMPARE_FUNC a_pfnCompare) {
		memset(a_pstBSearchTree, 0, sizeof(STBSearchTree));
		a_pstBSearchTree->m_pfnCompare = a_pfnCompare;
	}

	void BSTDestroy(STBSearchTree* a_pstBSearchTree) {
		BSTEnumerate(a_pstBSearchTree, EBSTOrder::POST, [](STBTreeNode* a_pstNode) -> void {
			SAFE_FREE(a_pstNode);
		});
	}

	bool BSTIsEmpty(STBSearchTree* a_pstBSearchTree) {
		return a_pstBSearchTree->m_nNumVals <= 0;
	}

	int BSTGetNumVals(STBSearchTree* a_pstBSearchTree) {
		return a_pstBSearchTree->m_nNumVals;
	}

	void* BSTGetVal(STBSearchTree* a_pstBSearchTree, void* a_pvKey) {
		assert(BSTFindNode(&a_pstBSearchTree->m_pstRootNode, a_pvKey, a_pstBSearchTree->m_pfnCompare) != NULL);
		return (*BSTFindNode(&a_pstBSearchTree->m_pstRootNode, a_pvKey, a_pstBSearchTree->m_pfnCompare))->m_pvVal;
	}

	void BSTAddVal(STBSearchTree* a_pstBSearchTree, void* a_pvKey, void* a_pvVal) {
		STBTreeNode** pstNode = BSTFindNode(&a_pstBSearchTree->m_pstRootNode, a_pvKey, a_pstBSearchTree->m_pfnCompare);

		// 키가 없을 경우
		if(*pstNode == NULL) {
			*pstNode = CreateBTNode(a_pvKey, a_pvVal);
			a_pstBSearchTree->m_nNumVals += 1;
		}
	}

	void BSTRemoveVal(STBSearchTree* a_pstBSearchTree, void* a_pvKey) {
		STBTreeNode** pstNode = BSTFindNode(&a_pstBSearchTree->m_pstRootNode, a_pvKey, a_pstBSearchTree->m_pfnCompare);

		// 키가 존재 할 경우
		if(*pstNode != NULL) {
			// 자식 노드가 모두 존재 할 경우
			if((*pstNode)->m_pstLChildNode != NULL && (*pstNode)->m_pstRChildNode != NULL) {
				STBTreeNode** pstRemoveNode = &(*pstNode)->m_pstRChildNode;

				while((*pstRemoveNode)->m_pstLChildNode != NULL) {
					pstRemoveNode = &(*pstRemoveNode)->m_pstLChildNode;
				}

				(*pstNode)->m_pvKey = (*pstRemoveNode)->m_pvKey;
				(*pstNode)->m_pvVal = (*pstRemoveNode)->m_pvVal;

				pstNode = pstRemoveNode;
			}

			STBTreeNode* pstRemoveNode = *pstNode;

			// 왼쪽 자식 노드가 존재 할 경우
			if(pstRemoveNode->m_pstLChildNode != NULL) {
				*pstNode = pstRemoveNode->m_pstLChildNode;
			} else {
				*pstNode = pstRemoveNode->m_pstRChildNode;
			}

			a_pstBSearchTree->m_nNumVals -= 1;
		}
	}

	void BSTEnumerate(STBSearchTree* a_pstBSearchTree, EBSTOrder a_eOrder, void(*a_pfnCallback)(STBTreeNode*)) {
		switch(a_eOrder) {
			case EBSTOrder::PRE: BSTPreEnumerate(a_pstBSearchTree->m_pstRootNode, a_pfnCallback); break;
			case EBSTOrder::IN: BSTInEnumerate(a_pstBSearchTree->m_pstRootNode, a_pfnCallback); break;
			case EBSTOrder::POST: BSTPostEnumerate(a_pstBSearchTree->m_pstRootNode, a_pfnCallback); break;
			case EBSTOrder::LEVEL: BSTLevelEnumerate(a_pstBSearchTree->m_pstRootNode, a_pfnCallback); break;
		}
	}
}
