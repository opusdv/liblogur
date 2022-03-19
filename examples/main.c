#include <logur.h>

int main() {
  struct logur_t *logur = logur_init();
  PERROR_IF(logur, "logur_init()");

  return 0;
}
