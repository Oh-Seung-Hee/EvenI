#include "Hash.h"

namespace Global {
	void HInit(STHash* a_pstHash, KEY_FUNC a_pfnKey, COMPARE_FUNC a_pfnCompare) {
		memset(a_pstHash, 0, sizeof(STHash));

#if defined HASH_OPEN_ADDRESS

#elif defined HASH_CHAIN
		for(int i = 0; i < HASH_SIZE; ++i) {
			LLInit(&a_pstHash->m_astValLists[i], a_pfnCompare);
		}
#endif // #if defined HASH_OPEN_ADDRESS
	}

	void HDestroy(STHash* a_pstHash) {
#if defined HASH_OPEN_ADDRESS

#elif defined HASH_CHAIN
		for(int i = 0; i < HASH_SIZE; ++i) {
			LLDestroy(&a_pstHash->m_astValLists[i]);
		}
#endif // #if defined HASH_OPEN_ADDRESS
	}

	bool HIsEmpty(STHash* a_pstHash) {
		return a_pstHash->m_nNumVals <= 0;
	}

	int HGetNumVals(STHash* a_pstHash) {
		return a_pstHash->m_nNumVals;
	}

	void* HGetVal(STHash* a_pstHash, void* a_pvKey) {
		return nullptr;
	}

	void HAddVal(STHash* a_pstHash, void* a_pvKey, void* a_pvVal) {
		int nKey = a_pstHash->m_pfnKey(a_pvKey);

#if defined HASH_OPEN_ADDRESS

#elif defined HASH_CHAIN

#endif // #if defined HASH_OPEN_ADDRESS
	}

	void HRemoveVal(STHash* a_pstHash, void* a_pvKey) {

	}
}
