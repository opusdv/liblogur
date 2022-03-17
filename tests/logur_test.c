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
 *   You should have received a copy of the GNU General Public              *
 *   License along with Box.  If not, see <http://www.gnu.org/licenses/>.   *
 ****************************************************************************/

#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <cmocka.h>

#include <logur.h>

static void test_logur_init() {
  struct logur_t *logur = logur_init();
  assert_non_null(logur);
}
int main(void) {
  const struct CMUnitTest tests[] = {cmocka_unit_test(test_logur_init)

  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
