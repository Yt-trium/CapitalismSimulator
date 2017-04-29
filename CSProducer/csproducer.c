#include "csproducer.h"

void *check()
{
    writeLog("[CSP%u]-> get checked\n",id);
    return NULL;
}

void *exit_()
{
    exit(0);
    return NULL;
}

void *ready()
{
    writeLog("[CSP%u]-> get ready (load in 1s)\n",id);
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
    writeLog("[CSP%u]I CAN PLAY\n",id);
    produce(0);
    writeLog("[CSP%u]I HAVE PLAYED\n",id);
    return NULL;
}


unsigned int *getStocks()
{
    static unsigned int r;
    r = stocks;

    writeLog("[CSP%u][getStocks]stocks = %u\n",id,stocks);
    return &r;
}

unsigned int *get(unsigned int *q)
{
    static unsigned int r;

    if(gc.exhaustibleResource)
    {
        r = min((*q),stocks);
        stocks -= r;

        writeLog("[CSP%u][get      ]stocks = %u\n",id,stocks);
    }
    else
        r = (*q);

    return &r;
}


void loadConfig(int a)
{
    writeLog("[CSP%u]Loading GameConfig from CSCoordinator\n",id);
    enum clnt_stat stat;
    GameConfig r_;
    stat = callrpc( host_coordinator,
                    PROGNUM_CSCOORDINATOR,VERSNUM,
                    CSCOORDINATOR_GETCONFIG,
                    (xdrproc_t)xdr_void,
                    (char *)NULL,
                    (xdrproc_t)xdr_gc,
                    (char *)&r_
                   );

    if (stat != RPC_SUCCESS)
    {
        writeLog("[CSP%u]RPC ERROR\n",id);
        clnt_perrno(stat) ;
        exit(1);
    }
    gc = r_;

    printf_GameConfig(gc);

    if(gc.exhaustibleResource)
    {
        if(!gc.coordinatedActions)
        {
            // Alarm for ressource production
            struct sigaction prod;
            prod.sa_handler = &produce;
            sigaction(SIGALRM, &prod, NULL);
            // alarm(CSPRODUCER_TIMER);
            ualarm (100000*CSPRODUCER_TIMER, 0);
        }
    }

    unsigned int init;
    if(id < 5)
        init = gc.R1InitialQuantity;
    else if(id < 10)
        init = gc.R2InitialQuantity;
    else if(id < 15)
        init = gc.R3InitialQuantity;
    else if(id < 20)
        init = gc.R4InitialQuantity;
    else if(id < 25)
        init = gc.R5InitialQuantity;
    else
        exit(3);

    stocks = init;
}


void produce(int a)
{
    stocks += stocks/2 + 1;
    writeLog("[CSP%u][produce  ]stocks = %u\n",id,stocks);
    // alarm(CSPRODUCER_TIMER);

    if(!gc.coordinatedActions)
        ualarm (100000*CSPRODUCER_TIMER, 0);
}
