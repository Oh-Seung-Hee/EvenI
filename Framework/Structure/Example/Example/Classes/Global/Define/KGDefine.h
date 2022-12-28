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
	/** 이진 트리 노드 */
	struct STBTNode {
		void* m_pvKey;
		void* m_pvVal;

		STBTNode* m_pstLChildNode;
		STBTNode* m_pstRChildNode;
	};
}
