#include "csproducer.h"

int main(int argc, char *argv[])
{
    strcpy(me,"CSP__");

    writeLog("CSProducer\n");
    writeLog("Checking arguments...\n");

    if(argc != 2)
    {
        writeLog("usage : %s id",argv[0]);
        return 1;
    }

    id = atoi(argv[1]);
    sprintf(me,"CSP%02u",id);
    proceed = False;

    writeLog("Registering RPC function...\n");

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

    writeLog("Launching svc_run()...\n");
    svc_run();

    return 0;
}
