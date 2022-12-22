#pragma once

#include "../../Define/KGDefine.h"

namespace Global {
	/** 이진 트리 순서 */
	enum class EBTOrder {
		NONE = -1,
		PRE,
		IN,
		POST,
		LEVEL,
		MAX_VAL
	};

	/** 이진 트리 노드 */
	struct STBTNode {
		void* m_pvVal;

		STBTNode* m_pstLChildNode;
		STBTNode* m_pstRChildNode;
	};

	/** 이진 탐색 트리 */
	struct STBSearchTree {
		int m_nNumVals;
		STBTNode* m_pstRootNode;
	};

	/** 초기화 */
	void BSTInit(STBSearchTree* a_pstBSearchTree);

	/** 제거한다 */
	void BSTDestroy(STBSearchTree* a_pstBSearchTree);

	/** 순회한다 */
	void BSTEnumerate(STBSearchTree* a_pstBSearchTree, EBTOrder a_eOrder, void(*a_pfnCallback)(STBTNode*));
}
