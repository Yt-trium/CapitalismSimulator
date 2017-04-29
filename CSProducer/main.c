#include "csproducer.h"

int main(int argc, char *argv[])
{
    writeLog("CSProducer\n");
    writeLog("[CSP ]Checking arguments...\n");

    if(argc != 2)
    {
        writeLog("usage : %s id",argv[0]);
        return 1;
    }

    id = atoi(argv[1]);
    proceed = False;

    writeLog("[CSP%u]Registering RPC function...\n",id);

    registerrpc(PROGNUM_CSPRODUCER+id,VERSNUM,PROC_CHECK,
                check,
                xdr_void,xdr_void);

    registerrpc(PROGNUM_CSPRODUCER+id,VERSNUM,PROC_EXIT,
                exit_,
                xdr_void,xdr_void);

    registerrpc(PROGNUM_CSPRODUCER+id,VERSNUM,PROC_READY,
                ready,
                xdr_void,xdr_void);

    registerrpc(PROGNUM_CSPRODUCER+id,VERSNUM,PROC_GOPLAY,
                goPlay,
                xdr_void,xdr_void);

    registerrpc(PROGNUM_CSPRODUCER+id,VERSNUM,CSPRODUCER_GET,
                get,
                xdr_int,xdr_int);

    registerrpc(PROGNUM_CSPRODUCER+id,VERSNUM,CSPRODUCER_GETSTOCKS,
                getStocks,
                xdr_void,xdr_int);

    /*
    if(argc != 4)
    {
        writeLog("usage : %s id exhaustible(0/1) initialQuantity",argv[0]);
        return 1;
    }
    unsigned int id = atoi(argv[1]);

    if(atoi(argv[2]))
        exhaustible = TRUE;
    else
        exhaustible = FALSE;

    stocks = atoi(argv[3]);

    writeLog("CSProducer - stocks = %u\n",stocks);

    // RPC function
    registerrpc(PROGNUM_CSPRODUCER+id,VERSNUM,PROC_READY,
                ready,
                xdr_int,xdr_int);

    registerrpc(PROGNUM_CSPRODUCER+id,VERSNUM,CSPRODUCER_GET,
                get,
                xdr_int,xdr_int);

    registerrpc(PROGNUM_CSPRODUCER+id,VERSNUM,CSPRODUCER_GETSTOCKS,
                getStocks,
                xdr_int,xdr_int);

    if(exhaustible)
    {
        // Alarm for ressource production
        struct sigaction prod;
        prod.sa_handler = &produce;
        sigaction(SIGALRM, &prod, NULL);
        alarm(CSPRODCUER_TIMER);
    }
    */

    writeLog("[CSP%u]Launching svc_run()...\n",id);
    svc_run();

    return 0;
}
