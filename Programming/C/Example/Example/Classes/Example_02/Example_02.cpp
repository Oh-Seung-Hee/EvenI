#include "Example_02.h"

//#define E02_VAR
#define E02_CONST

namespace E02 {
	int Example_02(int argc, char* args[]) {
#if defined E02_VAR
		int nIntVal = 10;
		short nShortVal = 20;
		long nLongVal = 30l;
		long long nLongLongVal = 40l;

		printf("=====> 정수 <=====\n");
		printf("%d, %d, %ld, %lld\n", nIntVal, nShortVal, nLongVal, nLongLongVal);

		float fFloatVal = 10.0f;
		double dblDoubleVal = 20.0;
		long double ldblLongDoubleVal = 30.0l;

		printf("\n=====> 실수 <=====\n");
		printf("%f, %lf, %Lf\n", fFloatVal, dblDoubleVal, ldblLongDoubleVal);

		char chLetter = 'A';
		char szStr[100] = "Hello, World!";

		printf("\n=====> 문자 <=====\n");
		printf("%c, %s\n", chLetter, szStr);
#elif defined E02_CONST
		const int nConstVal = 10;
		const float fConstVal = 3.14f;

		/*
		상수는 선언이 완료 되고 나면 더이상 값을 변경하는 것이 불가능하기 때문에 해당 코드는 컴파일 에러가 발생한다.
		*/
		//nConstVal = 20;

		printf("=====> 상수 <=====\n");
		printf("%d, %f\n", nConstVal, fConstVal);
#endif // #if defined E02_VAR

		return 0;
	}
}
