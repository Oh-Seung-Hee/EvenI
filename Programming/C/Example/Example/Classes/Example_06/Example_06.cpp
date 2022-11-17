#include "Example_06.h"

#define E06_SINGLE
#define E06_MULTI

namespace E06 {
	int Example_06(int argc, char* args[]) {
#if defined E06_SINGLE

#elif defined E06_MULTI

#endif // #if defined E06_SINGLE

		return 0;
	}
}
