#ifndef CSAGENT_H
#define CSAGENT_H

#include <stdio.h>

#include <rpc/types.h>
#include <rpc/xdr.h>
#include <rpc/rpc.h>

#include "../CSCommon/define.h"

static char *host = "127.0.0.1";

unsigned int get(unsigned int q);
unsigned int getStocks();

#endif // CSAGENT_H
