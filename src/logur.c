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

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include <logur.h>

/** @struct logur_t
 *  @brief This structure blah blah blah...
 *  @var logur_t::log_file
 *  Member 'log_file' contains...
 *  @var logur_t::log_level
 *  Member 'log_level' contains...
 */

typedef struct logur_t {
  int log_file;
  log_level_t log_level;
} logur_t;

logur_t *logur_init() { return (logur_t *)malloc(sizeof(logur_t)); }

void logur_ctor(logur_t* logur) {
	logur->log_file = STDOUT_FILENO;
	logur->log_level = INFO;
}

int __open_file(const char *file_name) {
  int fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  PERROR_IF(fd, "open file");

  return fd;
}

void logur_set_log_file(logur_t *logur, const char *file_name) {
	int fd = __open_file(file_name);
	logur->log_file = fd;
}
