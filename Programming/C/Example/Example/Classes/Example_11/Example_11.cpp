#include "Example_11.h"

#define E11_FILE_SYS_01
#define E11_FILE_SYS_02
#define E11_FILE_SYS_03
#define E11_FILE_SYS_04

namespace E11 {
#if defined E11_FILE_SYS_01

#elif defined E11_FILE_SYS_02

#elif defined E11_FILE_SYS_03

#elif defined E11_FILE_SYS_04
	/** 텍스트 파일을 복사한다 */
	void CopyTextFile(char a_pszSrcPath[], char a_pszDestPath[]) {
		FILE* pfRStream = fopen(a_pszSrcPath, "rt");
		FILE* pfWStream = fopen(a_pszDestPath, "wt");

		// 파일이 존재 할 경우
		if(pfRStream != NULL && pfWStream != NULL) {
			char szBuffer[100] = "";

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

				printf("%s\n", szStr);
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
				fwrite(&i, sizeof(i), 1, pfWStream);
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
