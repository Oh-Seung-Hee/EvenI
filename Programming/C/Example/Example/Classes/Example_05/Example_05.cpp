#include "Example_05.h"

#define E05_LOOP_WHILE
#define E05_LOOP_FOR
#define E05_LOOP_DO_WHILE

namespace E05 {
	int Example_05(int argc, char* args[]) {
#if defined E05_LOOP_WHILE

#elif defined E05_LOOP_FOR

#elif defined E05_LOOP_DO_WHILE

#endif // #if defined E05_LOOP_WHILE

		return 0;
	}
}
