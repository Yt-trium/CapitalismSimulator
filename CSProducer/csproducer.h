#ifndef CSPRODUCER_H
#define CSPRODUCER_H

#include <stdio.h>
#include "../CSCommon/define.h"

// Actual stock
static unsigned int stocks = 1000;

unsigned int max(unsigned int a, unsigned int b);
unsigned int min(unsigned int a, unsigned int b);

// RPC functions
unsigned int *getStocks();
unsigned int *get(unsigned int *q);

// Alarm
void produce(int a);

#endif // CSPRODUCER_H
