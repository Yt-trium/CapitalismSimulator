#include "csagent.h"

void *check()
{
    writeLog("-> check()\n");

    return NULL;
}

void *exit_()
{
    writeLog("-> exit_()\n");
    blingBling();
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
    play(0);
    writeLog("-- end goPlay()\n");
    return NULL;
}

unsigned int *getMyStocks(Resource *i)
{
    static unsigned int r;
    writeLog("-> getMyStocks(%u) - %u\n",(*i),r);

    if(gc.allowObservation)
    {
    switch((*i))
    {
        case RSRC1:
            r = stocksR1;
        break;
        case RSRC2:
            r = stocksR2;
        break;
        case RSRC3:
            r = stocksR3;
        break;
        case RSRC4:
            r = stocksR4;
        break;
        case RSRC5:
            r = stocksR5;
        break;
        default:
            r = 0;
        break;
    }
    }
    else
        r = 0;

    writeLog("-> getMyStocks(%u) - %u\n",(*i),r);
    return &r;
}

unsigned int *getMy(Resource *i)
{
    static unsigned int r;

    if(gc.Robbery)
    {
        if(protecting == True)
        {
            r = 0;

            switch((*i))
            {
            case RSRC1:
                stocksR1 += gc.maxGet*2;
            break;
            case RSRC2:
                stocksR2 += gc.maxGet*2;
            break;
            case RSRC3:
                stocksR3 += gc.maxGet*2;
            break;
            case RSRC4:
                stocksR4 += gc.maxGet*2;
            break;
            case RSRC5:
                stocksR5 += gc.maxGet*2;
            break;
            }
        }
        // Else...
        switch((*i))
        {
            case RSRC1:
            r = min(stocksR1,gc.maxGet);
            stocksR1 -= r;
            break;
            case RSRC2:
            r = min(stocksR2,gc.maxGet);
            stocksR2 -= r;
            break;
            case RSRC3:
            r = min(stocksR3,gc.maxGet);
            stocksR3 -= r;
            break;
            case RSRC4:
            r = min(stocksR4,gc.maxGet);
            stocksR4 -= r;
            break;
            case RSRC5:
            r = min(stocksR5,gc.maxGet);
            stocksR5 -= r;
            break;
            default:
                r = 0;
            break;
        }
    }
    else
        r = 0;

    writeLog("-> getMy(%u) - %u\n",(*i),r);
    return &r;
}
