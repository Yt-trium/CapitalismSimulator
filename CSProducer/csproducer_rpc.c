#include "csproducer.h"

void *check()
{
    writeLog("-> check()\n");

    return NULL;
}

void *exit_()
{
    writeLog("-> exit_()\n");
    exit(0);

    return NULL;
}

void *ready()
{
    writeLog("-> ready()\n");
    proceed = True;

    // Request for a configuration load
    struct sigaction lc;
    lc.sa_handler = &loadConfig;
    sigaction(SIGALRM, &lc, NULL);
    alarm(1);

    return NULL;
}

void *goPlay()
{
    writeLog("-> goPlay()\n");
    produce(0);
    writeLog("-- end goPlay()\n");
    return NULL;
}

unsigned int *getStocks()
{
    static unsigned int r;
    r = stocks;

    writeLog("-> getStocks() - %u\n",stocks);
    return &r;
}

unsigned int *get(unsigned int *q)
{
    static unsigned int r;

    if(gc.exhaustibleResource)
    {
        r = min((*q),stocks);
        stocks -= r;

        writeLog("-> get(%u) - %u - new stocks %u\n",(*q),r,stocks);
    }
    else
        r = (*q);

    return &r;
}
