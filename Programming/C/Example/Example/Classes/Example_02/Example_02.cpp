#include "Example_02.h"

#define E02_VAR
#define E02_CONST

namespace E02 {
	int Example_02(int argc, char* args[]) {
#if defined E02_VAR

#elif defined E02_CONST

#endif // #if defined E02_VAR

		return 0;
	}
}
