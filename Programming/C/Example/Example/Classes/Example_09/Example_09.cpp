#include "Example_09.h"

#define E09_STRUCT
#define E09_UNION
#define E09_ENUM

namespace E09 {
#if defined E09_STRUCT
	/** 캐릭터 정보 */
	struct STCharacterInfo {
		int m_nLV;
		int m_nHP;
		int m_nATK;
	};
#elif defined E09_UNION
	/** 값 정보 */
	union UNValInfo {
		int m_nVal;
		float m_fVal;
	};
#elif defined E09_ENUM

#endif // #if defined E09_STRUCT

	int Example_09(int argc, char* args[]) {
#if defined E09_STRUCT

#elif defined E09_UNION
		UNValInfo unValInfo = { 0 };
		unValInfo.m_nVal = INT_MAX / 2;

		printf("=====> 정수 할당 후 <=====\n");
		printf("%d, %f\n", unValInfo.m_nVal, unValInfo.m_fVal);

		unValInfo.m_fVal = FLT_MAX / 2.0f;

		printf("\n=====> 정수 할당 후 <=====\n");
		printf("%d, %f\n", unValInfo.m_nVal, unValInfo.m_fVal);
#elif defined E09_ENUM

#endif // #if defined E09_STRUCT

		return 0;
	}
}
