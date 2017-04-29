#ifndef CSAGENT_H
#define CSAGENT_H

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

unsigned int stocksR1;
unsigned int stocksR2;
unsigned int stocksR3;
unsigned int stocksR4;
unsigned int stocksR5;

// RPC functions
void *check();
void *exit_();
void *ready();
void *goPlay();

unsigned int get(unsigned int q, unsigned int id_);
unsigned int getStocks(unsigned int id_);

void printProducerStates();
void blingBling();

void checkEnd();

void humanAgent();
void indivAgent();
void coopAgent();

// Alarm
void loadConfig(int a);
void play(int a);

#endif // CSAGENT_H
