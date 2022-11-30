#include "Practice_06.h"
#include <stdlib.h>
#include <time.h>

#define P06_01
#define P06_02
#define P06_03

namespace P06 {
	int Practice_06(int argc, char* args[]) {
#if defined P06_01		
		// 정답 배열(answerNum)과 도전 배열(input) 생성
		int inputNum[4], answerNum[4];
		//int ball = 0, strike = 0;	// ball와 strike 선언

		/*
		srand 함수를 통한 시드 값 설정은 프로그램이 구동 될 때 한번만 해주시면 됩니다.
		*/
		// 숫자 랜덤으로 정답 배열 안에 생성
		for(int i = 0; i < 4; i++) {	// 배열에 0~9의 숫자 4개 생성
			srand(time(NULL));

			answerNum[i] = rand() % 10;

			for(int j = 0; j < i; j++) {	// 배열에 중복 숫자 확인
				if(answerNum[i] == answerNum[j]) {
					i--;
					break;
				}
			}
		}

		// 게임 진행
		printf("생성 한 숫자 : %d %d %d %d\n\n", answerNum[0], answerNum[1], answerNum[2], answerNum[3]);
		
		// 도전 숫자 배열 입력받아 초기화
		while(1) {
			int ball = 0, strike = 0;	// ball와 strike 선언

			printf("숫자(4개) 입력 :  ");
			scanf("%d %d %d %d", &inputNum[0], &inputNum[1], &inputNum[2], &inputNum[3]);

			/*
			아래 조건문 같은 경우 조건문의 구성을 변경해주는 것으로 조금이나마 속도 향상을 하는 것이 가능합니다.

			Ex)
			if(inputNum[i] == answerNum[j]) {
			     if(i == j) {
				     strike++;
				 } else {
				     ball++;
				 }
			}
			*/
			for(int i = 0; i < 4; i++) {
				for(int j = 0; j < 4; j++) {
					if(i == j && inputNum[i] == answerNum[j]) {
						strike++;
					} else if(i != j && inputNum[i] == answerNum[j]) {
						ball++;
					}
				}
			}

			printf("결과 : %d Strike, %d Ball\n\n", strike, ball);

			if(strike == 4) {
				printf("게임을 종료합니다.\n");

				exit(1);
			}
		}
		
#elif defined P06_02
		

#elif defined P06_03
		// 배열(snail) 선언(50x50)
		int snail[50][50] = { 0 };
		// 입력받을 행(x), 열(y) 변수 선언
		int x, y;
		int num = 1;	// 배열 초기화에 사용될 변수(num) 선언
		int dir = 1;	// 방향 전환용 변수(dir) 선언
		int pos_x = 0, pos_y = -1;	// 초기화할 배열의 위치를 위한 변수 선언

		// 행, 열 개수 입력받음
		printf("행, 열 개수 입력 : ");
		scanf("%d %d", &x, &y);

		int mem_x = x - 1, mem_y = y;	// 배열 초기화 for문에 사용될 변수 행렬 개수 복사하여 선언
		int num_xy = x * y;	// 배열 크기 변수(num_xy) 선언

		// 배열을 달팽이 형태로 초기화
		while(num < num_xy + 1) {
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

#endif // #if defined P06_01

		return 0;
	}
}
