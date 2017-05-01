#include "csagent.h"

unsigned int get(unsigned int q, unsigned int id_)
{
    writeLog("get(%u) from %u\n",q,id_);
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
        writeLog("RPC ERROR\n") ;
        clnt_perrno(stat) ;
        exit(1);
    }

    unsigned int r = r_;
    writeLog("get(%u) from %u returned %u\n",q,id_,r);
    return r;
}

unsigned int getStocks(unsigned int id_)
{
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
        writeLog("RPC ERROR\n") ;
        clnt_perrno(stat) ;
        exit(1);
    }

    unsigned int r = r_;
    return r;
}

unsigned int getAgentStocks(unsigned int id_, Resource rs)
{
    if(id_ == id)
        return 0;

    if(!gc.allowObservation)
        return 0;

    enum clnt_stat stat;

    unsigned int r_ = 0;

    stat = callrpc( host_csagent[id_],
                    PROGNUM_CSAGENT+id_,VERSNUM,
                    CSAGENT_GETSTOCKS,
                    (xdrproc_t)xdr_int,
                    (char *)&rs,
                    (xdrproc_t)xdr_int,
                    (char *)&r_
                   );

    if (stat != RPC_SUCCESS)
    {
        writeLog("RPC ERROR\n");
        clnt_perrno(stat);
        exit(1);
    }

    unsigned int r = r_;
    return r;
}



unsigned int getAgent(unsigned int id_, Resource rs)
{
    if(!gc.Robbery)
        return 0;

    enum clnt_stat stat;

    unsigned int r_ = 0;

    stat = callrpc( host_csagent[id_],
                    PROGNUM_CSAGENT+id_,VERSNUM,
                    CSAGENT_GET,
                    (xdrproc_t)xdr_int,
                    (char *)rs,
                    (xdrproc_t)xdr_int,
                    (char *)&r_
                   );

    if (stat != RPC_SUCCESS)
    {
        writeLog("RPC ERROR\n");
        clnt_perrno(stat);
        exit(1);
    }

    unsigned int r = r_;
    return r;
}


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
    protecting = False;

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
    writeLog("Showing all producer states\n");
    for(i=0;i<gc.R1NumberOfProducer;i++)
    {
        writeLog("R1 P%u : %u\n",i,getStocks(i+z*5));
    }z++;
    for(i=0;i<gc.R2NumberOfProducer;i++)
    {
        writeLog("R2 P%u : %u\n",i,getStocks(i+z*5));
    }z++;
    for(i=0;i<gc.R3NumberOfProducer;i++)
    {
        writeLog("R3 P%u : %u\n",i,getStocks(i+z*5));
    }z++;
    for(i=0;i<gc.R4NumberOfProducer;i++)
    {
        writeLog("R4 P%u : %u\n",i,getStocks(i+z*5));
    }z++;
    for(i=0;i<gc.R5NumberOfProducer;i++)
    {
        writeLog("R5 P%u : %u\n",i,getStocks(i+z*5));
    }
}

void printAgentStates()
{
    unsigned int i,z;
    z=0;
    writeLog("Showing all agent states\n");
    for(i=0;i<gc.humans;i++)
    {
        writeLog("R1 A%02u : %u\n",i+z*10,getAgentStocks(i+z*10,RSRC1));
        writeLog("R2 A%02u : %u\n",i+z*10,getAgentStocks(i+z*10,RSRC2));
        writeLog("R3 A%02u : %u\n",i+z*10,getAgentStocks(i+z*10,RSRC3));
        writeLog("R4 A%02u : %u\n",i+z*10,getAgentStocks(i+z*10,RSRC4));
        writeLog("R5 A%02u : %u\n",i+z*10,getAgentStocks(i+z*10,RSRC5));
    }z++;
    for(i=0;i<gc.individualistic;i++)
    {
        writeLog("R1 A%02u : %u\n",i+z*10,getAgentStocks(i+z*10,RSRC1));
        writeLog("R2 A%02u : %u\n",i+z*10,getAgentStocks(i+z*10,RSRC2));
        writeLog("R3 A%02u : %u\n",i+z*10,getAgentStocks(i+z*10,RSRC3));
        writeLog("R4 A%02u : %u\n",i+z*10,getAgentStocks(i+z*10,RSRC4));
        writeLog("R5 A%02u : %u\n",i+z*10,getAgentStocks(i+z*10,RSRC5));
    }z++;
    for(i=0;i<gc.cooperative;i++)
    {
        writeLog("R1 A%02u : %u\n",i+z*10,getAgentStocks(i+z*10,RSRC1));
        writeLog("R2 A%02u : %u\n",i+z*10,getAgentStocks(i+z*10,RSRC2));
        writeLog("R3 A%02u : %u\n",i+z*10,getAgentStocks(i+z*10,RSRC3));
        writeLog("R4 A%02u : %u\n",i+z*10,getAgentStocks(i+z*10,RSRC4));
        writeLog("R5 A%02u : %u\n",i+z*10,getAgentStocks(i+z*10,RSRC5));
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
        writeLog("-----  I HAVE WIN -----\n");
        blingBling();
        writeLog("-----  CALING END GAME IN 1 S -----\n");

        struct sigaction x;
        x.sa_handler = &callEnd;
        sigaction(SIGALRM, &x, NULL);
        alarm(1);
    }

    writeLog("return\n");
    return;
}

void blingBling()
{
    writeLog("score : %u %u %u %u %u\n",stocksR1,stocksR2,stocksR3,stocksR4,stocksR5);
}

void callEnd(int a)
{
    writeLog("callEnd\n");

    enum clnt_stat stat;
    stat = callrpc( host_coordinator,
                    PROGNUM_CSCOORDINATOR,VERSNUM,
                    CSCOORDINATOR_ENDGAME,
                    (xdrproc_t)xdr_void,
                    (char *)NULL,
                    (xdrproc_t)xdr_void,
                    (char *)NULL
                    );

    if (stat != RPC_SUCCESS)
    {
        writeLog("RPC ERROR\n");
        clnt_perrno(stat) ;
        exit(1);
    }
}
