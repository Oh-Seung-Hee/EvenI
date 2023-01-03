#define P04_01
#define P04_02

#include "Practice_04.h"

namespace P04 {
	int Practice_04(int argc, char* args[]) {
#if defined P04_01
		int score;

		printf("당신의 학점을 입력하세요.\n");
		scanf("%d", &score);
		printf("당신의 학점은 ");

		/*
		 * Note.
		 * printf 함수를 통한 문장을 반드시 한번에 완성 할 필요는 없습니다. printf 함수를 통해 문장을 한번에 완성을 할려고 하면
		 * 코드의 중복이 발생 할 가능성이 높기 때문에 해당 문제는 printf 함수를 여러번 호출해주는 것이 좀 더 간결한 코드가 작성
		 * 됩니다.
		 */
		if(score >= 90) {
			printf("A");

			if(score % 10 >= 7) {
				printf("%c입니다.\n", 43);
			} else if(score % 10 >= 4) {
				printf("%d입니다.\n", 0);
			} else {
				printf("%c입니다.\n", 45);
			}
		} else if(score >= 80) {
			printf("B");

			if(score % 10 >= 7) {
				printf("%c입니다.\n", 43);
			} else if(score % 10 >= 4) {
				printf("%d입니다.\n", 0);
			} else {
				printf("%c입니다.\n", 45);
			}
		} else if(score >= 70) {
			printf("C");

			if(score % 10 >= 7) {
				printf("%c입니다.\n", 43);
			} else if(score % 10 >= 4) {
				printf("%d입니다.\n", 0);
			} else {
				printf("%c입니다.\n", 45);
			}
		} else if(score >= 60) {
			printf("D");

			if(score % 10 >= 7) {
				printf("%c입니다.\n", 43);
			} else if(score % 10 >= 4) {
				printf("%d입니다.\n", 0);
			} else {
				printf("%c입니다.\n", 45);
			}
		} else {
			printf("F입니다.\n");
		}

#elif defined P04_02
		int score;

		printf("당신의 학점을 입력하세요.\n");
		scanf("%d", &score);
		printf("당신의 학점은 ");

		switch(score % 100 / 10) {
			case 10:
				printf("A+");
				break;
			case 9:
				printf("A");

				switch(score % 10) {
					case 9:
					case 8:
					case 7:
						printf("%c입니다.\n", 43);
						break;
					case 6:
					case 5:
					case 4:
						printf("%d입니다.\n", 0);
						break;
					case 3:
					case 2:
					case 1:
					case 0:
						printf("%c입니다.\n", 45);
						break;
				}
				break;
			case 8:
				printf("B");

				switch(score % 10) {
					case 9:
					case 8:
					case 7:
						printf("%c입니다.\n", 43);
						break;
					case 6:
					case 5:
					case 4:
						printf("%d입니다.\n", 0);
						break;
					case 3:
					case 2:
					case 1:
					case 0:
						printf("%c입니다.\n", 45);
						break;
				}
				break;
			case 7:
				printf("C");

				switch(score % 10) {
					case 9:
					case 8:
					case 7:
						printf("%c입니다.\n", 43);
						break;
					case 6:
					case 5:
					case 4:
						printf("%d입니다.\n", 0);
						break;
					case 3:
					case 2:
					case 1:
					case 0:
						printf("%c입니다.\n", 45);
						break;
				}
				break;
			case 6:
				printf("D");

				switch(score % 10) {
					case 9:
					case 8:
					case 7:
						printf("%c입니다.\n", 43);
						break;
					case 6:
					case 5:
					case 4:
						printf("%d입니다.\n", 0);
						break;
					case 3:
					case 2:
					case 1:
					case 0:
						printf("%c입니다.\n", 45);
						break;
				}
				break;
			case 5:
			case 4:
			case 3:
			case 2:
			case 1:
			case 0:
				printf("F입니다.");
				break;
		}

#endif // #if defined P04_01

		return 0;
	}
}
