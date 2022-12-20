#pragma once

#include "../../Define/KGDefine.h"

namespace Global {
	/** 배열 리스트 */
	struct STArrayList {
		int m_nSize;
		int m_nNumVals;

		void** m_pvVals;
	};

	/** 초기화 */
	void ALInit(STArrayList* a_pstArrayList);

	/** 제거한다 */
	void ALDestroy(STArrayList* a_pstArrayList);

	/** 인덱스 유효 여부를 검사한다 */
	bool ALIsValidIdx(STArrayList* a_pstArrayList, int a_nIdx);

	/** 개수를 반환한다 */
	int ALGetNumVals(STArrayList* a_pstArrayList);

	/** 값을 반환한다 */
	void* ALGetVal(STArrayList* a_pstArrayList, int a_nIdx);

	/** 값을 탐색한다 */
	int ALFindVal(STArrayList* a_pstArrayList, void* a_pvVal);

	/** 값을 추가한다 */
	void ALAddVal(STArrayList* a_pstArrayList, void* a_pvVal);

	/** 값을 추가한다 */
	void ALInsertVal(STArrayList* a_pstArrayList, int a_nIdx, void* a_pvVal);

	/** 값을 제거한다 */
	void ALRemoveVal(STArrayList* a_pstArrayList, void* a_pvVal);

	/** 값을 제거한다 */
	void ALRemoveValAt(STArrayList* a_pstArrayList, int a_nIdx);
}
