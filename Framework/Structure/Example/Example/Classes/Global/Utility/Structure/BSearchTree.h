#pragma once

#include "../../Define/KGDefine.h"

namespace Global {
	/** 이진 탐색 트리 순서 */
	enum class EBSTOrder {
		NONE = -1,
		PRE,
		IN,
		POST,
		LEVEL,
		MAX_VAL
	};

	/** 이진 탐색 트리 */
	struct STBSearchTree {
		int m_nNumVals;
		COMPARE_FUNC m_pfnCompare;

		STBTreeNode* m_pstRootNode;
	};

	/** 초기화 */
	void BSTInit(STBSearchTree* a_pstBSearchTree, COMPARE_FUNC a_pfnCompare);

	/** 제거한다 */
	void BSTDestroy(STBSearchTree* a_pstBSearchTree);

	/** 비어있는지 검사한다 */
	bool BSTIsEmpty(STBSearchTree* a_pstBSearchTree);

	/** 개수를 반환한다 */
	int BSTGetNumVals(STBSearchTree* a_pstBSearchTree);

	/** 값을 반환한다 */
	void* BSTGetVal(STBSearchTree* a_pstBSearchTree, void* a_pvKey);

	/** 값을 추가한다 */
	void BSTAddVal(STBSearchTree* a_pstBSearchTree, void* a_pvKey, void* a_pvVal);

	/** 값을 제거한다 */
	void BSTRemoveVal(STBSearchTree* a_pstBSearchTree, void* a_pvKey);

	/** 순회한다 */
	void BSTEnumerate(STBSearchTree* a_pstBSearchTree, EBSTOrder a_eOrder, void(*a_pfnCallback)(STBTreeNode*));
}
