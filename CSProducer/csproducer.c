#include "csproducer.h"

void loadConfig(int a)
{
    writeLog("Loading GameConfig from CSCoordinator\n");
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
        writeLog("RPC ERROR\n");
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
    if(gc.endCondition == 0 && stocks == 0)
        return;

    unsigned int old_ = stocks;
    stocks += stocks/2 + 1;
    writeLog("- produce() [before : %u - after  : %u]\n",old_,stocks);

    if(!gc.coordinatedActions)
        ualarm (100000*CSPRODUCER_TIMER, 0);
}
