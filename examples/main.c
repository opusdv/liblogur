#include <logur.h>

int main() {
  struct logur_t *logur = logur_init();
  PERROR_IF(logur, "logur_init()");

  logur_ctor(logur);

  logur_dtor(logur);
  return 0;
}
