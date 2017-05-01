#include "csagent.h"

void humanAgent()
{
    writeLog("HUMAN AGENT ROUND\n");

    if(!gc.allowObservation)
        writeLog("observation not allowed (always show 0)\n");
    printProducerStates();
    printAgentStates();

    unsigned int a = 100, b = 100, c = 100;

    while(a > 3)
    {
        writeLog("\n"
                 "1. get(quantity,id) (get ressource from producer)\n"
                 "2. getAgent(id, resource) (get ressource from agent)\n"
                 "3. protect (protect from robbery)\n");

        scanf("%u",&a);
    }

    switch(a)
    {
        case 1:
            while(b > gc.maxGet || c > 25)
            {
                writeLog("\noptions : \n");
                scanf("%u %u",&b,&c);
            }
            get(b,c);
        break;
        case 2:
            while(b > 30 || c > 5 || c <= 0)
            {
                writeLog("\noptions : \n");
                scanf("%u %u",&b,&c);
            }
            getAgent(b,c);
        break;
        case 3:
            protecting = True;
        break;
    }
}

void indivAgent()
{
    writeLog("INDIVIDUALISTIC AGENT ROUND\n");

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
    writeLog("COOPERATIVE AGENT ROUND\n");

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
