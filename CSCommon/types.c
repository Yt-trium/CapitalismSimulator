#include "types.h"
#include "log.h"

Boolean intToBool(int x)
{
    if(x == 0)
        return False;
    return True;
}

bool_t xdr_gc(XDR *xdrs, GameConfig *a)
{
    xdr_int(xdrs, &a->coordinatedActions);
    xdr_int(xdrs, &a->exhaustibleResource);
    xdr_int(xdrs, &a->allowObservation);
    xdr_int(xdrs, &a->Robbery);

    xdr_int(xdrs, &a->maxGet);
    xdr_int(xdrs, &a->endCondition);
    xdr_int(xdrs, &a->R1InitialQuantity);
    xdr_int(xdrs, &a->R1NumberOfProducer);
    xdr_int(xdrs, &a->R2InitialQuantity);
    xdr_int(xdrs, &a->R2NumberOfProducer);
    xdr_int(xdrs, &a->R3InitialQuantity);
    xdr_int(xdrs, &a->R3NumberOfProducer);
    xdr_int(xdrs, &a->R4InitialQuantity);
    xdr_int(xdrs, &a->R4NumberOfProducer);
    xdr_int(xdrs, &a->R5InitialQuantity);
    xdr_int(xdrs, &a->R5NumberOfProducer);

    xdr_int(xdrs, &a->humans);
    xdr_int(xdrs, &a->individualistic);
    xdr_int(xdrs, &a->cooperative);

    return TRUE;
}

void printf_GameConfig(GameConfig a)
{
    writeLog("- printf_GameConfig -\n");

    writeLog("coordinatedActions : %u\n",a.coordinatedActions);
    writeLog("exhaustibleResource : %u\n",a.exhaustibleResource);
    writeLog("allowObservation : %u\n",a.allowObservation);
    writeLog("Robbery : %u\n",a.Robbery);
    writeLog("endCondition : %u\n",a.endCondition);

    writeLog("R1InitialQuantity  : %u\n",a.R1InitialQuantity);
    writeLog("R1NumberOfProducer : %u\n",a.R1NumberOfProducer);
    writeLog("R2InitialQuantity  : %u\n",a.R2InitialQuantity);
    writeLog("R2NumberOfProducer : %u\n",a.R2NumberOfProducer);
    writeLog("R3InitialQuantity  : %u\n",a.R3InitialQuantity);
    writeLog("R3NumberOfProducer : %u\n",a.R3NumberOfProducer);
    writeLog("R4InitialQuantity  : %u\n",a.R4InitialQuantity);
    writeLog("R4NumberOfProducer : %u\n",a.R4NumberOfProducer);
    writeLog("R5InitialQuantity  : %u\n",a.R5InitialQuantity);
    writeLog("R5NumberOfProducer : %u\n",a.R5NumberOfProducer);

    writeLog("Humans %u\n",a.humans);
    writeLog("Indivi %u\n",a.individualistic);
    writeLog("Cooper %u\n",a.cooperative);
}

unsigned int max(unsigned int a, unsigned int b)
{
    return (a>b ? a : b);
}
unsigned int min(unsigned int a, unsigned int b)
{
    return (a<b ? a : b);
}
