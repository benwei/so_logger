#include <iostream>
#include <unistd.h>
#include "pthread.h"
#include <sys/types.h>
#include "so_logger.h"

using namespace std;

int main(int argc, char **argv)
{
    int level = SOLOG_DEBUG;
    sopenlog("./test.log", SOLOG_INFO);

    slog(SOLOG_INFO, "%s", "log1");

    slog(SOLOG_DEBUG, "%s","log2");

    ssetlog_option(SO_OPT_SET_LEVEL, &level);

    slog(SOLOG_DEBUG, "%s","log3");
    scloselog();
    return 0;
}
