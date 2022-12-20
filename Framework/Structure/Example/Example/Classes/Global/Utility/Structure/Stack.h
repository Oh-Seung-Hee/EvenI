#pragma once

#include "../../Define/KGDefine.h"

namespace Global {
	/** 스택 */
	struct STStack {
		int m_nSize;
		int m_nNumVals;

		void** m_pvVals;
	};

	/** 초기화 */
	void SInit(STStack* a_pstStack);

	/** 제거한다 */
	void SDestroy(STStack* a_pstStack);

	/** 빈 스택 여부를 검사한다 */
	bool SIsEmpty(STStack* a_pstStack);

	/** 값을 추가한다 */
	void SPush(STStack* a_pstStack, void* a_pvVal);

	/** 값을 제거한다 */
	void* SPop(STStack* a_pstStack);
}
