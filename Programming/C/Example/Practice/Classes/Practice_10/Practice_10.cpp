#include "Practice_10.h"
#include <stdlib.h>
#include <string.h>

//#define P10_01
//#define P10_02
#define P10_03

namespace P10 {
#if defined P10_01
	void odd(int* arr, int len) {
		for(int i = 0; i < len; i++) {
			if(arr[i] % 2 == 1) {
				printf("%d ", arr[i]);
			}
		}
	}

	void even(int* arr, int len) {
		for(int i = len-1; i > -1; i--) {
			if(arr[i] % 2 == 0) {
				printf("%d ", arr[i]);
			}
		}
	}

#elif defined P10_02
	/*과제 10 - 2
		* -슬라이드 퍼즐 게임 제작하기(단, 입력 가능한 2 차원 배열 크기는 제한하지 않는다)
		*
		*Ex)
		* 과제 6 - 2 참조
		- 슬라이드 퍼즐 게임 제작하기
		- 프로그램이 시작되면 너비, 높이를 입력 받는다. (단, 입력 가능한 최대 너비, 높이는 각각 50 으로 제한)
		- 숫자 0 부터 입력한 (너비 x 높이) - 1 까지 값을 부여한 2 차원 배열 생성하기 (숫자 0 은 공백을 의미한다.)
		- 생성 된 배열의 각 요소를 무작위로 재배치 후 해당 배열을 올바른 순서로 맞출 경우 게임 종료

		Ex)
		너비, 높이 입력 : 3 3

		1 4 5									1 2 3
		3 2 6	<-	공백 주변의 요소를 옮겨서		4 5 6	순서로 맞출 경우 게임 종료
		8 7										7 8

		위치 입력 : 2 1	<- 행, 열 순으로 위치를 입력 받는다

		1 4 5
		3 2 6
		8   7

		입력 받은 위치의 상/하/좌/우 에 공백이 존재 할 경우 공백과 해당 위치에 존재하는 숫자를 바꾼다 (단, 입력 받은 위치 주변에 공백이
		없을 경우에는 무시)

		위의 과정을 반복해서 올바른 순서로 값이 배치 될 경우 게임을 종료한다

		*/

#elif defined P10_03

#endif // #if defined P10_01

	int Practice_10(int argc, char* args[]) {
#if defined P10_01
		int arrLen = 5, idx = 0;

		int* arr = (int*)malloc(sizeof(int) * arrLen);

		while(1) {
			printf("정수 입력 : ");
			scanf("%d", &arr[idx]);

			if(arr[idx] == 0) {
				break;
			}

			idx++;

			if(arrLen == idx) {
				arrLen += 5;
				arr = (int*)realloc(arr, sizeof(int) * arrLen);
			}
		}

		printf("=====> 결과 <=====\n");
		odd(arr, idx);	// 홀수 출력
		even(arr, idx);	// 짝수 출력

		free(arr);


#elif defined P10_02
		int x, y, cnt=0;
		int** puzzle = NULL;
		int** answer = NULL;
		
		printf("너비, 높이 입력 : ");
		scanf("%d %d", &x, &y);

		// puzzle 함수 입력받은 크기로 초기화
		puzzle = (int**)malloc(sizeof(int*) * x);
		for(int i = 0; i < x; i++) {
			puzzle[i] = (int*)malloc(sizeof(int) * y);
		}

		answer = (int**)malloc(sizeof(int*) * x);
		for(int i = 0; i < x; i++) {
			answer[i] = (int*)malloc(sizeof(int) * y);
		}

		for(int i = 0; i < x; i++) {
			for(int j = 0; j < y; j++) {
				puzzle[i][j] = cnt;

				cnt++;
			}
		}

		for(int i = 0; i < x; i++) {
			for(int j = 0; j < y; j++) {
				answer[i][j] = puzzle[i][j];
			}
		}

		for(int i = 0; i < x; i++) {
			for(int j = 0; j < y; j++) {
				if(answer[i][j] == 0) {
					printf("%5c ", ' ');
				} else {
					printf("%5d ", answer[i][j]);
				}
			}

			printf("\n");
		}

		free(puzzle);
		free(answer);

#elif defined P10_03
		int x, y;	// 입력받을 행(x), 열(y) 변수 선언
		int num = 1, dir = 1;	// 배열 초기화에 사용될 변수(num), 방향 전환용 변수(dir) 선언
		int pos_x = 0, pos_y = -1;	// 초기화할 배열의 위치를 위한 변수 선언
		int** snail = NULL;	

		printf("행, 열 개수 입력 : ");
		scanf("%d %d", &x, &y);

		snail = (int**)malloc(sizeof(int*) * x);
		for(int i = 0; i < x; i++) {
			snail[i] = (int*)malloc(sizeof(int) * y);
		}

		int mem_x = x - 1, mem_y = y;	// 배열 초기화 for문에 사용될 변수 행렬 개수 복사하여 선언

		// 배열을 달팽이 형태로 초기화
		while(num < x*y + 1) {
			for(int i = 0; i < mem_y; i++) {
				pos_y += dir;
				snail[pos_x][pos_y] = num;
				num++;
			}
			mem_y--;

			for(int i = 0; i < mem_x; i++) {
				pos_x += dir;
				snail[pos_x][pos_y] = num;
				num++;
			}
			mem_x--;

			dir *= -1;	// 방향 전환
		}

		// 배열 출력
		printf("\n=====> 배열 요소 <=====\n");
		for(int i = 0; i < x; i++) {
			for(int j = 0; j < y; j++) {
				printf("%5d", snail[i][j]);
			}

			printf("\n");
		}

		/*
		* Note.
		* 기본적으로 free 함수 호출 횟수는 동적 할당 횟수만큼 해야합니다.
		* 현재 snail 은 포인터 배열을 의미하는 더블 포인터이고, 해당 포인터를 기반으로 다시 각 행마다 동적 할당을 했기 때문에
		* free 함수 또한 각 행마다 별도로 호출해서 메모리를 정리해 줄 필요가 있습니다.
		*/
		free(snail);

#endif // #if defined P10_01

		return 0;
	}
}
