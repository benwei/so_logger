/*
 * Copyright (C) 2015 ben@juluos.org
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 ****************************************************************
 * general simple log version 0.1
 **/

#ifndef STAROS_LOGGER_H
#define STAROS_LOGGER_H

#include <stdarg.h>
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
#define SOLOG_NONE    0
#define SOLOG_CRIT    2
#define SOLOG_ERR     3
#define SOLOG_WARNING 4
#define SOLOG_NOTICE  5
#define SOLOG_INFO    6
#define SOLOG_DEBUG   7


int sopenlog(const char *filename, int log_level);

void slog(int level, const char *fmt, ...);

#define SO_OPT_SET_LEVEL         1 /* value: int*/
#define SO_OPT_SET_MAX_LOG_LINE  2 /* value: unsigned int*/
#define SO_OPT_RESET_LOG_COUNTER 3 /* value: NULL */
#define DEFAULT_LOG_LINE_LIMIT 2048

void ssetlog_option(int option, void *value);

void scloselog(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* STAROS_LOGGER_H */
