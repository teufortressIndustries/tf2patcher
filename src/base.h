// dont allow mingw to use msvcrt for stdio
#define __USE_MINGW_ANSI_STDIO 1
#define _GNU_SOURCE

#include <assert.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// normalize platform-dependent definitions
#if defined(_WIN32)
#define WINDOWS
#elif defined(__linux__) || defined(linux)
#define LINUX
#endif

#ifdef WINDOWS
#include "psapi.h"
#include "windows.h"
#elif defined(LINUX)
#include <fcntl.h>
#include <stdio.h>
#include <strings.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#endif
