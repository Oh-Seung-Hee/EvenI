#include "Example_12.h"
#include "Utility/E12Board.h"
#include "Utility/E12Snake.h"
#include "Utility/E12Tail.h"

#define E12_WIDTH			(65)
#define E12_HEIGHT			(25)

namespace E12 {
	int Example_12(int argc, char* args[]) {
		float fPrevTime = clock() / (float)CLOCKS_PER_SEC;
		E12State eState = E12State::PLAY;

		STE12Board stBoard;
		STE12Snake stSnake;
		STE12Tail stTail;

		E12SetupBoard(E12_WIDTH, E12_HEIGHT, &stBoard);
		E12SetupSnake(E12_WIDTH / 2, E12_HEIGHT / 2, &stSnake);
		E12SetupTail(rand() % (E12_WIDTH - 2) + 1, rand() % (E12_HEIGHT - 2) + 1, &stTail);

		do {
			COORD stCursorPos;
			ZeroMemory(&stCursorPos, sizeof(stCursorPos));

			__try {
				float fTime = clock() / (float)CLOCKS_PER_SEC;
				float fDeltaTime = fTime - fPrevTime;

				E12ClearBoard(&stBoard);
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), stCursorPos);

				// 이동이 가능 할 경우
				if(fDeltaTime >= 0.1f) {
					fPrevTime = fTime;
					E12MoveSnake(&stSnake);
				}

				// 꼬리를 획득했을 경우
				if(stSnake.m_stPos.m_nX == stTail.m_stPos.m_nX && stSnake.m_stPos.m_nY == stTail.m_stPos.m_nY) {
					E12AddTail(&stSnake);
					E12SetupTail(rand() % (E12_WIDTH - 2) + 1, rand() % (E12_HEIGHT - 2) + 1, &stTail);
				}

				STE12Vec stDirection = stSnake.m_stDirection;

				// 수평 방향 키를 눌렀을 경우
				if(GetAsyncKeyState('A') & 0x8000 || GetAsyncKeyState('D') & 0x8000) {
					stDirection.m_nX = (GetAsyncKeyState('A') & 0x8000) ? -1 : 1;
					stDirection.m_nY = 0;
				}
				// 수직 방향 키를 눌렀을 경우
				else if(GetAsyncKeyState('W') & 0x8000 || GetAsyncKeyState('S') & 0x8000) {
					stDirection.m_nX = 0;
					stDirection.m_nY = (GetAsyncKeyState('W') & 0x8000) ? -1 : 1;
				}

				E12SetDirection(stDirection.m_nX, stDirection.m_nY, &stSnake);

				E12DrawSnake(&stSnake, &stBoard);
				E12DrawTail(&stTail, &stBoard);
				E12DrawOutline(&stBoard);

				// 게임이 종료 되었을 경우
				if(stBoard.m_pchBoard[E12_2D_TO_IDX(stSnake.m_stPos.m_nY, stSnake.m_stPos.m_nX, stBoard.m_stSize.m_nWidth)] != '@') {
					eState = E12State::GAME_OVER;
					stBoard.m_pchBoard[E12_2D_TO_IDX(stSnake.m_stPos.m_nY, stSnake.m_stPos.m_nX, stBoard.m_stSize.m_nWidth)] = '@';
				}
			} __finally {
				E12DrawBoard(&stBoard);
			}
		} while(eState != E12State::GAME_OVER);

		E12DestroyBoard(&stBoard);
		E12DestroySnake(&stSnake);

		return 0;
	}
}
