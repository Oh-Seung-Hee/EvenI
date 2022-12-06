#include "Practice_08.h"
#include <stdlib.h>
#include <time.h>

//#define P08_01
//#define P08_02
#define P08_03

namespace P08 {
#if defined P08_01
	// 버블정렬 오름차순
	void bubbleAscending(int* pArr, int size) {
		int i, j, tmp;

		for(i = 0; i < size - 1; i++) {
			for(j = 0; j < size - 1-i; j++) {
				if(*(pArr + j) > *(pArr + j + 1)) {
					tmp = *(pArr + j);
					*(pArr + j) = *(pArr + j + 1);
					*(pArr + j + 1) = tmp;
				}
			}
		}
	}

	// 버블정렬 내림차순
	void bubbleDescending(int* pArr, int size) {
		int i, j, tmp;

		for(i = 0; i < size - 1; i++) {
			for(j = 0; j < size - 1 - i; j++) {
				if(*(pArr + j) < *(pArr + j + 1)) {
					tmp = *(pArr + j);
					*(pArr + j) = *(pArr + j + 1);
					*(pArr + j + 1) = tmp;
				}
			}
		}
	}

#elif defined P08_02
	// 버블정렬 오름차순
	void bubbleAscending(int* pArr, int size) {
		int i, j, tmp;

		for(i = 0; i < size - 1; i++) {
			for(j = 0; j < size - 1 - i; j++) {
				if(*(pArr + j) > *(pArr + j + 1)) {
					tmp = *(pArr + j);
					*(pArr + j) = *(pArr + j + 1);
					*(pArr + j + 1) = tmp;
				}
			}
		}
	}

	// 이진탐색
	int binSearch(int* pArr, int size, int key) {
		int low = 0, mid, high = size - 1;
		
		while(low <= high) {
			mid = (low + high) / 2;

			/*
			Note.
			가능하면 함수는 하나의 역할만 수행하도록 설계해주는 것이 좋습니다. 함수의 사용 목적 중 하나는 코드의 재사용성이기
			때문에 특정 함수가 여러 역할을 할 수록 해당 함수는 재사용성이 떨어질 수 밖에 없습니다.
			*/
			if(key == *(pArr + mid)) {		// 탐색 성공 시	
				printf("탐색 성공\n");

				return 0;
			} else if(key < *(pArr + mid)) {	// key 값이 탐색중인 값보다 작을 때
				high = mid - 1;
			} else {	// key 값이 탐색중인 값보다 클 때
				low = mid + 1;
			}
		}

		// 탐색 실패 시
		printf("탐색 실패\n");

		return 0;
	}

#elif defined P08_03
	// 좌방향 교환
	void swapLeft(int* pNum1, int* pNum2, int* pNum3) {
		int tmp;

		tmp = *pNum1;
		*pNum1 = *pNum2;
		*pNum2 = *pNum3;
		*pNum3 = tmp;

		printf("%d, %d, %d", *pNum1, *pNum2, *pNum3);
	}

	// 우방향 교환
	void swapRight(int* pNum1, int* pNum2, int* pNum3) {
		int tmp;

		tmp = *pNum3;
		*pNum3 = *pNum2;
		*pNum2 = *pNum1;
		*pNum1 = tmp;

		printf("%d, %d, %d", *pNum1, *pNum2, *pNum3);
	}

#endif // #if defined P08_01

	int Practice_08(int argc, char* args[]) {
#if defined P08_01
		int sortArr[6];

		srand(time(NULL));

		// 배열 초기화
		for(int i = 0; i < 6; i++) {
			sortArr[i] = rand() % 10;
			
			for(int j = 0; j < i; j++) {
				if(sortArr[i] == sortArr[j]) {
					i--;
					break;
				}
			}
		}

		// 배열 출력
		printf("=====> 배열 요소 - 정렬 전 <=====\n");
		for(int i = 0; i < 6; i++) {
			printf("%d, ", sortArr[i]);
		}
		printf("\n");
		
		// 오름차순으로 배열 출력
		printf("=====> 배열 요소 - 오름차순으로 정렬 후 <=====\n");
		bubbleAscending(sortArr, sizeof(sortArr) / sizeof(sortArr[0]));
		for(int i = 0; i < 6; i++) {
			printf("%d, ", sortArr[i]);
		}
		printf("\n");

		// 내림차순으로 배열 출력
		printf("=====> 배열 요소 - 내림차순으로 정렬 후 <=====\n");
		bubbleDescending(sortArr, sizeof(sortArr) / sizeof(sortArr[0]));
		for(int i = 0; i < 6; i++) {
			printf("%d, ", sortArr[i]);
		}
		printf("\n");		

#elif defined P08_02
		int sortArr[7];	
		int inputNum;	// 이진 탐색 할 숫자

		srand(time(NULL));

		// 배열 초기화
		for(int i = 0; i < 7; i++) {
			sortArr[i] = rand() % 50;

			for(int j = 0; j < i; j++) {
				if(sortArr[i] == sortArr[j]) {
					i--;
					break;
				}
			}
		}

		// 배열 정렬 후 출력
		printf("=====> 배열 요소 <=====\n");
		bubbleAscending(sortArr, sizeof(sortArr) / sizeof(sortArr[0]));
		for(int i = 0; i < 7; i++) {
			printf("%d, ", sortArr[i]);
		}
		printf("\n\n");

		// 탐색 할 숫자 입력
		printf("정수 입력 : ");
		scanf("%d", &inputNum);

		// 결과
		printf("결과 : ");
		binSearch(sortArr, sizeof(sortArr) / sizeof(sortArr[0]), inputNum);

#elif defined P08_03
		int num1 = 10, num2 = 20, num3 = 30;
		int inputNum;

		printf("정수(0 or 1) 입력 : ");
		scanf("%d", &inputNum);
		printf("\n");
		
		// 교환 전
		printf("=====> 교환 전 <=====\n");
		printf("%d, %d, %d\n", num1, num2, num3);
		printf("\n");

		// 교환 후
		printf("=====> 교환 후 <=====\n");
		if(inputNum == 0) {
			swapLeft(&num1, &num2, &num3);
		} else if(inputNum == 1) {
			swapRight(&num1, &num2, &num3);
		}

#endif // #if defined P08_01

		return 0;
	}
}
