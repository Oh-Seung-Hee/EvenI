#include "Example_03.h"

namespace E03 {
	int Example_03(int argc, char* args[]) {
		int nLhs = 0;
		int nRhs = 0;

		printf("정수 (2 개) 입력 : ");
		scanf("%d %d", &nLhs, &nRhs);

		/*
		C 는 산술 연산자와 같은 이항 연산자를 수행하기 위해서 피연산자의 자료형이 서로 동일해야하는 제약이 존재한다. 따라서,
		피연산자의 자료형이 서로 다를 경우 두 피연산자 중 하나의 자료형을 자동으로 변환시킨다.

		이를 묵시적 (암시적) 형변환이라고 하며, 묵시적 형변환은 가능한 데이터의 손실이 덜 발생하는 방향으로 이루어진다. 또한,
		산술 연산을 수행한 결과의 자료형은 피연산자의 자료형과 동일하기 때문에 피연산자의 자료형이 동일하더라도 원치 않는 결과를
		만들어 낼 수 있다. (Ex. 정수 / 정수 -> 정수)
		*/
		printf("\n=====> 산술 연산자 <=====\n");
		printf("%d + %d = %d\n", nLhs, nRhs, nLhs + nRhs);
		printf("%d - %d = %d\n", nLhs, nRhs, nLhs - nRhs);
		printf("%d * %d = %d\n", nLhs, nRhs, nLhs * nRhs);
		printf("%d / %d = %f\n", nLhs, nRhs, nLhs / (float)nRhs);
		printf("%d %% %d = %d\n", nLhs, nRhs, nLhs % nRhs);

		/*
		관계, 논리 연산자는 피연산자가 참 또는 거짓 일 경우 해당 연산을 수행 할 수 있으며, 해당 연산의 결과 또한 참 또는 거짓이라는
		특징이 존재한다. C 는 참 또는 거짓을 표현하는 자료형이 별도로 존재하지 않는다.

		따라서, C 는 0 을 제외한 모든 수를 참으로 인식함으로써 참 또는 거짓을 표현한다.
		*/
		printf("\n=====> 관계 연산자 <=====\n");
		printf("%d < %d = %d\n", nLhs, nRhs, nLhs < nRhs);
		printf("%d > %d = %d\n", nLhs, nRhs, nLhs > nRhs);
		printf("%d <= %d = %d\n", nLhs, nRhs, nLhs <= nRhs);
		printf("%d >= %d = %d\n", nLhs, nRhs, nLhs >= nRhs);
		printf("%d == %d = %d\n", nLhs, nRhs, nLhs == nRhs);
		printf("%d != %d = %d\n", nLhs, nRhs, nLhs != nRhs);

		printf("\n=====> 논리 연산자 <=====\n");
		printf("%d && %d = %d\n", nLhs, nRhs, nLhs && nRhs);
		printf("%d || %d = %d\n", nLhs, nRhs, nLhs || nRhs);
		printf("!%d = %d\n", nLhs, !nLhs);

		printf("\n=====> 증감 연산자 <=====\n");

		int nPrevLhs = nLhs;
		int nPrevRhs = nRhs;

		printf("++%d, --%d = %d, %d\n", nPrevLhs, nPrevRhs, ++nLhs, --nRhs);

		nPrevLhs = nLhs;
		nPrevRhs = nRhs;

		/*
		후위 증감 연산자는 선 연산 후 증감 순서를 지니고 있기 때문에 증감 연산에 의해 값이 변경되기 이전의 값이 출력되는 것을
		확인 할 수 있다.
		*/
		printf("%d++, %d-- = %d, %d\n", nPrevLhs, nPrevRhs, nLhs++, nRhs++);

		printf("\n=====> 증감 연산자 후 <=====\n");
		printf("%d, %d\n", nLhs, nRhs);

		printf("\n=====> 비트 연산자 <=====\n");
		printf("%d & %d = %d\n", nLhs, nRhs, nLhs & nRhs);
		printf("%d | %d = %d\n", nLhs, nRhs, nLhs | nRhs);
		printf("%d ^ %d = %d\n", nLhs, nRhs, nLhs ^ nRhs);
		printf("~%d = %d\n", nLhs, ~nLhs);
		printf("%d << 1 = %d\n", nLhs, nLhs << 1);
		printf("%d >> 2 = %d\n", nLhs, nLhs >> 2);

		return 0;
	}
}
