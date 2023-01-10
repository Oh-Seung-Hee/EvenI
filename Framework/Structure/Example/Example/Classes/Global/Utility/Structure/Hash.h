#pragma once

#include "../../Define/KGDefine.h"
#include "ArrayList.h"
#include "LinkedList.h"

//#define HASH_OPEN_ADDRESS
#define HASH_CHAIN

#define HASH_SIZE			(10)

namespace Global {
	/** 해시 */
	struct STHash {
		int m_nSize;
		int m_nNumVals;

		KEY_FUNC m_pfnKey;
		COMPARE_FUNC m_pfnCompare;

#if defined HASH_OPEN_ADDRESS
		STArrayList m_oSlotList;
#elif defined HASH_CHAIN
		STLinkedList m_astValLists[HASH_SIZE];
#endif // #if defined HASH_OPEN_ADDRESS
	};

	/** 초기화 */
	void HInit(STHash* a_pstHash, KEY_FUNC a_pfnKey, COMPARE_FUNC a_pfnCompare);

	/** 제거한다 */
	void HDestroy(STHash* a_pstHash);

	/** 비어있는지 검사한다 */
	bool HIsEmpty(STHash* a_pstHash);

	/** 개수를 반환한다 */
	int HGetNumVals(STHash* a_pstHash);

	/** 값을 반환한다 */
	void* HGetVal(STHash* a_pstHash, void* a_pvKey);

	/** 값을 추가한다 */
	void HAddVal(STHash* a_pstHash, void* a_pvKey, void* a_pvVal);

	/** 값을 제거한다 */
	void HRemoveVal(STHash* a_pstHash, void* a_pvKey);
}
