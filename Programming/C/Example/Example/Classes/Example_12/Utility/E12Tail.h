#pragma once

#include "KE12Define.h"
#include "E12Board.h"

/** 꼬리 */
struct STE12Tail {
	STE12Vec m_stPos;
};

/** 뱀 꼬리 */
struct STE12SnakeTail {
	STE12Tail m_stTail;
	STE12SnakeTail* m_pstNextTail;
};

/** 꼬리를 설정한다 */
void E12SetupTail(int a_nX, int a_nY, STE12Tail* a_pstOutTail);

/** 꼬리를 그린다 */
void E12DrawTail(STE12Tail* a_pstTail, STE12Board* a_pstOutBoard);
