#include "Dequeue.h"

namespace Global {
	/** 크기를 변경한다 */
	static void DResize(STDequeue* a_pstDequeue, int a_nSize) {
		void** pvVals = (void**)malloc(sizeof(void*) * a_nSize);

		for(int i = 0; i < a_nSize && i < a_pstDequeue->m_nNumVals; ++i) {
			pvVals[i] = a_pstDequeue->m_pvVals[(a_pstDequeue->m_nFront + i) % a_pstDequeue->m_nSize];
		}

		SAFE_FREE(a_pstDequeue->m_pvVals);

		a_pstDequeue->m_nSize = a_nSize;
		a_pstDequeue->m_nNumVals = (a_nSize < a_pstDequeue->m_nNumVals) ? a_nSize : a_pstDequeue->m_nNumVals;

		a_pstDequeue->m_nRear = a_pstDequeue->m_nNumVals % a_nSize;
		a_pstDequeue->m_nFront = 0;

		a_pstDequeue->m_pvVals = pvVals;
	}

	void DInit(STDequeue* a_pstDequeue) {
		memset(a_pstDequeue, 0, sizeof(STDequeue));

		a_pstDequeue->m_nSize = 5;
		a_pstDequeue->m_pvVals = (void**)malloc(sizeof(void*) * a_pstDequeue->m_nSize);
	}

	void DDestroy(STDequeue* a_pstDequeue) {
		SAFE_FREE(a_pstDequeue->m_pvVals);
	}

	bool DIsEmpty(STDequeue* a_pstDequeue) {
		return a_pstDequeue->m_nNumVals <= 0;
	}

	void* DPeek(STDequeue* a_pstDequeue) {
		assert(!DIsEmpty(a_pstDequeue));
		return a_pstDequeue->m_pvVals[a_pstDequeue->m_nFront];
	}

	void DEnqueueFront(STDequeue* a_pstDequeue, void* a_pvVal) {
		// 덱이 가득 찼을 경우
		if(a_pstDequeue->m_nNumVals >= a_pstDequeue->m_nSize) {
			DResize(a_pstDequeue, a_pstDequeue->m_nSize * 2);
		}

		a_pstDequeue->m_nFront = (a_pstDequeue->m_nFront + (a_pstDequeue->m_nSize - 1)) % a_pstDequeue->m_nSize;
		a_pstDequeue->m_nNumVals += 1;

		a_pstDequeue->m_pvVals[a_pstDequeue->m_nFront] = a_pvVal;
	}

	void DEnqueueRear(STDequeue* a_pstDequeue, void* a_pvVal) {
		// 덱이 가득 찼을 경우
		if(a_pstDequeue->m_nNumVals >= a_pstDequeue->m_nSize) {
			DResize(a_pstDequeue, a_pstDequeue->m_nSize * 2);
		}

		a_pstDequeue->m_pvVals[a_pstDequeue->m_nRear] = a_pvVal;

		a_pstDequeue->m_nRear = (a_pstDequeue->m_nRear + 1) % a_pstDequeue->m_nSize;
		a_pstDequeue->m_nNumVals += 1;
	}

	void* DDequeueFront(STDequeue* a_pstDequeue) {
		assert(!DIsEmpty(a_pstDequeue));
		void* pvVal = a_pstDequeue->m_pvVals[a_pstDequeue->m_nFront];

		a_pstDequeue->m_nFront = (a_pstDequeue->m_nFront + 1) % a_pstDequeue->m_nSize;
		a_pstDequeue->m_nNumVals -= 1;

		return pvVal;
	}

	void* DDequeueRear(STDequeue* a_pstDequeue) {
		assert(!DIsEmpty(a_pstDequeue));

		a_pstDequeue->m_nRear = (a_pstDequeue->m_nRear + (a_pstDequeue->m_nSize - 1)) % a_pstDequeue->m_nSize;
		a_pstDequeue->m_nNumVals -= 1;

		return a_pstDequeue->m_pvVals[a_pstDequeue->m_nRear];
	}
}
