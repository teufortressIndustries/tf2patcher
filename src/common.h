#ifndef _COMMON_H_
#define _COMMON_H_

#include "base.h"
#include "sys/types.h"

typedef struct pinfo_s {
  bool verbose_mode;

#ifdef WINDOWS
  HANDLE process;
  HMODULE module;
#elif defined(LINUX)
  pid_t pid;
  int mem_fd;
  unsigned long offset;
#endif

  unsigned char *cl_base;
  size_t cl_size;

} pinfo_t;

extern const char path_sep;
extern const char *path_sep_str;

extern pinfo_t pinfo;

void verbose_print(const char *format, ...);
char *strlecpy(char *dst, const char *src, size_t sz);
char *extract_file_name(const char *name, char *buf, size_t sz);

#ifdef WINDOWS
char *describe_error(char *buf, size_t sz);
#endif

#endif
