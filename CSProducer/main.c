#include <rpc/types.h>
#include <rpc/xdr.h>
#include <rpc/rpc.h>

#include "csproducer.h"

int main(int argc, char *argv[])
{
    printf("CSProducer - stocks = %u\n",stocks);

    // RPC function
    registerrpc(PROGNUM,VERSNUM,CSPRODUCER_GET,
                get,
                xdr_int,xdr_int);

    registerrpc(PROGNUM,VERSNUM,CSPRODUCER_GETSTOCKS,
                getStocks,
                xdr_int,xdr_int);

    // Alarm for ressource production
    struct sigaction prod;
    prod.sa_handler = &produce;
    sigaction(SIGALRM, &prod, NULL);
    alarm(CSPRODCUER_TIMER);

    // Launch RPC
    svc_run();

    return 0;
}
