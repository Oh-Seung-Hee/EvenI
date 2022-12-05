#include "Example_09.h"

#define E09_STRUCT
#define E09_UNION
#define E09_ENUM

namespace E09 {
#if defined E09_STRUCT
	/** 회원 정보 */
	struct STMemberInfo {
		char m_szName[100];
		char m_szPhoneNumber[100];
	};

	/** 회원 정보를 출력한다 */
	void PrintMemberInfo(STMemberInfo a_stMemberInfo) {
		printf("이름 : %s\n", a_stMemberInfo.m_szName);
		printf("전화번호 : %s\n", a_stMemberInfo.m_szPhoneNumber);
	}
#elif defined E09_UNION
	/** 값 정보 */
	union UNValInfo {
		int m_nVal;
		float m_fVal;
	};
#elif defined E09_ENUM
	/** 스탯 타입 */
	enum class EStatType {
		NONE = -1,
		LV,
		HP,
		ATK,
		DEF,
		MAX_VAL
	};

	/** 캐릭터 정보 */
	struct STCharacterInfo {
		int m_nLV;
		int m_nHP;
		int m_nATK;
		int m_nDEF;
	};

	/** 스탯을 강화한다 */
	void EnhanceStat(STCharacterInfo* a_pstCharacterInfo, EStatType a_eStatType) {
		switch(a_eStatType) {
			case EStatType::LV: a_pstCharacterInfo->m_nLV += 1; break;
			case EStatType::HP: a_pstCharacterInfo->m_nHP += 50; break;
			case EStatType::ATK: a_pstCharacterInfo->m_nATK += 10; break;
			case EStatType::DEF: a_pstCharacterInfo->m_nDEF += 5; break;
		}
	}

	/** 캐릭터 정보를 출력한다 */
	void PrintCharacterInfo(STCharacterInfo* a_pstCharacterInfo) {
		printf("레벨 : %d\n", a_pstCharacterInfo->m_nLV);
		printf("체력 : %d\n", a_pstCharacterInfo->m_nHP);
		printf("공격력 : %d\n", a_pstCharacterInfo->m_nATK);
		printf("방어력 : %d\n", a_pstCharacterInfo->m_nDEF);

	}
#endif // #if defined E09_STRUCT

	int Example_09(int argc, char* args[]) {
#if defined E09_STRUCT
		STMemberInfo stMemberInfo01;
		strcpy(stMemberInfo01.m_szName, "회원 1");
		strcpy(stMemberInfo01.m_szPhoneNumber, "1234");

		STMemberInfo stMemberInfo02 = {
			"회원 2", "1234"
		};

		STMemberInfo stMemberInfo03 = {
			"회원 3", "1234"
		};

		STMemberInfo* pstMemberInfo03 = &stMemberInfo03;

		printf("=====> 회원 정보 - 1 <=====\n");
		PrintMemberInfo(stMemberInfo01);

		printf("\n=====> 회원 정보 - 2 <=====\n");
		PrintMemberInfo(stMemberInfo02);

		printf("\n=====> 회원 정보 - 3 <=====\n");
		printf("이름 : %s\n", pstMemberInfo03->m_szName);
		printf("전화번호 : %s\n", (*pstMemberInfo03).m_szPhoneNumber);
#elif defined E09_UNION
		UNValInfo unValInfo = { 0 };
		unValInfo.m_nVal = INT_MAX / 2;

		printf("=====> 정수 할당 후 <=====\n");
		printf("%d, %f\n", unValInfo.m_nVal, unValInfo.m_fVal);

		unValInfo.m_fVal = FLT_MAX / 2.0f;

		printf("\n=====> 정수 할당 후 <=====\n");
		printf("%d, %f\n", unValInfo.m_nVal, unValInfo.m_fVal);
#elif defined E09_ENUM
		STCharacterInfo stCharacterInfo = {
			1, 50, 15, 5
		};

		EStatType eSelStatType = EStatType::NONE;

		do {
			printf("=====> 메뉴 <=====\n");
			printf("1. 레벨 강화\n");
			printf("2. 체력 강화\n");
			printf("3. 공격력 강화\n");
			printf("4. 방어력 강화\n");
			printf("0. 종료\n");

			printf("\n메뉴 선택 : ");
			scanf("%d", &eSelStatType);

			eSelStatType = (EStatType)((int)eSelStatType - 1);

			// 올바른 스탯 타입 일 경우
			if(eSelStatType != EStatType::NONE) {
				EnhanceStat(&stCharacterInfo, eSelStatType);

				printf("\n=====> 강화 결과 <=====\n");
				PrintCharacterInfo(&stCharacterInfo);

				printf("\n");
			}
		} while(eSelStatType != EStatType::NONE);
#endif // #if defined E09_STRUCT

		return 0;
	}
}
