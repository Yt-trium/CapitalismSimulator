#include "csagent.h"

unsigned int get(unsigned int q)
{
    printf("get(%u)\n",q);
    enum clnt_stat stat;

    unsigned int q_ = q, r_ = 0;

    stat = callrpc( host,
                    PROGNUM,VERSNUM,
                    CSPRODUCER_GET,
                    (xdrproc_t) xdr_int,
                    (char *)&q_,
                    (xdrproc_t)xdr_int,
                    (char *)&r_
                   );

    if (stat != RPC_SUCCESS)
    {
        fprintf(stderr, "RPC ERROR\n") ;
        clnt_perrno(stat) ;
        fprintf(stderr, "\n") ;
        exit(1);
    }

    unsigned int r = r_;
    printf("r =  %u\n",r);
    return r;
}

unsigned int getStocks()
{
    printf("getStocks()\n");
    enum clnt_stat stat;

    unsigned int r_ = 0;

    stat = callrpc( host,
                    PROGNUM,VERSNUM,
                    CSPRODUCER_GETSTOCKS,
                    (xdrproc_t)xdr_void,
                    (char *)NULL,
                    (xdrproc_t)xdr_int,
                    (char *)&r_
                   );

    if (stat != RPC_SUCCESS)
    {
        fprintf(stderr, "RPC ERROR\n") ;
        clnt_perrno(stat) ;
        fprintf(stderr, "\n") ;
        exit(1);
    }

    unsigned int r = r_;
    printf("r =  %u\n",r);
    return r;
}
