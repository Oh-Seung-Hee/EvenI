#pragma once

#include "KE12Define.h"
#include "E12Board.h"
#include "E12Tail.h"

/** 뱀 */
struct STE12Snake {
	STE12Vec m_stPos;
	STE12Vec m_stDirection;

	STE12SnakeTail* m_pstTail;
};

/** 뱀을 설정한다 */
void E12SetupSnake(int a_nX, int a_nY, STE12Snake* a_pstOutSnake);

/** 방향을 변경한다 */
void E12SetDirection(int a_nX, int a_nY, STE12Snake* a_pstOutSnake);

/** 꼬리를 추가한다 */
void E12AddTail(STE12Snake* a_pstOutSnake);

/** 뱀을 움직인다 */
void E12MoveSnake(STE12Snake* a_pstOutSnake);

/** 뱀을 그린다 */
void E12DrawSnake(STE12Snake* a_pstSnake, STE12Board* a_pstOutBoard);

/** 뱀을 제거한다 */
void E12DestroySnake(STE12Snake* a_pstSnake);
