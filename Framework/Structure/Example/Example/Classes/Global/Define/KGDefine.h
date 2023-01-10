#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define INVALID_IDX			(-1)

// 메모리 관리
#define SAFE_FREE(TARGET)			if((TARGET) != NULL) { free((TARGET)); (TARGET) = NULL; }

namespace Global {
	/** 해시 슬롯 상태 */
	enum class EHSlotState {
		NONE = -1,
		EMPTY,
		USE,
		DELETED,
		MAX_VAL
	};

	/** 해시 슬롯 */
	struct STHSlot {
		void* m_pvKey;
		void* m_pvVal;

		EHSlotState m_eSlotState;
	};

	/** 이진 트리 노드 */
	struct STBTreeNode {
		void* m_pvKey;
		void* m_pvVal;

		STBTreeNode* m_pstLChildNode;
		STBTreeNode* m_pstRChildNode;
	};

	typedef int(*KEY_FUNC)(void*);
	typedef int(*COMPARE_FUNC)(void*, void*);
}
