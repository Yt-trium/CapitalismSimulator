#include "cscoordinator.h"

Boolean checkGameConfig(GameConfig a)
{
    /* Contrainte d'intégrité
     *
     * Humans > 0 => Coordinated actions = True
     *
     * 0 < Initial quantity <= 50000
     * 0 <= Number of producer <= 5
     * SUM(Number of producer) > 0
     * SUM(Agent) > 0
     * 0 <= Cooperative <= 10
     * 0 <= Individualistic <= 10
     * 0 <= Humans <= 10
    */

    if(a.humans > 0 && a.coordinatedActions != True)
    {
        printf("ERROR: arguments integrity\n");
        return 1;
    }

    if( a.R1NumberOfProducer > 5 ||
        a.R2NumberOfProducer > 5 ||
        a.R3NumberOfProducer > 5 ||
        a.R4NumberOfProducer > 5 ||
        a.R5NumberOfProducer > 5)
    {
        printf("ERROR: arguments integrity\n");
        return 1;
    }

    if(a.R1NumberOfProducer+a.R2NumberOfProducer+a.R3NumberOfProducer+
       a.R4NumberOfProducer+a.R5NumberOfProducer == 0)
    {
        printf("ERROR: arguments integrity\n");
        return 1;
    }
    if( a.cooperative > 10 ||
        a.individualistic > 10 ||
        a.humans > 10)
    {
        printf("ERROR: arguments integrity\n");
        return 1;
    }

    if(a.cooperative+a.individualistic+a.humans == 0)
    {
        printf("ERROR: arguments integrity\n");
        return 1;
    }

    return 0;
}

Boolean callAll(unsigned int n, unsigned int z, unsigned int type, unsigned int proc)
{
    unsigned int i;
    unsigned int r_ = 0;
    char* host;

    for(i=0;i<n;i++)
    {
        if(type == PROGNUM_CSAGENT)
            host = host_csagent[i+z*5];
        else
            host = host_csproducer[i+z*5];

        if(RPC_SUCCESS !=
                callrpc(host,
                type+i+z*5,VERSNUM,
                proc,
                (xdrproc_t)xdr_void,
                (char *)NULL,
                (xdrproc_t)xdr_void,
                (char *)NULL
                ))
        {
            printf("ERROR: callrpc with code %u-%u-%u\n",i,z,type);
            printf("host : %s\n",host);
            printf("prog : %u\n",type+i+z*5);
            printf("proc : %u\n",proc);
            return 1;
        }
    }
    return 0;
}

GameConfig *getConfig()
{
    static GameConfig *a = NULL;

    if(a!=NULL)
        free(a);

    a = malloc(sizeof(GameConfig));

    a->coordinatedActions = gc.coordinatedActions;
    a->exhaustibleResource = gc.exhaustibleResource;
    a->allowObservation = gc.allowObservation;
    a->Robbery = gc.Robbery;
    a->maxGet = gc.maxGet;
    a->endCondition = gc.endCondition;

    a->R1InitialQuantity  = gc.R1InitialQuantity;
    a->R1NumberOfProducer = gc.R1NumberOfProducer;
    a->R2InitialQuantity  = gc.R2InitialQuantity;
    a->R2NumberOfProducer = gc.R2NumberOfProducer;
    a->R3InitialQuantity  = gc.R3InitialQuantity;
    a->R3NumberOfProducer = gc.R3NumberOfProducer;
    a->R4InitialQuantity  = gc.R4InitialQuantity;
    a->R4NumberOfProducer = gc.R4NumberOfProducer;
    a->R5InitialQuantity  = gc.R5InitialQuantity;
    a->R5NumberOfProducer = gc.R5NumberOfProducer;

    a->humans = gc.humans;
    a->individualistic = gc.individualistic;
    a->cooperative = gc.cooperative;

    return a;
}

void makeThemPlay(int a)
{
    printf("Making the producer to play...\n");
    unsigned int z=0;
    if(callAll(gc.R1NumberOfProducer,z++,PROGNUM_CSPRODUCER,PROC_GOPLAY))
        exit(2);
    if(callAll(gc.R2NumberOfProducer,z++,PROGNUM_CSPRODUCER,PROC_GOPLAY))
        exit(2);
    if(callAll(gc.R3NumberOfProducer,z++,PROGNUM_CSPRODUCER,PROC_GOPLAY))
        exit(2);
    if(callAll(gc.R4NumberOfProducer,z++,PROGNUM_CSPRODUCER,PROC_GOPLAY))
        exit(2);
    if(callAll(gc.R5NumberOfProducer,z++,PROGNUM_CSPRODUCER,PROC_GOPLAY))
        exit(2);

    printf("Making the agent to play...\n");
    z=0;
    if(callAll(gc.humans,z,PROGNUM_CSAGENT,PROC_GOPLAY))
        exit(2);
    z+=2;
    if(callAll(gc.individualistic,z,PROGNUM_CSAGENT,PROC_GOPLAY))
        exit(2);
    z+=2;
    if(callAll(gc.cooperative,z,PROGNUM_CSAGENT,PROC_GOPLAY))
        exit(2);

    printf("End of the turn...\n");
    ualarm(100000, 0);
}

void *endGame()
{
    static Boolean x = False;

    if(x==True)
        return NULL;
    x=True;

    writeLog("CSC ENDING THE GAME\n");

    unsigned int z=0;
    writeLog("CSC ENDING R1\n");
    callAll(gc.R1NumberOfProducer,z++,PROGNUM_CSPRODUCER,PROC_EXIT);
    writeLog("CSC ENDING R2\n");
    callAll(gc.R2NumberOfProducer,z++,PROGNUM_CSPRODUCER,PROC_EXIT);
    writeLog("CSC ENDING R3\n");
    callAll(gc.R3NumberOfProducer,z++,PROGNUM_CSPRODUCER,PROC_EXIT);
    writeLog("CSC ENDING R4\n");
    callAll(gc.R4NumberOfProducer,z++,PROGNUM_CSPRODUCER,PROC_EXIT);
    writeLog("CSC ENDING R5\n");
    callAll(gc.R5NumberOfProducer,z++,PROGNUM_CSPRODUCER,PROC_EXIT);

    z=0;
    callAll(gc.humans,z,PROGNUM_CSPRODUCER,PROC_EXIT);
    z+=2;
    callAll(gc.individualistic,z,PROGNUM_CSPRODUCER,PROC_EXIT);
    z+=2;
    callAll(gc.cooperative,z,PROGNUM_CSPRODUCER,PROC_EXIT);
    z+=2;

    exit(0);
}
