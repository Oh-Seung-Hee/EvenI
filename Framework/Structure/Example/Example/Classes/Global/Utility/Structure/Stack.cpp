#include "Stack.h"

namespace Global {
	/** 크기를 변경한다 */
	static void SResize(STStack* a_pstStack, int a_nSize) {
		void** pvVals = (void**)malloc(sizeof(void*) * a_nSize);

		for(int i = 0; i < a_nSize && i < a_pstStack->m_nNumVals; ++i) {
			pvVals[i] = a_pstStack->m_pvVals[i];
		}

		SAFE_FREE(a_pstStack->m_pvVals);

		a_pstStack->m_nSize = a_nSize;
		a_pstStack->m_nNumVals = (a_nSize < a_pstStack->m_nNumVals) ? a_nSize : a_pstStack->m_nNumVals;

		a_pstStack->m_pvVals = pvVals;
	}

	void SInit(STStack* a_pstStack) {
		memset(a_pstStack, 0, sizeof(STStack));

		a_pstStack->m_nSize = 5;
		a_pstStack->m_pvVals = (void**)malloc(sizeof(void*) * a_pstStack->m_nSize);
	}

	void SDestroy(STStack* a_pstStack) {
		SAFE_FREE(a_pstStack->m_pvVals);
	}

	bool SIsEmpty(STStack* a_pstStack) {
		return a_pstStack->m_nNumVals <= 0;
	}

	void* SPeek(STStack* a_pstStack) {
		assert(!SIsEmpty(a_pstStack));
		return a_pstStack->m_pvVals[a_pstStack->m_nNumVals - 1];
	}

	void SPush(STStack* a_pstStack, void* a_pvVal) {
		// 스택이 가득 찼을 경우
		if(a_pstStack->m_nNumVals >= a_pstStack->m_nSize) {
			SResize(a_pstStack, a_pstStack->m_nSize * 2);
		}

		a_pstStack->m_pvVals[a_pstStack->m_nNumVals++] = a_pvVal;
	}

	void* SPop(STStack* a_pstStack) {
		assert(!SIsEmpty(a_pstStack));
		return a_pstStack->m_pvVals[--a_pstStack->m_nNumVals];
	}
}
