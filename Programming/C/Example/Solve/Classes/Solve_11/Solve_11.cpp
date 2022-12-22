#include "Solve_11.h"

namespace S11 {
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

	/** 회원을 로드한다 */
	void LoadMembers(STMemberManager* a_pstMemberManager, const char* a_pszFilePath) {
		FILE* pfRStream = fopen(a_pszFilePath, "rb");

		// 파일이 존재 할 경우
		if(pfRStream != NULL) {
			int nNumMembers = 0;
			fread(&nNumMembers, sizeof(int), 1, pfRStream);

			for(int i = 0; i < nNumMembers; ++i) {
				STMember stMember;
				memset(&stMember, 0, sizeof(stMember));

				fgets(stMember.m_szName, sizeof(stMember.m_szName), pfRStream);
				fgets(stMember.m_szPhoneNumber, sizeof(stMember.m_szPhoneNumber), pfRStream);

				stMember.m_szName[strlen(stMember.m_szName) - 1] = '\0';
				stMember.m_szPhoneNumber[strlen(stMember.m_szPhoneNumber) - 1] = '\0';

				a_pstMemberManager->m_astMembers[i] = stMember;
			}

			a_pstMemberManager->m_nNumMembers = nNumMembers;
			fclose(pfRStream);
		}
	}

	/** 회원을 저장한다 */
	void SaveMembers(STMemberManager* a_pstMemberManager, const char* a_pszFilePath) {
		FILE* pfWStream = fopen(a_pszFilePath, "wb");

		// 파일이 존재 할 경우
		if(pfWStream != NULL) {
			fwrite(&a_pstMemberManager->m_nNumMembers, sizeof(int), 1, pfWStream);

			for(int i = 0; i < a_pstMemberManager->m_nNumMembers; ++i) {
				fprintf(pfWStream, "%s\n", a_pstMemberManager->m_astMembers[i].m_szName);
				fprintf(pfWStream, "%s\n", a_pstMemberManager->m_astMembers[i].m_szPhoneNumber);
			}

			fclose(pfWStream);
		}
	}

	int Solve_11(int argc, char* args[]) {
		EMenu eSelMenu = EMenu::NONE;

		STMemberManager stMemberManager;
		memset(&stMemberManager, 0, sizeof(stMemberManager));

		LoadMembers(&stMemberManager, "Resources/Solve_11/Members.txt");

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
			SaveMembers(&stMemberManager, "Resources/Solve_11/Members.txt");
		} while(eSelMenu != EMenu::EXIT);

		return 0;
	}
}
