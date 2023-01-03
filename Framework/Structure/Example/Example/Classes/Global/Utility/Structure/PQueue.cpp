#include "PQueue.h"

namespace Global {
	/** 크기를 변경한다 */
	static void PQResize(STPQueue* a_pstPQueue, int a_nSize) {
		void** pvVals = (void**)malloc(sizeof(void*) * a_nSize);

		for(int i = 0; i < a_nSize && i < a_pstPQueue->m_nNumVals; ++i) {
			pvVals[i] = a_pstPQueue->m_pvVals[i];
		}

		SAFE_FREE(a_pstPQueue->m_pvVals);

		a_pstPQueue->m_nSize = a_nSize;
		a_pstPQueue->m_nNumVals = (a_nSize < a_pstPQueue->m_nNumVals) ? a_nSize : a_pstPQueue->m_nNumVals;
		a_pstPQueue->m_pvVals = pvVals;

	}
	void PQInit(STPQueue* a_pstPQueue, COMPARE_FUNC a_pfnCompare) {
		memset(a_pstPQueue, 0, sizeof(STArrayList));

		a_pstPQueue->m_nSize = 5;
		a_pstPQueue->m_pvVals = (void**)malloc(sizeof(void*) * a_pstPQueue->m_nSize);
		a_pstPQueue->m_pfnCompare = a_pfnCompare;
	}

	void PQDestroy(STPQueue* a_pstPQueue) {
		SAFE_FREE(a_pstPQueue->m_pvVals);
	}

	bool PQIsEmpty(STPQueue* a_pstPQueue) {
		return a_pstPQueue->m_nNumVals <= 0;
	}

	void* PQPeek(STPQueue* a_pstPQueue) {
		assert(!PQIsEmpty(a_pstPQueue));
		return a_pstPQueue->m_pvVals[0];
	}

	void PQEnqueue(STPQueue* a_pstPQueue, void* a_pvVal) {
		// 우선 순위 큐가 가득 찼을 경우
		if(a_pstPQueue->m_nNumVals >= a_pstPQueue->m_nSize) {
			PQResize(a_pstPQueue, a_pstPQueue->m_nSize * 2);
		}

		int nIdx = a_pstPQueue->m_nNumVals;
		a_pstPQueue->m_pvVals[a_pstPQueue->m_nNumVals++] = a_pvVal;

		while(nIdx > 0) {
			int nParentIdx = (nIdx - 1) / 2;

			// 값 교환이 불가능 할 경우
			if(a_pstPQueue->m_pfnCompare(a_pstPQueue->m_pvVals[nParentIdx], a_pstPQueue->m_pvVals[nIdx]) <= 0) {
				break;
			}

			void* pvTemp = a_pstPQueue->m_pvVals[nIdx];
			a_pstPQueue->m_pvVals[nIdx] = a_pstPQueue->m_pvVals[nParentIdx];
			a_pstPQueue->m_pvVals[nParentIdx] = pvTemp;

			nIdx = nParentIdx;
		}
	}

	void* PQDequeue(STPQueue* a_pstPQueue) {
		assert(!PQIsEmpty(a_pstPQueue));
		void* pvVal = a_pstPQueue->m_pvVals[0];
		a_pstPQueue->m_pvVals[0] = a_pstPQueue->m_pvVals[--a_pstPQueue->m_nNumVals];

		int nIdx = 0;

		while(nIdx < a_pstPQueue->m_nNumVals / 2) {
			int nCompareIdx = (nIdx * 2) + 1;

			// 오른쪽 자식이 존재 할 경우
			if(nCompareIdx + 1 < a_pstPQueue->m_nNumVals) {
				int nRChildIdx = nCompareIdx + 1;
				nCompareIdx = (a_pstPQueue->m_pfnCompare(a_pstPQueue->m_pvVals[nCompareIdx], a_pstPQueue->m_pvVals[nRChildIdx]) <= 0) ? nCompareIdx : nRChildIdx;
			}

			// 값 교환이 불가능 할 경우
			if(a_pstPQueue->m_pfnCompare(a_pstPQueue->m_pvVals[nIdx], a_pstPQueue->m_pvVals[nCompareIdx]) <= 0) {
				break;
			}

			void* pvTemp = a_pstPQueue->m_pvVals[nIdx];
			a_pstPQueue->m_pvVals[nIdx] = a_pstPQueue->m_pvVals[nCompareIdx];
			a_pstPQueue->m_pvVals[nCompareIdx] = pvTemp;

			nIdx = nCompareIdx;
		}

		return pvVal;
	}
}
