#include "common.h"

#define TO_CHAR(x) #x
#define STR(x) TO_CHAR(x)

const char * version()
{
	return STR(PROJECT_VERSION_MAJOR) "."
			STR(PROJECT_VERSION_MINOR) "."
 			STR(PROJECT_VERSION_PATCH);
}