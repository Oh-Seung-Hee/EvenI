#pragma once

#include "../../Define/KGDefine.h"
#include "LinkedList.h"

#define HASH_OPEN_ADDRESS
#define HASH_CHAIN

#define HASH_SIZE			(10)

namespace Global {
	/** 해시 */
	struct STHash {
		int m_nSize;
		int m_nNumVals;

		COMPARE_FUNC m_pfnCompare;

#if defined HASH_OPEN_ADDRESS

#elif defined HASH_CHAIN
		STLinkedList m_stValLists[HASH_SIZE];
#endif // #if defined HASH_OPEN_ADDRESS
	};

	/** 초기화 */
	void HInit(STHash* a_pstHash, COMPARE_FUNC a_pfnCompare);

	/** 제거한다 */
	void HDestroy(STHash* a_pstHash);
}
