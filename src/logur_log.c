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

#include <logur.h>

#include <stdlib.h>
#include <string.h>

void logur_log(struct logur_t *logur, const char *msg, ...) {
  int log_level = logur_get_log_level(logur);
  int str_len = strlen(msg);
  char *buffer = (char *)malloc(str_len + 1);
	PERROR_IF(buffer, "buffer malloc");

  va_list vl;
  va_start(vl, msg);
  vsnprintf(buffer, str_len + 1, msg, vl);
  va_end(vl);

  printf("%s\n", buffer);
  printf("%d\n", log_level);

  free(buffer);
}
