#include "Example_10.h"

#define E10_MALLOC
#define E10_CALLOC
#define E10_REALLOC

namespace E10 {
#if defined E10_MALLOC
	/** 값을 설정한다 */
	void SetupVals(int a_pnVals[], int a_nSize) {
		for(int i = 0; i < a_nSize; ++i) {
			a_pnVals[i] = i + 1;
		}
	}
#elif defined E10_CALLOC
	/** 노드 */
	struct STNode {
		int m_nVal;
		STNode* m_pstNextNode;
	};

	/** 연결 리스트 */
	struct STLinkedList {
		int m_nNumVals;
		STNode* m_pstHeadNode;
	};

	/** 리스트를 설정한다 */
	void SetupList(STLinkedList* a_pstLinkedList) {
		a_pstLinkedList->m_nNumVals = 0;
		a_pstLinkedList->m_pstHeadNode = NULL;
	}

	/** 값을 반환한다 */
	int GetVal(STLinkedList* a_pstLinkedList, int a_nIdx) {
		STNode* pstNode = a_pstLinkedList->m_pstHeadNode;

		for(int i = 0; i < a_nIdx; ++i) {
			pstNode = pstNode->m_pstNextNode;
		}

		return pstNode->m_nVal;
	}

	/** 노드를 생성한다 */
	STNode* CreateNode(int a_nVal) {
		STNode* pstNode = (STNode*)calloc(1, sizeof(STNode));
		pstNode->m_nVal = a_nVal;

		return pstNode;
	}

	/** 값을 추가한다 */
	void AddVal(STLinkedList* a_pstLinkedList, int a_nVal) {
		STNode** pstNode = &a_pstLinkedList->m_pstHeadNode;

		while(*pstNode != NULL) {
			pstNode = &(*pstNode)->m_pstNextNode;
		}

		*pstNode = CreateNode(a_nVal);
		a_pstLinkedList->m_nNumVals += 1;
	}

	/** 값을 탐색한다 */
	int FindVal(STLinkedList* a_pstLinkedList, int a_nVal) {
		STNode* pstNode = a_pstLinkedList->m_pstHeadNode;

		for(int i = 0; i < a_pstLinkedList->m_nNumVals; ++i) {
			// 값이 존재 할 경우
			if(pstNode->m_nVal == a_nVal) {
				return i;
			}

			pstNode = pstNode->m_pstNextNode;
		}

		return -1;
	}

	/** 값을 제거한다 */
	void RemoveVal(STLinkedList* a_pstLinkedList, int a_nVal) {
		STNode** pstNode = &a_pstLinkedList->m_pstHeadNode;

		while(*pstNode != NULL && (*pstNode)->m_nVal != a_nVal) {
			pstNode = &(*pstNode)->m_pstNextNode;
		}

		// 값이 존재 할 경우
		if(*pstNode != NULL) {
			STNode* pstRemoveNode = *pstNode;
			*pstNode = pstRemoveNode->m_pstNextNode;

			free(pstRemoveNode);
			a_pstLinkedList->m_nNumVals -= 1;
		}
	}

	/** 리스트를 제거한다 */
	void DestroyList(STLinkedList* a_pstLinkedList) {
		STNode* pstNode = a_pstLinkedList->m_pstHeadNode;

		while(pstNode != NULL) {
			STNode* pstRemoveNode = pstNode;
			pstNode = pstNode->m_pstNextNode;

			free(pstRemoveNode);
		}

		a_pstLinkedList->m_pstHeadNode = NULL;
	}
#elif defined E10_REALLOC
	/** 배열 */
	struct STArray {
		int m_nSize;
		int m_nNumVals;

		int* m_pnVals;
	};

	/** 배열을 설정한다 */
	void SetupArray(STArray* a_pstArray, int a_nSize) {
		a_pstArray->m_nSize = a_nSize;
		a_pstArray->m_nNumVals = 0;
		a_pstArray->m_pnVals = (int*)malloc(sizeof(int) * a_nSize);
	}

	/** 값을 반환한다 */
	int GetVal(STArray* a_pstArray, int a_nIdx) {
		return a_pstArray->m_pnVals[a_nIdx];
	}

	/** 값을 탐색한다 */
	int FindVal(STArray* a_pstArray, int a_nVal) {
		for(int i = 0; i < a_pstArray->m_nNumVals; ++i) {
			// 값이 존재 할 경우
			if(a_pstArray->m_pnVals[i] == a_nVal) {
				return i;
			}
		}

		return -1;
	}

	/** 배열 크기를 변경한다 */
	void ResizeArray(STArray* a_pstArray, int a_nSize) {
		a_pstArray->m_nSize = a_nSize;
		a_pstArray->m_nNumVals = (a_pstArray->m_nNumVals < a_nSize) ? a_pstArray->m_nNumVals : a_nSize;

		a_pstArray->m_pnVals = (int*)realloc(a_pstArray->m_pnVals, sizeof(int) * a_nSize);
	}

