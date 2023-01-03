//#define S09_01
//#define S09_02
#define S09_03

#include "Solve_09.h"

namespace S09 {
#if defined S09_01
	/** 문자열을 출력한다 */
	void PrintDigitStrs(const char* a_pszDigitStr, const char* a_pszStr) {
		for(int i = 0; i < strlen(a_pszStr); ++i) {
			char szStr[100] = "";

			// 숫자 일 경우
			if(isdigit(a_pszStr[i])) {
				int nDigit = a_pszStr[i] - '0';
				strncpy(szStr, a_pszDigitStr + ((nDigit * 5) + nDigit), 5);

				printf("%s ", szStr);
			}
		}

		printf("\n");
	}
#elif defined S09_02
	/** 방향 */
	enum class EDirection {
		NONE = -1,
		LEFT,
		RIGHT,
		MAX_VAL
	};

	/** 값을 설정한다 */
	void SetupVals(int(*a_pnVals)[50], int a_nNumRows, int a_nNumCols) {
		for(int i = 0; i < a_nNumRows; ++i) {
			for(int j = 0; j < a_nNumCols; ++j) {
				a_pnVals[i][j] = (i * a_nNumCols) + j;
			}
		}
	}

	/** 값을 회전한다 */
	void RotateVals(int(*a_pnVals)[50], int a_nNumRows, int a_nNumCols, EDirection a_eDirection) {
		for(int i = 0; i < a_nNumRows / 2; ++i) {
			for(int j = i; j < a_nNumCols - (i + 1); ++j) {
				int nLTRow = i;
				int nLTCol = j;

				int nLBRow = a_nNumRows - (j + 1);
				int nLBCol = i;

				int nRTRow = j;
				int nRTCol = a_nNumCols - (i + 1);

				int nRBRow = a_nNumRows - (i + 1);
				int nRBCol = a_nNumCols - (j + 1);

				// 왼쪽 방향 일 경우
				if(a_eDirection == EDirection::LEFT) {
					int nTemp = a_pnVals[nLTRow][nLTCol];
					a_pnVals[nLTRow][nLTCol] = a_pnVals[nRTRow][nRTCol];
					a_pnVals[nRTRow][nRTCol] = a_pnVals[nRBRow][nRBCol];
					a_pnVals[nRBRow][nRBCol] = a_pnVals[nLBRow][nLBCol];
					a_pnVals[nLBRow][nLBCol] = nTemp;
				} else {
					int nTemp = a_pnVals[nRTRow][nRTCol];
					a_pnVals[nRTRow][nRTCol] = a_pnVals[nLTRow][nLTCol];
					a_pnVals[nLTRow][nLTCol] = a_pnVals[nLBRow][nLBCol];
					a_pnVals[nLBRow][nLBCol] = a_pnVals[nRBRow][nRBCol];
					a_pnVals[nRBRow][nRBCol] = nTemp;
				}
			}
		}
	}

	/** 값을 출력한다 */
	void PrintVals(int(*a_pnVals)[50], int a_nNumRows, int a_nNumCols) {
		for(int i = 0; i < a_nNumRows; ++i) {
			for(int j = 0; j < a_nNumCols; ++j) {
				printf("%4d ", a_pnVals[i][j]);
			}

			printf("\n");
		}
	}
#elif defined S09_03
	/** 메뉴 */
	enum class EMenu {
		NONE = -1,
		ADD_MEMBER,
		REMOVE_MEMBER,
		SEARCH_MEMBER,
		PRINT_ALL_MEMBERS,
		EXIT,
		MAX_VAL
	};

	/** 회원 */
	struct STMember {
		char m_szName[100];
		char m_szPhoneNumber[100];
	};

	/** 회원 관리자 */
	struct STMemberManager {
		int m_nNumMembers;
		STMember m_astMembers[100];
	};

	/** 회원을 탐색한다 */
	int FindMember(STMemberManager* a_pstMemberManager, char a_pszName[]) {
		for(int i = 0; i < a_pstMemberManager->m_nNumMembers; ++i) {
			// 회원이 존재 할 경우
			if(strcmp(a_pstMemberManager->m_astMembers[i].m_szName, a_pszName) == 0) {
				return i;
			}
		}

		return -1;
	}

	/** 회원을 추가한다 */
	void AddMember(STMemberManager* a_pstMemberManager) {
		STMember stMember;
		memset(&stMember, 0, sizeof(stMember));

		printf("\n=====> 회원 추가 <=====\n");

		printf("이름 입력 : ");
		scanf("%[^\n]s", stMember.m_szName);

		getchar();

		printf("전화번호 입력 : ");
		scanf("%[^\n]s", stMember.m_szPhoneNumber);

		int nIdx = FindMember(a_pstMemberManager, stMember.m_szName);

		// 회원이 존재 할 경우
		if(nIdx >= 0) {
			printf("\n%s 은 이미 존재하는 회원입니다.\n", stMember.m_szName);
		} else {
			a_pstMemberManager->m_astMembers[a_pstMemberManager->m_nNumMembers++] = stMember;
			printf("\n%s 을(를) 추가했습니다.\n", stMember.m_szName);
		}
	}

