/****************************************************************************
 * Copyright (C) 2022 by Donatas Vaytukaytis
 **
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

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include <logur.h>

/** @struct logur_t
 *  @brief This structure blah blah blah...
 *  @var logur_t::log_file
 *  Member 'log_file' contains...
 *  @var logur_t::log_level
 *  Member 'log_level' contains...
 */

typedef struct logur_log_fmt_t {
  const char *func_name;
  char *file_name;
  int line;
  char *time;
  char *date;
  char *timestamp;
  int pid;
  int tid;
} logur_log_fmt_t;

typedef struct logur_t {
  logur_log_fmt_t *log_fmt;
  int log_file;
  log_level_t log_level;
} logur_t;

// Init functions
logur_t *logur_init() {
  logur_t *logur = (logur_t *)malloc(sizeof(logur_t));
  PERROR_IF(logur, "logur malloc");
  return logur;
}

logur_log_fmt_t *logur_log_fmt_init() {
  logur_log_fmt_t *log_fmt = (logur_log_fmt_t *)malloc(sizeof(logur_log_fmt_t));
  PERROR_IF(log_fmt, "log_fmt malloc");
  return log_fmt;
}

// Ctor/Dtor functions
void logur_ctor(logur_t *logur, logur_log_fmt_t *log_fmt) {
  logur->log_file = STDOUT_FILENO;
  logur->log_level = INFO;
  logur->log_fmt = log_fmt;
}

void logur_dtor(logur_t *logur) { free(logur); }

void logur_log_fmt_dtor(logur_log_fmt_t *log_fmt) { free(log_fmt); }

// Private funnctions
static int __open_file(const char *file_name) {
  int fd = open(file_name, O_WRONLY | O_CREAT, S_IRWXU | S_IRWXG);
  PERROR_IF(fd, "open file");
  return fd;
}

// Setter/Getter functions
void logur_set_log_file(logur_t *logur, const char *file_name) {
  int fd = __open_file(file_name);
  logur->log_file = fd;
}

void logur_set_log_level(logur_t *logur, log_level_t log_level) {
  logur->log_level = log_level;
}

int logur_get_log_level(logur_t *logur) { return logur->log_level; }
