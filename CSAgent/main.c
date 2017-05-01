#include "csagent.h"

int main(int argc, char *argv[])
{
    strcpy(me,"CSA__");
    writeLog("CSAgent\n");
    writeLog("Checking arguments...\n");

    if(argc != 2)
    {
        printf("usage : %s id",argv[0]);
        return 1;
    }

    id = atoi(argv[1]);
    sprintf(me,"CSA%02u",id);
    proceed = False;
    protecting = False;

    writeLog("Registering RPC function...\n");

    registerrpc(PROGNUM_CSAGENT+id,VERSNUM,PROC_CHECK,
                check,
                xdr_void,xdr_void);

    registerrpc(PROGNUM_CSAGENT+id,VERSNUM,PROC_EXIT,
                exit_,
                xdr_void,xdr_void);

    registerrpc(PROGNUM_CSAGENT+id,VERSNUM,PROC_READY,
                ready,
                xdr_void,xdr_void);

    registerrpc(PROGNUM_CSAGENT+id,VERSNUM,PROC_GOPLAY,
                goPlay,
                xdr_void,xdr_void);

    registerrpc(PROGNUM_CSAGENT+id,VERSNUM,CSAGENT_GETSTOCKS,
                getMyStocks,
                xdr_int,xdr_int);

    registerrpc(PROGNUM_CSAGENT+id,VERSNUM,CSAGENT_GET,
                getMy,
                xdr_int,xdr_int);

    writeLog("Launching svc_run()...\n");
    svc_run();

    return 0;
}
