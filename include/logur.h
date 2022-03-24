/****************************************************************************
 * Copyright (C) 2022 by Donatas Vaytukaytis                                *
 *                                                                          *
 * This file is part of Logur.                                              *
 *                                                                          *
 *   Logus is free software: you can redistribute it and/or modify it       *
 *   under the terms of the GNU General Public License as published  *
 *   by the Free Software Foundation, either version 3 of the License, or   *
 *   (at your option) any later version.                                    *
 *                                                                          *
 *   Logur is distributed in the hope that it will be useful,               *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *   GNU Lesser General Public License for more details.                    *
 *                                                                          *
 *   You should have received a copy of the GNU General Public
 ** License along with Box.  If not, see <http://www.gnu.org/licenses/>.   *
 ****************************************************************************/

#ifndef _LOGUR_H_
#define _LOGUR_H_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define PERROR_IF(cond, msg)                                                   \
  if (!cond) {                                                                 \
    perror(msg);                                                               \
    exit(EXIT_FAILURE);                                                        \
  }

typedef enum { DEBUG = 0, INFO, WARNING, ERROR } log_level_t;
struct logur_t;
struct logur_log_fmt_t;

extern struct logur_t *logur_init();
extern struct logur_log_fmt_t *logur_log_fmt_init();

extern void logur_ctor(struct logur_t *, struct logur_log_fmt_t *);
extern void logur_log_fmt_ctor(struct logur_log_fmt_t *);
extern void logur_dtor(struct logur_t *);
extern void logur_log_fmt_dtor(struct logur_log_fmt_t *);

extern void logur_set_log_file(struct logur_t *logur, const char *file_name);
extern void logur_set_log_level(struct logur_t *logur, log_level_t);
extern void logur_set_log_fmt(struct logur_t *logur, const char *func_name);
extern struct logur_log_fmt_t *logur_get_log_fmt(struct logur_t *logur);
extern int logur_get_log_level(struct logur_t *logur);

void logur_log(struct logur_t *logur, const char *func_name, int line,
               char *file, const char *msg, ...)
    __attribute__((format(printf, 5, 6)));

#define DEBUG(...) logur_log(logur, __func__, __LINE__, __FILE__, __VA_ARGS__)
#define INFO(...) lour_log(logur, __func__, __LINE__, __FILE__, __VA_ARGS__)
#define ERROR(...) logur_log(logur, __func__, __LINE__, __FILE__, __VA_ARGS__)
#define WARNING(...) logur_log(logur, __func__, __LINE__, __FILE__, __VA_ARGS__)

#endif
