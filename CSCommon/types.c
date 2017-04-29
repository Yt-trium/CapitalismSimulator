#include "types.h"

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
    printf("- printf_GameConfig -\n");

    printf("R1InitialQuantity  : %u\n",a.R1InitialQuantity);
    printf("R1NumberOfProducer : %u\n",a.R1NumberOfProducer);

    printf("Humans %u\n",a.humans);
    printf("Indivi %u\n",a.individualistic);
    printf("Cooper %u\n",a.cooperative);
}

unsigned int max(unsigned int a, unsigned int b)
{
    return (a>b ? a : b);
}
unsigned int min(unsigned int a, unsigned int b)
{
    return (a<b ? a : b);
}
