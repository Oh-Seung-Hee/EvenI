#pragma once

#include "../../Define/KGDefine.h"

namespace Global {
	/** 큐 */
	struct STQueue {
		int m_nSize;
		int m_nRear;
		int m_nFront;
		int m_nNumVals;

		void** m_pvVals;
	};

	/** 초기화 */
	void QInit(STQueue* a_pstQueue);

	/** 제거한다 */
	void QDestroy(STQueue* a_pstQueue);

	/** 빈 스택 여부를 검사한다 */
	bool QIsEmpty(STQueue* a_pstQueue);

	/** 값을 추가한다 */
	void QEnqueue(STQueue* a_pstQueue, void* a_pvVal);

	/** 값을 제거한다 */
	void* QDequeue(STQueue* a_pstQueue);
}
