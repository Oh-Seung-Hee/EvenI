#include "Example_11.h"

//#define E11_FILE_SYS_01
//#define E11_FILE_SYS_02
//#define E11_FILE_SYS_03
//#define E11_FILE_SYS_04
#define E11_FILE_SYS_05

namespace E11 {
#if defined E11_FILE_SYS_01

#elif defined E11_FILE_SYS_02

#elif defined E11_FILE_SYS_03

#elif defined E11_FILE_SYS_04

#elif defined E11_FILE_SYS_05
	/** 텍스트 파일을 복사한다 */
	void CopyTextFile(char a_pszSrcPath[], char a_pszDestPath[]) {
		FILE* pfRStream = fopen(a_pszSrcPath, "rt");
		FILE* pfWStream = fopen(a_pszDestPath, "wt");

		// 파일이 존재 할 경우
		if(pfRStream != NULL && pfWStream != NULL) {
			char szBuffer[100] = "";

			/*
			 * fgets 함수는 특정 파일에서 더이상 읽어들일 데이터가 없을 경우 NULL 포인터를 반환하는 특징이 존재한다. 따라서,
			 * 해당 특징을 활용하면 파일에 존재하는 모든 데이터를 가져오는 것이 가능하다.
			 */
			while(fgets(szBuffer, sizeof(szBuffer), pfRStream) != NULL) {
				fputs(szBuffer, pfWStream);
			}

			fclose(pfRStream);
			fclose(pfWStream);
		}
	}

	/** 바이너리 파일을 복사한다 */
	void CopyBinaryFile(char a_pszSrcPath[], char a_pszDestPath[]) {
		FILE* pfRStream = fopen(a_pszSrcPath, "rb");
		FILE* pfWStream = fopen(a_pszDestPath, "wb");

		// 파일이 존재 할 경우
		if(pfRStream != NULL && pfWStream != NULL) {
			int nNumBytes = 0;
			unsigned char anBuffer[100] = { 0 };

			/*
			 * fread 함수는 읽어들인 데이터의 바이트 크기를 반환하는 특징이 존재한다. (즉, 해당 특징을 활용하면 특정 파일에
			 * 존재하는 모든 데이터를 가져오는 것이 가능하다.)
			 */
			while((nNumBytes = fread(anBuffer, sizeof(unsigned char), sizeof(anBuffer), pfRStream)) > 0) {
				fwrite(anBuffer, sizeof(unsigned char), nNumBytes, pfWStream);
			}

			fclose(pfRStream);
			fclose(pfWStream);
		}
	}
#endif // #if defined E11_FILE_SYS_01

