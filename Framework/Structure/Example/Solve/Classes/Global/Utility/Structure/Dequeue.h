#pragma once

#include "../../Define/KGDefine.h"

namespace Global {
	/** 덱 */
	struct STDequeue {
		int m_nSize;
		int m_nRear;
		int m_nFront;
		int m_nNumVals;

		void** m_pvVals;
	};

	/** 초기화 */
	void DInit(STDequeue* a_pstDequeue);

	/** 제거한다 */
	void DDestroy(STDequeue* a_pstDequeue);

	/** 비어있는지 검사한다 */
	bool DIsEmpty(STDequeue* a_pstDequeue);

	/** 값을 반환한다 */
	void* DPeek(STDequeue* a_pstDequeue);

	/** 값을 추가한다 */
	void DEnqueueFront(STDequeue* a_pstDequeue, void* a_pvVal);

	/** 값을 추가한다 */
	void DEnqueueRear(STDequeue* a_pstDequeue, void* a_pvVal);

	/** 값을 제거한다 */
	void* DDequeueFront(STDequeue* a_pstDequeue);

	/** 값을 제거한다 */
	void* DDequeueRear(STDequeue* a_pstDequeue);
}
