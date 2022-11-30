#include "Practice_07.h"
#include <stdlib.h>
#include <time.h>

#define P07_01
#define P07_02
#define P07_03

namespace P07 {
#if defined P07_01
	int fibo(int num) {
		if(num == 1) {
			return 0;
		} else if(num == 2) {
			return 1;
		} else {
			return fibo(num - 1) + fibo(num - 2);
		}
	}

#elif defined P07_02
	int total(int sum[], int size) {
		int totalSum = 0;

		for(int i = 0; i < size; i++) {
			totalSum += sum[i];
		}

		return totalSum;
	}

#elif defined P07_03
	

#endif // #if defined P07_01

	int Practice_07(int argc, char* args[]) {
#if defined P07_01
		int num, i;

		printf("개수 입력 : ");
		scanf("%d", &num);
		printf("결과 : ");

		for(i = 1; i <= num; i++) {
			printf("%d,  ", fibo(i));
		}

#elif defined P07_02
		int num;
		int arr[50] = { 0 };

		printf("개수 입력 : ");
		scanf("%d",&num);
		
		srand(time(NULL));
		printf("\n=====> 배열 요소 <=====\n");
		for(int i = 0; i < num; i++) {
			arr[i] = rand() % 100;

			printf("%d, ", arr[i]);
		}

		printf("\n\n");
		printf("결과 : %d\n", total(arr, sizeof(arr) / sizeof(arr[0])));
		

#elif defined P07_03

#endif // #if defined P07_01

		return 0;
	}
}
