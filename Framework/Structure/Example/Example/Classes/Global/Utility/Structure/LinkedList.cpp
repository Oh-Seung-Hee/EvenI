#include "LinkedList.h"

namespace Global {
	/** 노드를 생성한다 */
	static STLLNode* LLCreateNode(void* a_pvVal) {
		STLLNode* pstNode = (STLLNode*)malloc(sizeof(STLLNode));
		pstNode->m_pvVal = a_pvVal;
		pstNode->m_pstPrevNode = NULL;
		pstNode->m_pstNextNode = NULL;

		return pstNode;
	}

	/** 노드를 추가한다 */
	static void LLAddNode(STLLNode* a_pstNode, void* a_pvVal) {
		STLLNode* pstNewNode = LLCreateNode(a_pvVal);
		pstNewNode->m_pstPrevNode = a_pstNode;
		pstNewNode->m_pstNextNode = a_pstNode->m_pstNextNode;

		a_pstNode->m_pstNextNode = pstNewNode;
		pstNewNode->m_pstNextNode->m_pstPrevNode = pstNewNode;
	}

	/** 노드를 제거한다 */
	static void LLRemoveNode(STLLNode* a_pstNode) {
		STLLNode* pstNextNode = a_pstNode->m_pstNextNode->m_pstNextNode;
		STLLNode* pstRemoveNode = a_pstNode->m_pstNextNode;

		a_pstNode->m_pstNextNode = pstNextNode;
		pstNextNode->m_pstPrevNode = a_pstNode;

		SAFE_FREE(pstRemoveNode);
	}

	void LLInit(STLinkedList* a_pstLinkedList) {
		memset(a_pstLinkedList, 0, sizeof(STLinkedList));

		a_pstLinkedList->m_pstHeadNode = LLCreateNode(NULL);
		a_pstLinkedList->m_pstTailNode = LLCreateNode(NULL);

		a_pstLinkedList->m_pstHeadNode->m_pstNextNode = a_pstLinkedList->m_pstTailNode;
		a_pstLinkedList->m_pstTailNode->m_pstPrevNode = a_pstLinkedList->m_pstHeadNode;
	}

	void LLDestroy(STLinkedList* a_pstLinkedList) {
		STLLNode* pstNode = a_pstLinkedList->m_pstHeadNode;

		while(pstNode != NULL) {
			STLLNode* pstRemoveNode = pstNode;
			pstNode = pstNode->m_pstNextNode;

			SAFE_FREE(pstRemoveNode);
		}
	}

	bool LLIsValidIdx(STLinkedList* a_pstLinkedList, int a_nIdx) {
		return a_nIdx >= 0 && a_nIdx < a_pstLinkedList->m_nNumVals;
	}

	int LLGetNumVals(STLinkedList* a_pstLinkedList) {
		return a_pstLinkedList->m_nNumVals;
	}

	void* LLGetVal(STLinkedList* a_pstLinkedList, int a_nIdx) {
		assert(LLIsValidIdx(a_pstLinkedList, a_nIdx));
		STLLNode* pstNode = a_pstLinkedList->m_pstHeadNode;

		for(int i = 0; i < a_nIdx; ++i) {
			pstNode = pstNode->m_pstNextNode;
		}

		return pstNode->m_pstNextNode->m_pvVal;
	}

	int LLFindVal(STLinkedList* a_pstLinkedList, void* a_pvVal) {
		STLLNode* pstNode = a_pstLinkedList->m_pstHeadNode;

		for(int i = 0; i < a_pstLinkedList->m_nNumVals; ++i) {
			// 값이 존재 할 경우
			if(pstNode->m_pstNextNode->m_pvVal == a_pvVal) {
				return i;
			}

			pstNode = pstNode->m_pstNextNode;
		}

		return INVALID_IDX;
	}

	void LLAddVal(STLinkedList* a_pstLinkedList, void* a_pvVal) {
		STLLNode* pstNode = a_pstLinkedList->m_pstHeadNode;

		while(pstNode->m_pstNextNode != a_pstLinkedList->m_pstTailNode) {
			pstNode = pstNode->m_pstNextNode;
		}

		LLAddNode(pstNode, a_pvVal);
		a_pstLinkedList->m_nNumVals += 1;
	}

	void LLInsertVal(STLinkedList* a_pstLinkedList, int a_nIdx, void* a_pvVal) {
		assert(LLIsValidIdx(a_pstLinkedList, a_nIdx));
		STLLNode* pstNode = a_pstLinkedList->m_pstHeadNode;

		for(int i = 0; i < a_nIdx; ++i) {
			pstNode = pstNode->m_pstNextNode;
		}

		LLAddNode(pstNode, a_pvVal);
		a_pstLinkedList->m_nNumVals += 1;
	}

	void LLRemoveVal(STLinkedList* a_pstLinkedList, void* a_pvVal) {
		int nIdx = LLFindVal(a_pstLinkedList, a_pvVal);

		// 값이 존재 할 경우
		if(LLIsValidIdx(a_pstLinkedList, nIdx)) {
			LLRemoveValAt(a_pstLinkedList, nIdx);
		}
	}

	void LLRemoveValAt(STLinkedList* a_pstLinkedList, int a_nIdx) {
		assert(LLIsValidIdx(a_pstLinkedList, a_nIdx));
		STLLNode* pstNode = a_pstLinkedList->m_pstHeadNode;

		for(int i = 0; i < a_nIdx; ++i) {
			pstNode = pstNode->m_pstNextNode;
		}

		LLRemoveNode(pstNode);
		a_pstLinkedList->m_nNumVals -= 1;
	}
}
