//#define P02_01
#define P02_02

#include "Practice_02.h"
#include <stdlib.h>

namespace P02 {
#if defined P02_01
	struct queue {
		int size;
		int front;
		int rear;
		int count;	// 현재 큐 안에 있는 데이터 갯수

		int* data;
	};

	void init(queue* q) {
		// 큐 사이즈 할당
		q->size = 10;
		q->count = 0;
		q->data = (int*)malloc(sizeof(int) * q->size);

		// 큐의 front와 rear 위치 초기화
		q->front = q->rear = 0;
	}

	int isEmpty(queue* q) {
		if(q->count <= 0) {	// 큐가 비어있으면 0을 반환
			return 1;
		}
		return 0;	// 큐가 비어있지 않으면 1을 반환
	}

	void enqueue(queue* q, int num) {
		// 큐가 가득 차있는 경우
		if(q->count >= q->size) {
			// 기존의 큐 복사할 tmp 할당
			int* tmp = (int*)malloc(sizeof(int) * q->size * 2);

			// 큐 복사
			for(int i = 0; i < q->size; i++) {
				tmp[i] = q->data[q->front + i % q->count];
			}

			free(q->data);

			// 큐 복사 후 front와 rear 위치, size 초기화
			q->front = 0;
			q->rear = q->count;
			q->size *= 2;
			q->data = tmp;

			free(tmp);
		}

		// 큐에 공간이 있는 경우
		q->data[q->rear++] = num;
		q->count++;

		if(q->rear >= q->size) {
			q->rear = 0;
		}
	}

	int dequeue(queue* q) {
		// 큐가 비어있는 경우
		if(isEmpty(q) == 1) {
			printf("큐가 비어있습니다\n");
		}

		// 큐에 데이터가 있는 경우
		int result = q->data[q->front++];
		q->count--;

		if(q->front >= q->size) {
			q->front = 0;
		}

		return result;
	}

	void freeQueue(queue* q) {
		free(q->data);
	}

#elif defined P02_02
	struct queue {
		int size;
		int front;
		int rear;
		int count;	// 현재 큐 안에 있는 데이터 갯수

		int* data;
	};

	void init(queue* q) {
		// 큐 사이즈 할당
		q->size = 10;
		q->count = 0;
		q->data = (int*)malloc(sizeof(int) * q->size);

		// 큐의 front와 rear 위치 초기화
		q->front = q->rear = 0;
	}

	int isEmpty(queue* q) {
		if(q->count <= 0) {	// 큐가 비어있으면 0을 반환
			return 1;
		}
		return 0;	// 큐가 비어있지 않으면 1을 반환
	}

	void frontEnqueue(queue* q, int num) {	// 전방에서 데이터 삽입
		// 큐가 가득 차있는 경우
		if(q->count >= q->size) {
			int* tmp = (int*)malloc(sizeof(int) * q->size * 2);

			for(int i = 0; i < q->size; i++) {
				tmp[i] = q->data[q->front + i % q->count];
			}

			free(q->data);

			q->front = 0;
			q->rear = q->count;
			q->size *= 2;
			q->data = tmp;

			free(tmp);
		}

		q->front -= 1;

		if(q->front < 0) {
			q->front = q->size - 1;
		}

		// 큐에 공간이 있는 경우
		q->data[q->front] = num;
		q->count++;
	}

	void rearEnqueue(queue* q, int num) {	// 후방에서 데이터 삽입
		// 큐가 가득 차있는 경우
		if(q->count >= q->size) {
			int* tmp = (int*)malloc(sizeof(int) * q->size * 2);

			for(int i = 0; i < q->size; i++) {
				tmp[i] = q->data[q->front + i % q->count];
			}

			free(q->data);

			q->front = 0;
			q->rear = q->count;
			q->size *= 2;
			q->data = tmp;

			free(tmp);
		}

		// 큐에 공간이 있는 경우
		q->data[q->rear++] = num;
		q->count++;

		if(q->rear >= q->size) {
			q->rear = 0;
		}
	}

	int frontDequeue(queue* q) {	// 전방에서 데이터 삭제
		// 큐가 비어있는 경우
		if(isEmpty(q) == 1) {
			printf("큐가 비어있습니다\n");
		}

		// 큐에 데이터가 있는 경우
		int result = q->data[q->front++];
		q->count--;

		if(q->front >= q->size) {
			q->front = 0;
		}

		return result;
	}

	int rearDequeue(queue* q) {		// 후방에서 데이터 삭제
		// 큐가 비어있는 경우
		if(isEmpty(q) == 1) {
			printf("큐가 비어있습니다\n");
		}

		q->rear -= 1;

		if(q->rear < 0) {
			q->rear = q->size - 1;
		}

		// 큐에 데이터가 있는 경우
		int result = q->data[q->rear];
		q->count--;

		return result;
	}

	void freeQueue(queue* q) {
		free(q->data);
	}

#endif // #if defined P02_01

	int Practice_02(int argc, char* args[]) {
#if defined P02_01
#define QUEUE_SIZE 10

		queue Queue;

		init(&Queue);

		printf("=====> 데이터 입력 순서 <=====\n");
		for(int i = 0; i < QUEUE_SIZE; i++) {
			printf("%d ", i + 1);
			enqueue(&Queue, i + 1);
		}

		printf("\n\n=====> 데이터 출력 순서 <=====\n");
		for(int i = 0; i < QUEUE_SIZE; i++) {
			printf("%d ", dequeue(&Queue));
		}

		printf("\n");

		freeQueue(&Queue);

#elif defined P02_02
#define QUEUE_SIZE 10

		queue Queue;

		init(&Queue);

		printf("=====> 데이터 입력 순서 (전방) <=====\n");
		for(int i = 0; i < QUEUE_SIZE; i++) {
			printf("%d ", i + 1);
			rearEnqueue(&Queue, i + 1);
		}

		printf("\n\n=====> 데이터 출력 순서 (전방) <=====\n");
		for(int i = 0; i < QUEUE_SIZE; i++) {
			printf("%d ", rearDequeue(&Queue));
		}

		printf("\n");

		freeQueue(&Queue);

#endif // #if defined P02_01

		return 0;
	}
}
