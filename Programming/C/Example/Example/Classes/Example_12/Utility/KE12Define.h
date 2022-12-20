#pragma once

#include "../../Global/Define/KGDefine.h"

// 인덱스 변환
#define E12_2D_TO_IDX(ROW, COL, NUM_COLS)			(((ROW) * (NUM_COLS)) + (COL))

// 메모리 관리
#define E12_SAFE_FREE(TARGET)			if((TARGET) != NULL) { free((TARGET)); (TARGET) = NULL; }

/** 상태 */
enum class E12State {
	NONE = -1,
	PLAY,
	GAME_OVER,
	MAX_VAL
};

/** 위치 */
struct STE12Vec {
	int m_nX;
	int m_nY;
};

/** 크기 */
struct STE12Size {
	int m_nWidth;
	int m_nHeight;
};
