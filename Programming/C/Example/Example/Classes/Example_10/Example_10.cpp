#include "Example_10.h"

#define E10_MALLOC
#define E10_CALLOC
#define E10_REALLOC

namespace E10 {
#if defined E10_MALLOC

#elif defined E10_CALLOC

#elif defined E10_REALLOC

#endif // #if defined E10_MALLOC

	int Example_10(int argc, char* args[]) {
#if defined E10_MALLOC

#elif defined E10_CALLOC

#elif defined E10_REALLOC

#endif // #if defined E10_MALLOC

		return 0;
	}
}
