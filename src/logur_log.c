#include <logur.h>

#include <stdlib.h>
#include <string.h>

void logur_log(struct logur_t *logur, const char *msg, ...) {
  int log_level = logur_get_log_level(logur);
  int str_len = strlen(msg);
  char *buffer = (char *)malloc(str_len + 1);

  va_list vl;
  va_start(vl, msg);
  vsnprintf(buffer, str_len + 1, msg, vl);
  va_end(vl);

  printf("%s\n", buffer);
  printf("%d\n", log_level);

  free(buffer);
}
