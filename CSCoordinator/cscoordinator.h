#ifndef CSCOORDINATOR_H
#define CSCOORDINATOR_H

#include <stdio.h>

#include <rpc/types.h>
#include <rpc/xdr.h>
#include <rpc/rpc.h>

#include "../CSCommon/define.h"
#include "../CSCommon/types.h"
#include "../CSCommon/log.h"

GameConfig gc;

Boolean checkGameConfig(GameConfig a);
Boolean callAll(unsigned int n, unsigned int z, unsigned int type, unsigned int proc);
GameConfig *getConfig();
void *endGame();

unsigned int *get(unsigned int *q);
void makeThemPlay(int a);

#endif // CSCOORDINATOR_H
