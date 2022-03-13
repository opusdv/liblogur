#include <stdlib.h>

#include <logur.h>

typedef struct logur_t {
	char*	log_file;
	int		log_level;		
} logur_t;

logur_t* logur_init() {
	return (logur_t*)malloc(sizeof(logur_t));
}


