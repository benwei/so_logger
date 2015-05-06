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
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <pthread.h>
#include "so_logger.h"

static FILE *fp = NULL;
static int _log_level = SOLOG_NONE;
static unsigned int log_counter = 0;
static unsigned int _log_max_line = DEFAULT_LOG_LINE_LIMIT;

int sopenlog(const char *filename, int log_level)
{
    fp = fopen(filename, "a+");
    if (!fp) return 1;
        fprintf(fp, "so_logger version:%s\n", REL_VERSION);

    _log_level = log_level;
    return 0;
}

void ssetlog_option(int option, void *value)
{
    if (!value) return ;
    switch (option) {
        case SO_OPT_SET_LEVEL:
            _log_level = *(int*)value & 0xff;
        break;
        case SO_OPT_SET_MAX_LOG_LINE:
            _log_max_line = *(unsigned int*)value;
        break;
        case SO_OPT_RESET_LOG_COUNTER:
            log_counter = 0;
        break;
    }
}

static pthread_mutex_t log_lock = PTHREAD_MUTEX_INITIALIZER;

#define MAX_BUF_SIZE 2048
char buf[MAX_BUF_SIZE] = {};

#define MAX_TIME_SIZE 24
char buf_time[MAX_TIME_SIZE] = {};

void slog(int level, const char *fmt, ...)
{
    va_list ptr;
    time_t t = 0;
    struct tm *ts = NULL;
    if (!fp || level > _log_level || log_counter > _log_max_line) return ;
    log_counter++;
    pthread_mutex_lock(&log_lock);
    t = time(NULL);
    ts = localtime(&t);
    strftime(buf_time, sizeof(buf_time)-1, "%Y-%m-%d %H:%M:%S", ts);
    va_start(ptr, fmt);
    vsnprintf(buf, sizeof(buf), fmt, ptr);
    va_end(ptr);
    fprintf(fp, "%s %s\n", buf_time, buf);
    fflush(fp);
    pthread_mutex_unlock(&log_lock);
}

void scloselog(void)
{
    if (!fp) return;

    fclose(fp);
}
