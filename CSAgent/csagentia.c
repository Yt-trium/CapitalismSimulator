#include "csagent.h"

void indivAgent()
{
    writeLog("[CSA%u]INDIVIDUALISTIC AGENT ROUND\n",id);

    unsigned int producer = 0;
    if(gc.R1NumberOfProducer > 0 && stocksR1 < gc.endCondition)
        producer += gc.R1NumberOfProducer;
    if(gc.R2NumberOfProducer > 0 && stocksR2 < gc.endCondition)
        producer += gc.R2NumberOfProducer;
    if(gc.R3NumberOfProducer > 0 && stocksR3 < gc.endCondition)
        producer += gc.R3NumberOfProducer;
    if(gc.R4NumberOfProducer > 0 && stocksR4 < gc.endCondition)
        producer += gc.R4NumberOfProducer;
    if(gc.R5NumberOfProducer > 0 && stocksR5 < gc.endCondition)
        producer += gc.R5NumberOfProducer;

    if(producer == 0)
        exit(42);

    unsigned int i, z = 0;

    for(i=0;i<gc.R1NumberOfProducer;i++)
    {
        if(stocksR1 < gc.endCondition)
            stocksR1 += get(gc.maxGet/producer,i+z*5);
    }z++;
    for(i=0;i<gc.R2NumberOfProducer;i++)
    {
        if(stocksR2 < gc.endCondition)
            stocksR2 += get(gc.maxGet/producer,i+z*5);
    }z++;
    for(i=0;i<gc.R3NumberOfProducer;i++)
    {
        if(stocksR3 < gc.endCondition)
            stocksR3 += get(gc.maxGet/producer,i+z*5);
    }z++;
    for(i=0;i<gc.R4NumberOfProducer;i++)
    {
        if(stocksR4 < gc.endCondition)
            stocksR4 += get(gc.maxGet/producer,i+z*5);
    }z++;
    for(i=0;i<gc.R5NumberOfProducer;i++)
    {
        if(stocksR5 < gc.endCondition)
            stocksR5 += get(gc.maxGet/producer,i+z*5);
    }
}

void coopAgent()
{
    writeLog("[CSA%u]COOPERATIVE AGENT ROUND\n",id);
}
