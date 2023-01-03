#pragma once

#include "../../Define/KGDefine.h"
#include "ArrayList.h"

namespace Global {
	/** 우선 순위 큐 */
	struct STPQueue {
		int m_nSize;
		int m_nNumVals;

		void** m_pvVals;
		COMPARE_FUNC m_pfnCompare;
	};

	/** 초기화 */
	void PQInit(STPQueue* a_pstPQueue, COMPARE_FUNC a_pfnCompare);

	/** 제거한다 */
	void PQDestroy(STPQueue* a_pstPQueue);

	/** 비어있는지 검사한다 */
	bool PQIsEmpty(STPQueue* a_pstPQueue);

	/** 값을 반환한다 */
	void* PQPeek(STPQueue* a_pstPQueue);

	/** 값을 추가한다 */
	void PQEnqueue(STPQueue* a_pstPQueue, void* a_pvVal);

	/** 값을 제거한다 */
	void* PQDequeue(STPQueue* a_pstPQueue);
}
