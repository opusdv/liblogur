#include <logur.h>
#include <stdio.h>

int main() {
  struct logur_t *logur = logur_init();
	struct logur_log_fmt_t* log_fmt = logur_log_fmt_init();
	
  logur_ctor(logur, log_fmt);

	DEBUG("test");

	logur_log_fmt_dtor(log_fmt);	
  logur_dtor(logur);
  return 0;
}
