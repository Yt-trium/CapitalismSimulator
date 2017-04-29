#include "cscoordinator.h"

int main(int argc, char *argv[])
{
    printf("CSCoordinator\n");
    printf("Checking arguments...\n");

    if(argc < 20)
    {
        printf("ERROR: too few arguments\n");
        exit(1);
    }
    if(argc > 20)
    {
        printf("ERROR: too much arguments\n");
        exit(1);
    }

    gc.coordinatedActions      = intToBool(atoi(argv[1]));
    gc.exhaustibleResource     = intToBool(atoi(argv[2]));
    gc.allowObservation        = intToBool(atoi(argv[3]));
    gc.Robbery                 = intToBool(atoi(argv[4]));
    gc.maxGet                  = atoi(argv[5]);
    gc.endCondition            = atoi(argv[6]);

    gc.R1InitialQuantity  = atoi(argv[7]);
    gc.R1NumberOfProducer = atoi(argv[8]);
    gc.R2InitialQuantity  = atoi(argv[9]);
    gc.R2NumberOfProducer = atoi(argv[10]);
    gc.R3InitialQuantity  = atoi(argv[11]);
    gc.R3NumberOfProducer = atoi(argv[12]);
    gc.R4InitialQuantity  = atoi(argv[13]);
    gc.R4NumberOfProducer = atoi(argv[14]);
    gc.R5InitialQuantity  = atoi(argv[15]);
    gc.R5NumberOfProducer = atoi(argv[16]);
    gc.humans             = atoi(argv[17]);
    gc.individualistic    = atoi(argv[18]);
    gc.cooperative        = atoi(argv[19]);

    if(checkGameConfig(gc))
        exit(1);

    unsigned int z;
    z = 0;

    printf("Checking producer process...\n");

    if(callAll(gc.R1NumberOfProducer,z++,PROGNUM_CSPRODUCER,PROC_CHECK))
        exit(2);
    if(callAll(gc.R2NumberOfProducer,z++,PROGNUM_CSPRODUCER,PROC_CHECK))
        exit(2);
    if(callAll(gc.R3NumberOfProducer,z++,PROGNUM_CSPRODUCER,PROC_CHECK))
        exit(2);
    if(callAll(gc.R4NumberOfProducer,z++,PROGNUM_CSPRODUCER,PROC_CHECK))
        exit(2);
    if(callAll(gc.R5NumberOfProducer,z++,PROGNUM_CSPRODUCER,PROC_CHECK))
        exit(2);

    z = 0;

    printf("Checking agent process...\n");

    if(callAll(gc.humans,z,PROGNUM_CSAGENT,PROC_CHECK))
        exit(2);
    z+=2;
    if(callAll(gc.individualistic,z,PROGNUM_CSAGENT,PROC_CHECK))
        exit(2);
    z+=2;
    if(callAll(gc.cooperative,z,PROGNUM_CSAGENT,PROC_CHECK))
        exit(2);

    printf("Registering RPC function...\n");

    registerrpc(PROGNUM_CSCOORDINATOR,VERSNUM,CSCOORDINATOR_GETCONFIG,
                getConfig,
                xdr_void,
                xdr_gc);


    registerrpc(PROGNUM_CSCOORDINATOR,VERSNUM,CSCOORDINATOR_ENDGAME,
                endGame,
                xdr_void,
                xdr_void);

    z = 0;

    printf("Ready for producer process...\n");
    if(callAll(gc.R1NumberOfProducer,z++,PROGNUM_CSPRODUCER,PROC_READY))
        exit(2);
    if(callAll(gc.R2NumberOfProducer,z++,PROGNUM_CSPRODUCER,PROC_READY))
        exit(2);
    if(callAll(gc.R3NumberOfProducer,z++,PROGNUM_CSPRODUCER,PROC_READY))
        exit(2);
    if(callAll(gc.R4NumberOfProducer,z++,PROGNUM_CSPRODUCER,PROC_READY))
        exit(2);
    if(callAll(gc.R5NumberOfProducer,z++,PROGNUM_CSPRODUCER,PROC_READY))
        exit(2);

    z = 0;

    printf("Ready for agent process...\n");

    if(callAll(gc.humans,z,PROGNUM_CSAGENT,PROC_READY))
        exit(2);
    z+=2;
    if(callAll(gc.individualistic,z,PROGNUM_CSAGENT,PROC_READY))
        exit(2);
    z+=2;
    if(callAll(gc.cooperative,z,PROGNUM_CSAGENT,PROC_READY))
        exit(2);

    if(gc.coordinatedActions)
    {
        struct sigaction p;
        p.sa_handler = &makeThemPlay;
        sigaction(SIGALRM, &p, NULL);
        alarm(2);
    }

    printf("Launching svc_run()...\n");
    svc_run();


    return 0;
}
