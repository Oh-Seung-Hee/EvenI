#include "BSearchTree.h"
#include "Queue.h"

namespace Global {
	/** 전위 순회한다 */
	static void BSTPreEnumerate(STBTNode* a_pstNode, void(*a_pfnCallback)(STBTNode*)) {
		// 노드가 존재 할 경우
		if(a_pstNode != NULL) {
			a_pfnCallback(a_pstNode);

			BSTPreEnumerate(a_pstNode->m_pstLChildNode, a_pfnCallback);
			BSTPreEnumerate(a_pstNode->m_pstRChildNode, a_pfnCallback);
		}
	}

	/** 중위 순회한다 */
	static void BSTInEnumerate(STBTNode* a_pstNode, void(*a_pfnCallback)(STBTNode*)) {
		// 노드가 존재 할 경우
		if(a_pstNode != NULL) {
			BSTInEnumerate(a_pstNode->m_pstLChildNode, a_pfnCallback);

			a_pfnCallback(a_pstNode);
			BSTInEnumerate(a_pstNode->m_pstRChildNode, a_pfnCallback);
		}
	}

	/** 후위 순회한다 */
	static void BSTPostEnumerate(STBTNode* a_pstNode, void(*a_pfnCallback)(STBTNode*)) {
		// 노드가 존재 할 경우
		if(a_pstNode != NULL) {
			BSTPostEnumerate(a_pstNode->m_pstLChildNode, a_pfnCallback);
			BSTPostEnumerate(a_pstNode->m_pstRChildNode, a_pfnCallback);

			a_pfnCallback(a_pstNode);
		}
	}

	/** 레벨 순회한다 */
	static void BSTLevelEnumerate(STBTNode* a_pstNode, void(*a_pfnCallback)(STBTNode*)) {
		STQueue stQueue;
		QInit(&stQueue);

		QEnqueue(&stQueue, a_pstNode);

		while(!QIsEmpty(&stQueue)) {
			STBTNode* pstNode = (STBTNode*)QDequeue(&stQueue);
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

	void BSTInit(STBSearchTree* a_pstBSearchTree) {
		memset(a_pstBSearchTree, 0, sizeof(STBSearchTree));
	}

	void BSTDestroy(STBSearchTree* a_pstBSearchTree) {
		BSTEnumerate(a_pstBSearchTree, EBTOrder::POST, [](STBTNode* a_pstNode) -> void {
			SAFE_FREE(a_pstNode);
		});
	}

	void BSTEnumerate(STBSearchTree* a_pstBSearchTree, EBTOrder a_eOrder, void(*a_pfnCallback)(STBTNode*)) {
		switch(a_eOrder) {
			case EBTOrder::PRE: BSTPreEnumerate(a_pstBSearchTree->m_pstRootNode, a_pfnCallback); break;
			case EBTOrder::IN: BSTInEnumerate(a_pstBSearchTree->m_pstRootNode, a_pfnCallback); break;
			case EBTOrder::POST: BSTPostEnumerate(a_pstBSearchTree->m_pstRootNode, a_pfnCallback); break;
			case EBTOrder::LEVEL: BSTLevelEnumerate(a_pstBSearchTree->m_pstRootNode, a_pfnCallback); break;
		}
	}
}
