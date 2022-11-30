#include "Example_11.h"

#define E11_FILE_SYSTEM_01
#define E11_FILE_SYSTEM_02
#define E11_FILE_SYSTEM_03

namespace E11 {
#if defined E11_FILE_SYSTEM_01

#elif defined E11_FILE_SYSTEM_02

#elif defined E11_FILE_SYSTEM_03

#endif // #if defined E11_FILE_SYSTEM_01

	int Example_11(int argc, char* args[]) {
#if defined E11_FILE_SYSTEM_01

#elif defined E11_FILE_SYSTEM_02

#elif defined E11_FILE_SYSTEM_03

#endif // #if defined E11_FILE_SYSTEM_01

		return 0;
	}
}
