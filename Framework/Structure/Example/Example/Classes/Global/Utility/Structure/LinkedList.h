#pragma once

#include "../../Define/KGDefine.h"

namespace Global {
	/** 노드 */
	struct STLLNode {
		void* m_pvVal;

		STLLNode* m_pstPrevNode;
		STLLNode* m_pstNextNode;
	};

	/** 연결 리스트 */
	struct STLinkedList {
		int m_nNumVals;

		STLLNode* m_pstHeadNode;
		STLLNode* m_pstTailNode;
	};

	/** 초기화 */
	void LLInit(STLinkedList* a_pstLinkedList);

	/** 제거한다 */
	void LLDestroy(STLinkedList* a_pstLinkedList);

	/** 인덱스 유효 여부를 검사한다 */
	bool LLIsValidIdx(STLinkedList* a_pstLinkedList, int a_nIdx);

	/** 개수를 반환한다 */
	int LLGetNumVals(STLinkedList* a_pstLinkedList);

	/** 값을 반환한다 */
	void* LLGetVal(STLinkedList* a_pstLinkedList, int a_nIdx);

	/** 값을 탐색한다 */
	int LLFindVal(STLinkedList* a_pstLinkedList, void* a_pvVal);

	/** 값을 추가한다 */
	void LLAddVal(STLinkedList* a_pstLinkedList, void* a_pvVal);

	/** 값을 추가한다 */
	void LLInsertVal(STLinkedList* a_pstLinkedList, int a_nIdx, void* a_pvVal);

	/** 값을 제거한다 */
	void LLRemoveVal(STLinkedList* a_pstLinkedList, void* a_pvVal);

	/** 값을 제거한다 */
	void LLRemoveValAt(STLinkedList* a_pstLinkedList, int a_nIdx);
}
