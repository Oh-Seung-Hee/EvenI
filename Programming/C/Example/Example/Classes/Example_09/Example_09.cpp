#include "Example_09.h"

#define E09_STRUCT
#define E09_UNION
#define E09_ENUM

namespace E09 {
#if defined E09_STRUCT

#elif defined E09_UNION

#elif defined E09_ENUM

#endif // #if defined E09_STRUCT

	int Example_09(int argc, char* args[]) {
#if defined E09_STRUCT

#elif defined E09_UNION

#elif defined E09_ENUM

#endif // #if defined E09_STRUCT

		return 0;
	}
}
