#ifndef CSPRODUCER_H
#define CSPRODUCER_H

#include <stdio.h>
#include <unistd.h>

#include <rpc/types.h>
#include <rpc/xdr.h>
#include <rpc/rpc.h>

#include "../CSCommon/define.h"
#include "../CSCommon/types.h"
#include "../CSCommon/log.h"

GameConfig gc;
unsigned int id;
Boolean proceed;

// Actual quantity of stock
unsigned int stocks;

// RPC functions
void *check();
void *exit_();
void *ready();
void *goPlay();

unsigned int *getStocks();
unsigned int *get(unsigned int *q);

// Alarm
void loadConfig(int a);
void produce(int a);

#endif // CSPRODUCER_H
