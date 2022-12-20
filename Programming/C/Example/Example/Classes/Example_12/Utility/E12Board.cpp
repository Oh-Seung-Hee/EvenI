#include "E12Board.h"

void E12SetupBoard(int a_nWidth, int a_nHeight, STE12Board* a_pstOutBoard) {
	a_pstOutBoard->m_stSize.m_nWidth = a_nWidth;
	a_pstOutBoard->m_stSize.m_nHeight = a_nHeight;

	a_pstOutBoard->m_pchBoard = (char*)malloc(sizeof(char) * (a_nWidth * a_nHeight));
}

void E12ClearBoard(STE12Board* a_pstBoard) {
	memset(a_pstBoard->m_pchBoard, ' ', sizeof(char) * (a_pstBoard->m_stSize.m_nWidth * a_pstBoard->m_stSize.m_nHeight));
}

void E12DrawBoard(STE12Board* a_pstBoard) {
	for(int i = 0; i < a_pstBoard->m_stSize.m_nHeight; ++i) {
		for(int j = 0; j < a_pstBoard->m_stSize.m_nWidth; ++j) {
			printf("%c", a_pstBoard->m_pchBoard[E12_2D_TO_IDX(i, j, a_pstBoard->m_stSize.m_nWidth)]);
		}

		printf("\n");
	}
}

void E12DrawOutline(STE12Board* a_pstBoard) {
	for(int i = 0; i < a_pstBoard->m_stSize.m_nWidth; ++i) {
		a_pstBoard->m_pchBoard[E12_2D_TO_IDX(0, i, a_pstBoard->m_stSize.m_nWidth)] = '#';
		a_pstBoard->m_pchBoard[E12_2D_TO_IDX(a_pstBoard->m_stSize.m_nHeight - 1, i, a_pstBoard->m_stSize.m_nWidth)] = '#';
	}

	for(int i = 0; i < a_pstBoard->m_stSize.m_nHeight; ++i) {
		a_pstBoard->m_pchBoard[E12_2D_TO_IDX(i, 0, a_pstBoard->m_stSize.m_nWidth)] = '#';
		a_pstBoard->m_pchBoard[E12_2D_TO_IDX(i, a_pstBoard->m_stSize.m_nWidth - 1, a_pstBoard->m_stSize.m_nWidth)] = '#';
	}
}

void E12DestroyBoard(STE12Board* a_pstBoard) {
	E12_SAFE_FREE(a_pstBoard->m_pchBoard);
}