	/** 회원을 삭제한다 */
	void RemoveMember(STMemberManager* a_pstMemberManager) {
		char szName[100] = "";
		printf("\n=====> 회원 삭제 <=====\n");

		printf("이름 입력 : ");
		scanf("%[^\n]s", szName);

		getchar();
		int nIdx = FindMember(a_pstMemberManager, szName);

		// 회원이 존재 할 경우
		if(nIdx >= 0) {
			for(int i = nIdx; i < a_pstMemberManager->m_nNumMembers - 1; ++i) {
				a_pstMemberManager->m_astMembers[i] = a_pstMemberManager->m_astMembers[i + 1];
			}

			a_pstMemberManager->m_nNumMembers -= 1;
			printf("\n%s 을(를) 삭제했습니다.\n", szName);
		} else {
			printf("\n%s 은 존재하지 않는 회원입니다.\n", szName);
		}
	}

	/** 회원을 조회한다 */
	void SearchMember(STMemberManager* a_pstMemberManager) {
		char szName[100] = "";
		printf("\n=====> 회원 조회 <=====\n");

		printf("이름 입력 : ");
		scanf("%[^\n]s", szName);

		getchar();
		int nIdx = FindMember(a_pstMemberManager, szName);

		// 회원이 존재 할 경우
		if(nIdx >= 0) {
			printf("\n=====> 회원 정보 <=====\n");
			printf("이름 : %s\n", a_pstMemberManager->m_astMembers[nIdx].m_szName);
			printf("전화번호 : %s\n", a_pstMemberManager->m_astMembers[nIdx].m_szPhoneNumber);
		} else {
			printf("\n%s 은 존재하지 않는 회원입니다.\n", szName);
		}
	}

	/** 모든 회원을 출력한다 */
	void PrintAllMembers(STMemberManager* a_pstMemberManager) {
		printf("\n=====> 모든 회원 정보 <=====\n");

		for(int i = 0; i < a_pstMemberManager->m_nNumMembers; ++i) {
			printf("이름 : %s\n", a_pstMemberManager->m_astMembers[i].m_szName);
			printf("전화번호 : %s\n\n", a_pstMemberManager->m_astMembers[i].m_szPhoneNumber);
		}
	}
#endif // #if defined S09_01

	int Solve_09(int argc, char* args[]) {
#if defined S09_01
		const char* apszDigitStrs[] = {
			"*****     * ***** ***** *   * ***** ***** ***** ***** *****",
			"*   *     *     *     * *   * *     *         * *   * *   *",
			"*   *     *     *     * *   * *     *         * *   * *   *",
			"*   *     * ***** ***** ***** ***** *****     * ***** *****",
			"*   *     * *         *     *     * *   *     * *   *     *",
			"*   *     * *         *     *     * *   *     * *   *     *",
			"*****     * ***** *****     * ***** *****     * ***** *****"
		};

		char szStr[100] = "";

		printf("숫자 입력 : ");
		scanf("%s", szStr);

		for(int i = 0; i < sizeof(apszDigitStrs) / sizeof(apszDigitStrs[0]); ++i) {
			PrintDigitStrs(apszDigitStrs[i], szStr);
		}
#elif defined S09_02
		int nNumRows = 0;
		int nNumCols = 0;

		int anVals[50][50] = { 0 };

		printf("2 차원 배열 크기 입력 : ");
		scanf("%d %d", &nNumRows, &nNumCols);

		SetupVals(anVals, nNumRows, nNumCols);

		printf("=====> 배열 요소 <=====\n");
		PrintVals(anVals, nNumRows, nNumCols);

		EDirection eDirection = EDirection::NONE;

		printf("\n회전 방향 입력 : ");
		scanf("%d", &eDirection);

		RotateVals(anVals, nNumRows, nNumCols, eDirection);

		printf("\n=====> 배열 요소 - 회전 후 <=====\n");
		PrintVals(anVals, nNumRows, nNumCols);
#elif defined S09_03
		EMenu eSelMenu = EMenu::NONE;

		STMemberManager stMemberManager;
		memset(&stMemberManager, 0, sizeof(stMemberManager));

		do {
			printf("=====> 메뉴 <=====\n");
			printf("1. 회원 추가\n");
			printf("2. 회원 삭제\n");
			printf("3. 회원 조회\n");
			printf("4. 모든 회원 출력\n");
			printf("5. 종료\n");

			printf("\n메뉴 선택 : ");
			scanf("%d", &eSelMenu);

			getchar();
			eSelMenu = (EMenu)((int)eSelMenu - 1);

			switch(eSelMenu) {
				case EMenu::ADD_MEMBER: AddMember(&stMemberManager); break;
				case EMenu::REMOVE_MEMBER: RemoveMember(&stMemberManager); break;
				case EMenu::SEARCH_MEMBER: SearchMember(&stMemberManager); break;
				case EMenu::PRINT_ALL_MEMBERS: PrintAllMembers(&stMemberManager); break;
			}

			printf("\n");
		} while(eSelMenu != EMenu::EXIT);
#endif // #if defined S09_01

		return 0;
	}
}
