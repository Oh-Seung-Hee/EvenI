#include "E12Snake.h"

static STE12SnakeTail* E12CreateTail(int a_nX, int a_nY) {
	STE12SnakeTail* pstTail = (STE12SnakeTail*)malloc(sizeof(STE12SnakeTail));
	pstTail->m_stTail.m_stPos.m_nX = a_nX;
	pstTail->m_stTail.m_stPos.m_nY = a_nY;
	pstTail->m_pstNextTail = NULL;

	return pstTail;
}


void E12SetupSnake(int a_nX, int a_nY, STE12Snake* a_pstOutSnake) {
	a_pstOutSnake->m_stPos.m_nX = a_nX;
	a_pstOutSnake->m_stPos.m_nY = a_nY;

	a_pstOutSnake->m_stDirection.m_nX = 0;
	a_pstOutSnake->m_stDirection.m_nY = -1;

	a_pstOutSnake->m_pstTail = NULL;
}

void E12SetDirection(int a_nX, int a_nY, STE12Snake* a_pstOutSnake) {
	a_pstOutSnake->m_stDirection.m_nX = a_nX;
	a_pstOutSnake->m_stDirection.m_nY = a_nY;
}

void E12AddTail(STE12Snake* a_pstOutSnake) {
	// 꼬리가 없을 경우
	if(a_pstOutSnake->m_pstTail == NULL) {
		a_pstOutSnake->m_pstTail = E12CreateTail(a_pstOutSnake->m_stPos.m_nX - a_pstOutSnake->m_stDirection.m_nX, a_pstOutSnake->m_stPos.m_nY - a_pstOutSnake->m_stDirection.m_nY);
	} else {
		STE12SnakeTail* pstTail = a_pstOutSnake->m_pstTail;
		STE12SnakeTail* pstPrevTail = NULL;

		while(pstTail->m_pstNextTail != NULL) {
			pstPrevTail = pstTail;
			pstTail = pstTail->m_pstNextTail;
		}

		STE12Vec stPrevPos = (pstPrevTail != NULL) ? pstPrevTail->m_stTail.m_stPos : a_pstOutSnake->m_pstTail->m_stTail.m_stPos;

		STE12Vec stDirection = {
			pstTail->m_stTail.m_stPos.m_nX - stPrevPos.m_nX, pstTail->m_stTail.m_stPos.m_nY - stPrevPos.m_nY
		};

		pstTail->m_pstNextTail = E12CreateTail(pstTail->m_stTail.m_stPos.m_nX + stDirection.m_nX, pstTail->m_stTail.m_stPos.m_nY + stDirection.m_nY);
	}
}

void E12MoveSnake(STE12Snake* a_pstOutSnake) {
	STE12Vec stPos = a_pstOutSnake->m_stPos;
	STE12SnakeTail* pstTail = a_pstOutSnake->m_pstTail;

	while(pstTail != NULL) {
		STE12Vec stPrevPos = pstTail->m_stTail.m_stPos;
		pstTail->m_stTail.m_stPos = stPos;

		stPos = stPrevPos;
		pstTail = pstTail->m_pstNextTail;
	}

	a_pstOutSnake->m_stPos.m_nX += a_pstOutSnake->m_stDirection.m_nX;
	a_pstOutSnake->m_stPos.m_nY += a_pstOutSnake->m_stDirection.m_nY;
}

void E12DrawSnake(STE12Snake* a_pstSnake, STE12Board* a_pstOutBoard) {
	STE12SnakeTail* pstTail = a_pstSnake->m_pstTail;
	a_pstOutBoard->m_pchBoard[E12_2D_TO_IDX(a_pstSnake->m_stPos.m_nY, a_pstSnake->m_stPos.m_nX, a_pstOutBoard->m_stSize.m_nWidth)] = '@';

	while(pstTail != NULL) {
		E12DrawTail(&pstTail->m_stTail, a_pstOutBoard);
		pstTail = pstTail->m_pstNextTail;
	}
}

void E12DestroySnake(STE12Snake* a_pstSnake) {
	STE12SnakeTail* pstTail = a_pstSnake->m_pstTail;

	while(pstTail != NULL) {
		STE12SnakeTail* pstRemoveTail = pstTail;
		pstTail = pstTail->m_pstNextTail;

		E12_SAFE_FREE(pstRemoveTail);
	}
}
