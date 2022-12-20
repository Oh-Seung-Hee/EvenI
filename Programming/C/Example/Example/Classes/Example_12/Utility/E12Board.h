#pragma once

#include "KE12Define.h"

/** 보드 */
struct STE12Board {
	char* m_pchBoard;
	STE12Size m_stSize;
};

/** 보드를 생성한다 */
void E12SetupBoard(int a_nWidth, int a_nHeight, STE12Board* a_pstOutBoard);

/** 보드를 지운다 */
void E12ClearBoard(STE12Board* a_pstBoard);

/** 보드를 그린다 */
void E12DrawBoard(STE12Board* a_pstBoard);

/** 외곽선을 그린다 */
void E12DrawOutline(STE12Board* a_pstBoard);

/** 보드를 제거한다 */
void E12DestroyBoard(STE12Board* a_pstBoard);
