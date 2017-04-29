#ifndef TYPES_H
#define TYPES_H

#include <rpc/xdr.h>

// Boolean
typedef enum {False = 0, True = 1}
Boolean;

// Type of ressource
typedef enum {RSRC1 = 1, RSRC2 = 2, RSRC3 = 3, RSRC4 = 4, RSRC5 = 5}
Resource;

// Type of agent
typedef enum {HUMANS = 0, INDIVIDUALISTIC = 1, COOPERATIVE = 2}
Agent;

// Game configuration structure
typedef struct
{
    Boolean coordinatedActions;         // are actions coordinated by the CSCoordinator ?
    Boolean exhaustibleResource;        // are resource exhaustable ?
    Boolean allowObservation;           // is observation allowed ?
    Boolean Robbery;                    // is robbery allowed ?
    unsigned int maxGet;                // how many ressource can a CSAgent get in one call ?
    unsigned int endCondition;          // When does the game end ?
                                        // 0 -> No more resource
                                        // else the CSAgent need to get the 'endCondition' amount of
                                        // each available resource in the game to win

    unsigned int R1InitialQuantity;     // How many ressource the producer have initialy ?
    unsigned int R1NumberOfProducer;    // How many producer of this ressource ?
    unsigned int R2InitialQuantity;
    unsigned int R2NumberOfProducer;
    unsigned int R3InitialQuantity;
    unsigned int R3NumberOfProducer;
    unsigned int R4InitialQuantity;
    unsigned int R4NumberOfProducer;
    unsigned int R5InitialQuantity;
    unsigned int R5NumberOfProducer;

    unsigned int humans;                // how many humans CSAgent ?
    unsigned int individualistic;       // how many individualsitic CSAgent ?
    unsigned int cooperative;           // how many cooperative CSAgent ?
} GameConfig;

Boolean intToBool(int x);

unsigned int max(unsigned int a, unsigned int b);
unsigned int min(unsigned int a, unsigned int b);

// Filtre xdr pour les GameConfig
bool_t xdr_gc(XDR *xdrs, GameConfig * a) ;

void printf_GameConfig(GameConfig a);

#endif // TYPES_H
