#include "ArrayList.h"

namespace Global {
	/** 크기를 변경한다 */
	static void ALResize(STArrayList* a_pstArrayList, int a_nSize) {
		void** pvVals = (void**)malloc(sizeof(void*) * a_nSize);

		for(int i = 0; i < a_nSize && i < a_pstArrayList->m_nNumVals; ++i) {
			pvVals[i] = a_pstArrayList->m_pvVals[i];
		}

		SAFE_FREE(a_pstArrayList->m_pvVals);

		a_pstArrayList->m_nSize = a_nSize;
		a_pstArrayList->m_nNumVals = (a_pstArrayList->m_nSize < a_pstArrayList->m_nNumVals) ? a_pstArrayList->m_nSize : a_pstArrayList->m_nNumVals;
		a_pstArrayList->m_pvVals = pvVals;
	}

	void ALInit(STArrayList* a_pstArrayList) {
		memset(a_pstArrayList, 0, sizeof(STArrayList));

		a_pstArrayList->m_nSize = 5;
		a_pstArrayList->m_pvVals = (void**)malloc(sizeof(void*) * a_pstArrayList->m_nSize);
	}

	void ALDestroy(STArrayList* a_pstArrayList) {
		SAFE_FREE(a_pstArrayList->m_pvVals);
	}

	bool ALIsValidIdx(STArrayList* a_pstArrayList, int a_nIdx) {
		return a_nIdx >= 0 && a_nIdx < a_pstArrayList->m_nNumVals;
	}

	int ALGetNumVals(STArrayList* a_pstArrayList) {
		return a_pstArrayList->m_nNumVals;
	}

	void* ALGetVal(STArrayList* a_pstArrayList, int a_nIdx) {
		assert(ALIsValidIdx(a_pstArrayList, a_nIdx));
		return a_pstArrayList->m_pvVals[a_nIdx];
	}

	int ALFindVal(STArrayList* a_pstArrayList, void* a_pvVal) {
		for(int i = 0; i < a_pstArrayList->m_nNumVals; ++i) {
			// 값이 존재 할 경우
			if(a_pstArrayList->m_pvVals[i] == a_pvVal) {
				return i;
			}
		}

		return INVALID_IDX;
	}

	void ALAddVal(STArrayList* a_pstArrayList, void* a_pvVal) {
		// 배열이 가득 찼을 경우
		if(a_pstArrayList->m_nNumVals >= a_pstArrayList->m_nSize) {
			ALResize(a_pstArrayList, a_pstArrayList->m_nSize * 2);
		}

		a_pstArrayList->m_pvVals[a_pstArrayList->m_nNumVals++] = a_pvVal;
	}

	void ALInsertVal(STArrayList* a_pstArrayList, int a_nIdx, void* a_pvVal) {
		assert(ALIsValidIdx(a_pstArrayList, a_nIdx));

		// 배열이 가득 찼을 경우
		if(a_pstArrayList->m_nNumVals >= a_pstArrayList->m_nSize) {
			ALResize(a_pstArrayList, a_pstArrayList->m_nSize * 2);
		}

		for(int i = a_pstArrayList->m_nNumVals; i > a_nIdx; --i) {
			a_pstArrayList->m_pvVals[i] = a_pstArrayList->m_pvVals[i - 1];
		}

		a_pstArrayList->m_pvVals[a_nIdx] = a_pvVal;
		a_pstArrayList->m_nNumVals += 1;
	}

	void ALRemoveVal(STArrayList* a_pstArrayList, void* a_pvVal) {
		int nIdx = ALFindVal(a_pstArrayList, a_pvVal);

		// 값이 존재 할 경우
		if(ALIsValidIdx(a_pstArrayList, nIdx)) {
			ALRemoveValAt(a_pstArrayList, nIdx);
		}
	}

	void ALRemoveValAt(STArrayList* a_pstArrayList, int a_nIdx) {
		for(int i = a_nIdx; i < a_pstArrayList->m_nNumVals - 1; ++i) {
			a_pstArrayList->m_pvVals[i] = a_pstArrayList->m_pvVals[i + 1];
		}

		a_pstArrayList->m_nNumVals -= 1;
	}
}
