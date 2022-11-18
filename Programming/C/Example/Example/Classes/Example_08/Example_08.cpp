#include "Example_08.h"

#define E08_SINGLE
#define E08_DOUBLE

namespace E08 {
	int Example_08(int argc, char* args[]) {
#if defined E08_SINGLE

#elif defined E08_DOUBLE

#endif // #if defined E08_SINGLE

		return 0;
	}
}
