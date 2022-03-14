/****************************************************************************
 * Copyright (C) 2022 by Donatas Vaytukaytis								*
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
 *   You should have received a copy of the GNU General Public				*
 *   License along with Box.  If not, see <http://www.gnu.org/licenses/>.   *
 ****************************************************************************/

#include <logur.h>

typedef struct logur_t {
  char *log_file;
  int log_level;
} logur_t;

logur_t *logur_init() { return (logur_t *)malloc(sizeof(logur_t)); }
