#include "csproducer.h"

unsigned int max(unsigned int a, unsigned int b)
{
    return (a>b ? a : b);
}
unsigned int min(unsigned int a, unsigned int b)
{
    return (a<b ? a : b);
}

unsigned int *getStocks()
{
    static unsigned int r;
    r = stocks;

    printf("[getStocks]stocks = %u\n",stocks);
    return &r;
}

unsigned int *get(unsigned int *q)
{
    static unsigned int r;
    r = min((*q),stocks);
    stocks -= r;

    printf("[get      ]stocks = %u\n",stocks);
    return &r;
}

void produce(int a)
{
   stocks += stocks/2 + 1;
   printf("[produce  ]stocks = %u\n",stocks);
   alarm(CSPRODCUER_TIMER);
}
