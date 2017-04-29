#include "csagent.h"

void *check()
{
    writeLog("[CSA%u]-> get checked\n",id);
    return NULL;
}

void *exit_()
{
    exit(0);
    return NULL;
}

void *ready()
{
    writeLog("[CSA%u]-> get ready (load in 1s)\n",id);
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
    writeLog("[CSA%u]I CAN PLAY\n",id);
    play(0);
    writeLog("[CSA%u]I HAVE PLAYED\n",id);
    return NULL;
}


unsigned int get(unsigned int q, unsigned int id_)
{
    writeLog("[CSA%u]get(%u) from %u\n",id,q,id_);
    enum clnt_stat stat;

    unsigned int q_ = q, r_ = 0;

    stat = callrpc( host_csproducer[id_],
                    PROGNUM_CSPRODUCER+id_,VERSNUM,
                    CSPRODUCER_GET,
                    (xdrproc_t) xdr_int,
                    (char *)&q_,
                    (xdrproc_t)xdr_int,
                    (char *)&r_
                   );

    if (stat != RPC_SUCCESS)
    {
        writeLog("[CSA%u]RPC ERROR\n",id) ;
        clnt_perrno(stat) ;
        exit(1);
    }

    unsigned int r = r_;
    writeLog("[CSA%u]r =  %u\n",id,r);
    return r;
}

unsigned int getStocks(unsigned int id_)
{
    // writeLog("[CSA%u]getStocks()\n",id);

    if(!gc.allowObservation)
        return 0;

    enum clnt_stat stat;

    unsigned int r_ = 0;

    stat = callrpc( host_csproducer[id_],
                    PROGNUM_CSPRODUCER+id_,VERSNUM,
                    CSPRODUCER_GETSTOCKS,
                    (xdrproc_t)xdr_void,
                    (char *)NULL,
                    (xdrproc_t)xdr_int,
                    (char *)&r_
                   );

    if (stat != RPC_SUCCESS)
    {
        writeLog("[CSA%u]RPC ERROR\n",id) ;
        clnt_perrno(stat) ;
        exit(1);
    }

    unsigned int r = r_;
    // writeLog("[CSA%u]r =  %u\n",id,r);
    return r;
}

void humanAgent()
{
    writeLog("[CSA%u]HUMAN AGENT ROUND\n",id);
    unsigned int c, a = 0;

    if(!gc.allowObservation)
        writeLog("[CSA%u]observation not allowed (always show 0)\n",id);
    printProducerStates();

    scanf("%d %d",&c, &a);
    writeLog("[CSA%u]I PLAY %u %u\n",id,c,a);

}

void loadConfig(int a)
{
    writeLog("[CSA%u]Loading GameConfig from CSCoordinator\n",id);
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
        writeLog("[CSA%u]RPC ERROR\n",id) ;
        clnt_perrno(stat) ;
        exit(1);
    }
    gc = r_;

    printf_GameConfig(gc);

    if(!gc.coordinatedActions)
    {
        struct sigaction p;
        p.sa_handler = &play;
        sigaction(SIGALRM, &p, NULL);
        ualarm (100000*CSAGENT_TIMER, 0);
    }
}

void play(int a)
{
    if(id < 10)
        humanAgent();
    else if(id < 20)
        indivAgent();
    else if(id < 30)
        coopAgent();
    else
        exit(3);

    checkEnd();

    if(!gc.coordinatedActions)
        ualarm(100000*CSAGENT_TIMER, 0);
}

void printProducerStates()
{
    unsigned int i,z;
    z=0;
    writeLog("[CSA%u]Showing all producer states\n",id);
    for(i=0;i<gc.R1NumberOfProducer;i++)
    {
        writeLog("[CSA%u]R1 P%u : %u\n",id,i,getStocks(i+z*5));
    }z++;
    for(i=0;i<gc.R2NumberOfProducer;i++)
    {
        writeLog("[CSA%u]R2 P%u : %u\n",id,i,getStocks(i+z*5));
    }z++;
    for(i=0;i<gc.R3NumberOfProducer;i++)
    {
        writeLog("[CSA%u]R3 P%u : %u\n",id,i,getStocks(i+z*5));
    }z++;
    for(i=0;i<gc.R4NumberOfProducer;i++)
    {
        writeLog("[CSA%u]R4 P%u : %u\n",id,i,getStocks(i+z*5));
    }z++;
    for(i=0;i<gc.R5NumberOfProducer;i++)
    {
        writeLog("[CSA%u]R5 P%u : %u\n",id,i,getStocks(i+z*5));
    }
}

void checkEnd()
{
    Boolean IWIN = True;

    if(gc.endCondition == 0)
        IWIN = False;
    if(stocksR1 < gc.endCondition && gc.R1NumberOfProducer > 0)
        IWIN = False;
    if(stocksR2 < gc.endCondition && gc.R2NumberOfProducer > 0)
        IWIN = False;
    if(stocksR3 < gc.endCondition && gc.R3NumberOfProducer > 0)
        IWIN = False;
    if(stocksR4 < gc.endCondition && gc.R4NumberOfProducer > 0)
        IWIN = False;
    if(stocksR5 < gc.endCondition && gc.R5NumberOfProducer > 0)
        IWIN = False;

    if(IWIN == True)
    {
        writeLog("[CSA%u] -----  I HAVE WIN -----",id);
        blingBling();

        callrpc( host_coordinator,
                 PROGNUM_CSCOORDINATOR,VERSNUM,
                 CSCOORDINATOR_ENDGAME,
                 (xdrproc_t)xdr_void,
                 (char *)NULL,
                 (xdrproc_t)xdr_void,
                 (char *)NULL
                 );
    }
}

void blingBling()
{
    writeLog("[CSA%u] %u %u %u %u %u\n",id,stocksR1,stocksR2,stocksR3,stocksR4,stocksR5);
}