	int Example_11(int argc, char* args[]) {
#if defined E11_FILE_SYS_01
		FILE* pfWStream = fopen("Resources/Example_11/Example_11_01.txt", "wt");

		// 파일이 존재 할 경우
		if(pfWStream != NULL) {
			for(int i = 0; i < 10; ++i) {
				fprintf(pfWStream, "Hello, World!\n");
			}

			fclose(pfWStream);
		}

		FILE* pfRStream = fopen("Resources/Example_11/Example_11_01.txt", "rt");

		// 파일이 존재 할 경우
		if(pfRStream != NULL) {
			for(int i = 0; i < 10; ++i) {
				char szStr[100] = "";
				fscanf(pfRStream, "%s", szStr);

				/*
				 * C 표준 입/출력 스트림 종류
				 * - stdin		<- 콘솔 입력 스트림
				 * - stdout		<- 콘솔 출력 스트림
				 * 
				 * 표준 입/출력 스트림이란?
				 * - C 로 제작 된 콘솔 프로그램이 실행 될 때 콘솔 프로그램 간에 데이터를 입/출력하기 위해서는 자동으로 생성되는 스트림을 의미한다.
				 * (즉, printf/scanf 함수는 내부적으로 표준 입/출력 스트림을 통해서 데이터를 입/출력한다는 것을 알 수 있다.)
				 */
				fprintf(stdout, "%s\n", szStr);
			}

			fclose(pfRStream);
		}
#elif defined E11_FILE_SYS_02
		FILE* pfWStream = fopen("Resources/Example_11/Example_11_02.txt", "wt");

		// 파일이 존재 할 경우
		if(pfWStream != NULL) {
			for(int i = 0; i < 10; ++i) {
				fputs("Hello, World!\n", pfWStream);
			}

			fclose(pfWStream);
		}

		FILE* pfRStream = fopen("Resources/Example_11/Example_11_02.txt", "rt");

		// 파일이 존재 할 경우
		if(pfRStream != NULL) {
			for(int i = 0; i < 10; ++i) {
				char szStr[100] = "";
				fgets(szStr, sizeof(szStr), pfRStream);

				/*
				 * fgets 함수는 개행 문자를 기준으로 문자열을 읽어들이는 함수이기 때문에 해당 함수를 통해 특정 파일로부터
				 * 문자열을 읽어들였을 경우 해당 문자열에 개행 문자가 포함되어있을 수 있다.
				 */
				// 개행 문자가 존재 할 경우
				if(szStr[strlen(szStr) - 1] == '\n') {
					szStr[strlen(szStr) - 1] = '\0';
				}

				printf("%s\n", szStr);
			}

			fclose(pfRStream);
		}
#elif defined E11_FILE_SYS_03
		FILE* pfWStream = fopen("Resources/Example_11/Example_11_03.bin", "wb");

		// 파일이 존재 할 경우
		if(pfWStream != NULL) {
			for(int i = 0; i < 10; ++i) {
				int nVal = 'A' + i;

				/*
				 * fread/fwrite 함수는 특정 데이터를 N 개 이상 입/출력하는 것이 가능하다. (즉, 해당 함수를 활용하면 배열을
				 * 특정 파일에 입/출력하는 것이 가능하다.
				 */
				fwrite(&nVal, sizeof(i), 1, pfWStream);
			}

			fclose(pfWStream);
		}

		FILE* pfRStream = fopen("Resources/Example_11/Example_11_03.bin", "rb");

		// 파일이 존재 할 경우
		if(pfRStream != NULL) {
			for(int i = 0; i < 10; ++i) {
				int nVal = 0;
				fread(&nVal, sizeof(nVal), 1, pfRStream);

				printf("%d, ", nVal);
			}

			fclose(pfRStream);
		}
#elif defined E11_FILE_SYS_04
		// 매개 변수가 유효 할 경우
		if(argc > 1) {
			FILE* pfRStream = fopen(args[1], "rb");

			// 파일이 존재 할 경우
			if(pfRStream != NULL) {
				/*
				 * fseek 함수는 입/출력하기 위한 파일 포인터 위치를 변경하는 역할을 수행한다. (즉, 해당 함수를 활용하면 특정
				 * 위치를 기준으로 데이터 입/출력 위치를 변경하는 것이 가능하다.)
				 * 
				 * C 파일 포인터 위치 기준 종류
				 * - SEEK_CUR	<- 현재 위치가 기준
				 * - SEEK_SET	<- 파일 첫 위치가 기준
				 * - SEEK_END	<- 파일 마지막 위치가 기준
				 * 
				 * ftell 함수는 현재 파일 포인터 위치를 가져오는 역할을 수행한다. (즉, 해당 함수와 fseek 함수를 활용하면
				 * 읽어들일 파일의 크기를 계산하는 것이 가능하다.)
				 */
				fseek(pfRStream, 0, SEEK_END);
				printf("파일 크기 : %d bytes\n", ftell(pfRStream));

				fclose(pfRStream);
			} else {
				printf("%s 파일이 존재하지 않습니다.\n", args[1]);
			}
		} else {
			printf("[실행 파일 경로] [파일 경로] 형식으로 입력해주세요.\n");
		}
#elif defined E11_FILE_SYS_05
		// 매개 변수가 유효 할 경우
		if(argc > 3) {
			// 텍스트 모드 일 경우
			if(strcmp(args[3], "t") == 0) {
				CopyTextFile(args[1], args[2]);
			}
			// 바이너리 모드 일 경우
			else if(strcmp(args[3], "b") == 0) {
				CopyBinaryFile(args[1], args[2]);
			}
		} else {
			printf("[실행 파일 경로] [복사 할 파일 경로] [복사 될 파일 경로] [파일 복사 모드] 형식으로 입력해주세요.\n");
		}
#endif // #if defined E11_FILE_SYS_01

		return 0;
	}
}
