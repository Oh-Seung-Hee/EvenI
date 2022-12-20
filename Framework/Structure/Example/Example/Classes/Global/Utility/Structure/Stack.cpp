#include "Stack.h"

namespace Global {
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

	void SPush(STStack* a_pstStack, void* a_pvVal) {
		// 스택이 가득 찼을 경우
		if(a_pstStack->m_nNumVals >= a_pstStack->m_nSize) {
			a_pstStack->m_nSize *= 2;
			a_pstStack->m_pvVals = (void**)realloc(a_pstStack->m_pvVals, sizeof(void*) * a_pstStack->m_nSize);
		}

		a_pstStack->m_pvVals[a_pstStack->m_nNumVals++] = a_pvVal;
	}

	void* SPop(STStack* a_pstStack) {
		assert(!SIsEmpty(a_pstStack));
		return a_pstStack->m_pvVals[--a_pstStack->m_nNumVals];
	}
}