	/** 값을 추가한다 */
	void AddVal(STArray* a_pstArray, int a_nVal) {
		// 배열이 가득 찼을 경우
		if(a_pstArray->m_nNumVals >= a_pstArray->m_nSize) {
			ResizeArray(a_pstArray, a_pstArray->m_nSize * 2);
		}

		a_pstArray->m_pnVals[a_pstArray->m_nNumVals++] = a_nVal;
	}

	/** 값을 제거한다 */
	void RemoveVal(STArray* a_pstArray, int a_nVal) {
		int nIdx = FindVal(a_pstArray, a_nVal);

		// 값이 존재 할 경우
		if(nIdx >= 0) {
			for(int i = nIdx; i < a_pstArray->m_nNumVals - 1; ++i) {
				a_pstArray->m_pnVals[i] = a_pstArray->m_pnVals[i + 1];
			}

			a_pstArray->m_nNumVals -= 1;
		}
	}

	/** 배열을 제거한다 */
	void DestoryArray(STArray* a_pstArray) {
		if(a_pstArray->m_pnVals != NULL) {
			free(a_pstArray->m_pnVals);
		}

		a_pstArray->m_pnVals = NULL;
	}
#endif // #if defined E10_MALLOC

	int Example_10(int argc, char* args[]) {
#if defined E10_MALLOC
		int nSize = 0;
		int nNumRows = 0;
		int nNumCols = 0;

		printf("1 차원 배열 크기 입력 : ");
		scanf("%d", &nSize);

		printf("2 차원 배열 크기 입력 : ");
		scanf("%d %d", &nNumRows, &nNumCols);

		/*
		* malloc 을 비롯한 동적 할당 메모리는 함수의 반환 값으로 힙 영역에 할당 된 메모리를 가리키는 void 포인터를 반환한다.
		* (즉, 동적 할당 함수는 단순히 필요한 메모리를 힙 영역에 할당하는 역할을 수행 할 뿐 해당 메모리에 어떤 데이터를 저장 및
		* 제어 할지는 알 수 없기 때문에 void 포인터를 반환하는 것을 알 수 있다.)
		* 
		* 따라서, 동적 할당 된 메모리를 제어하기 위해서는 특정 자료형 포인터로 형 변환해 줄 필요가 있다.
		*/
		int* pnVals01 = (int*)malloc(sizeof(int) * nSize);
		int* pnVals02 = (int*)malloc(sizeof(int) * (nNumRows * nNumCols));

		SetupVals(pnVals01, nSize);
		SetupVals(pnVals02, nNumRows * nNumCols);

		printf("=====> 1 차원 배열 요소 <=====\n");

		for(int i = 0; i < nSize; ++i) {
			printf("%d, ", pnVals01[i]);
		}

		printf("\n\n=====> 2 차원 배열 요소 <=====\n");

		for(int i = 0; i < nNumRows; ++i) {
			for(int j = 0; j < nNumCols; ++j) {
				printf("%2d, ", pnVals02[(i * nNumCols) + j]);
			}

			printf("\n");
		}

		free(pnVals01);
		free(pnVals02);
#elif defined E10_CALLOC
		STLinkedList stLinkedList;
		SetupList(&stLinkedList);

		for(int i = 0; i < 20; ++i) {
			AddVal(&stLinkedList, i + 1);
		}

		printf("=====> 리스트 요소 <=====\n");

		for(int i = 0; i < stLinkedList.m_nNumVals; ++i) {
			printf("%d, ", GetVal(&stLinkedList, i));
		}

		RemoveVal(&stLinkedList, 10);
		printf("\n\n=====> 리스트 요소 - 삭제 후 <=====\n");

		for(int i = 0; i < stLinkedList.m_nNumVals; ++i) {
			printf("%d, ", GetVal(&stLinkedList, i));
		}

		printf("\n");
		DestroyList(&stLinkedList);
#elif defined E10_REALLOC
		STArray stArray;
		SetupArray(&stArray, 5);

		int nSize = 0;

		printf("배열 길이 입력 : ");
		scanf("%d", &nSize);

		for(int i = 0; i < nSize; ++i) {
			AddVal(&stArray, i + 1);
		}

		printf("=====> 배열 요소 <=====\n");

		for(int i = 0; i < stArray.m_nNumVals; ++i) {
			printf("%d, ", GetVal(&stArray, i));
		}

		RemoveVal(&stArray, 10);
		printf("\n\n=====> 배열 요소 - 삭제 후 <=====\n");

		for(int i = 0; i < stArray.m_nNumVals; ++i) {
			printf("%d, ", GetVal(&stArray, i));
		}

		printf("\n");
		DestoryArray(&stArray);
#endif // #if defined E10_MALLOC

		return 0;
	}
}
