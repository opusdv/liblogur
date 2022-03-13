#ifndef _LOGUR_H_
#define _LOGUR_H_

#define PERROR_IF(conf, msg) if (cond) {perror(msg); exit(EXIT_FAILURE);}

typedef enum {
	DEBUG = 0,
	INFO,
	WARNING,
	ERROR
} log_level_t;

struct logur_t;

struct logur_t* logur_init();
void do_log();
void logur_fini();

#endif
