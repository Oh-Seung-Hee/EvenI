#include "E12Tail.h"

void E12SetupTail(int a_nX, int a_nY, STE12Tail* a_pstOutTail) {
	a_pstOutTail->m_stPos.m_nX = a_nX;
	a_pstOutTail->m_stPos.m_nY = a_nY;
}

void E12DrawTail(STE12Tail* a_pstTail, STE12Board* a_pstOutBoard) {
	a_pstOutBoard->m_pchBoard[E12_2D_TO_IDX(a_pstTail->m_stPos.m_nY, a_pstTail->m_stPos.m_nX, a_pstOutBoard->m_stSize.m_nWidth)] = '*';
}
