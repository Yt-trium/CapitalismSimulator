#include "csagent.h"

int main(int argc, char *argv[])
{
    writeLog("CSAgent\n");
    writeLog("[CSA ]Checking arguments...\n");

    if(argc != 2)
    {
        printf("usage : %s id",argv[0]);
        return 1;
    }

    id = atoi(argv[1]);
    proceed = False;

    writeLog("[CSA%u]Registering RPC function...\n",id);

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

    svc_run();

    return 0;
}
