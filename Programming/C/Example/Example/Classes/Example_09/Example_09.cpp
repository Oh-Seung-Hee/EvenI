#include "Example_09.h"

//#define E09_STRUCT
//#define E09_UNION
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
	/*
	* 열거형을 활용하면 const 키워드를 사용하는 것에 비해 좀 더 안정적으로 심볼릭 상수를 선언하는 것이 가능하다. (즉, 상수는
	* 프로그램에서 특정 데이터를 구분 할 때 활용되기 때문에 중복 된 값을 지닌 상수가 존재 할 경우 프로그램이 원치 않는 동작을
	* 할 수 있다.)
	* 
	* 열거형에 명시 된 상수는 특정 값을 명시하지 않을 경우 컴파일러에 의해 이전 상수 값에서 1 증가한 값이 자동으로 할당된다.
	* (즉, 사용자가 명시적으로 값을 부여하지 않기 때문에 중복 값을 지정하는 실수를 줄일 수 있다.)
	* 
	* C 열거형 상수 단점
	* - C 열거형 상수는 범위에 개념이 존재하지 않기 떄문에 열거형 상수가 선언 된 열거형이 서로 다르더라도 상수의 이름이 중복 될
	* 경우 컴파일 에러가 발생한다. (즉, 열거형 상수의 이름이 중복되지 않도록 주의 할 필요가 있다.)
	* 
	* C++ 열거형 상수 종류
	* - Scoped 열거형
	* - Unscoped 열거형
	* 
	* Unscoed 열거형은 열거형 상수가 해당 상수가 선언 된 열거형에 종속되지 않기 때문에 C 열거형과 유사하다. 반면, Scoped 열거형은
	* 열거형 상수가 해당 상수가 선언 된 열거형에 종속되는 특징이 존재한다. 따라서, Scoped 열거형을 통해 열거형 상수를 선언했을 경우
	* 해당 상수를 사용하기 위해서는 반드시 상수가 선언 된 열거형을 명시해 줄 필요가 있다.
	* 
	* 단, C 열거형은 정수와 열겨형 상수간에 할당이 자유로운 반면, C++ 열거형은 반드시 형변환 연산자를 사용해서 자료형을 변환해 줄
	* 필요가 있다.
	*/
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
		/*
		* 구조체는 사용자에 의해 정의 된 자료형이기 때문에 특정 구조체를 자료형처럼 사용하는 것이 가능하다. (즉, 구조체를 통해
		* 변수를 선언하는 것이 가능하며, 해당 변수는 구조체 변수라고 지칭한다.)
		* 
		* 구조체 변수는 하위에 여러 맴버를 지니고 있기 때문에 구조체 변수의 특정 맴버에 데이터를 저장하거나 읽어들이기 위해서는
		* 해당 맴버를 명시 할 필요가 있으며, 구조체 변수의 특정 맴버를 지정하기 위해서는 . (맴버 지정 연산자) 사용하면 된다.
		*/
		STMemberInfo stMemberInfo01;
		strcpy(stMemberInfo01.m_szName, "회원 1");
		strcpy(stMemberInfo01.m_szPhoneNumber, "1234");

		/*
		* 구조체 변수 또한 일반 변수와 마찬가지로 선언과 동시에 초기화를 하는 것이 가능하며, 초기화 값의 명시 순서는 구조체 맴버가
		* 선언 된 순서와 동일하다. 또한, 구조체 맴버보다 명시 된 초기화 값의 개수가 적을 경우 초기화 값이 명시 된 순서대로 구조체
		* 맴버에 할당되며 초기화 값이 명시되지 않는 맴버는 기본 값으로 초기화된다.
		*/
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

		/*
		* 구조체 포인터를 통해 특정 맴버에 접근하기 위해 * (역참조 연산자) 를 사용 할 경우 연산자 우선 순위에 주의해야한다.
		* (즉, * (역참조 연산자) 는 . (맴버 지정 연산자) 보다 우선 순위가 낮기 때문에 * (역참조 연산자) 가 먼저 실행 될 수 있도록
		* 우선 순위를 변경해 줄 필요가 있다.)
		* 
		* 따라서, 포인터를 통해 특정 맴버에 접근하기 위해서는 -> (포인터 맴버 지정 연산자) 를 활용하는 것을 추천한다.
		*/
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
