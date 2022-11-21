#include "Practice_01.h"

#define P01_01

namespace P01 {
	int Practice_01(int argc, char* args[]) {
#if defined P01_01
		printf("ABCD\n");
		printf("%s\n", "ABCD");
		printf("%c%c%c%c\n", 'A', 'B', 'C', 'D');
		printf("%c%c%c%c\n", 65, 66, 67, 68);
#endif // #if defined P01_01

		return 0;
	}
}
