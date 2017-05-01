#ifndef DEFINE_H
#define DEFINE_H

static const char host_csproducer[25][12] =
{"127.0.0.1","127.0.0.1","127.0.0.1","127.0.0.1","127.0.0.1",   // Producer R1
 "127.0.0.1","127.0.0.1","127.0.0.1","127.0.0.1","127.0.0.1",   // Producer R2
 "127.0.0.1","127.0.0.1","127.0.0.1","127.0.0.1","127.0.0.1",   // Producer R3
 "127.0.0.1","127.0.0.1","127.0.0.1","127.0.0.1","127.0.0.1",   // Producer R4
 "127.0.0.1","127.0.0.1","127.0.0.1","127.0.0.1","127.0.0.1",   // Producer R5
};

static const char host_csagent[30][12]=
{"127.0.0.1","127.0.0.1","127.0.0.1","127.0.0.1","127.0.0.1",   // Humans
 "127.0.0.1","127.0.0.1","127.0.0.1","127.0.0.1","127.0.0.1",
 "127.0.0.1","127.0.0.1","127.0.0.1","127.0.0.1","127.0.0.1",   // Individualistic
 "127.0.0.1","127.0.0.1","127.0.0.1","127.0.0.1","127.0.0.1",
 "127.0.0.1","127.0.0.1","127.0.0.1","127.0.0.1","127.0.0.1",   // Cooperative
 "127.0.0.1","127.0.0.1","127.0.0.1","127.0.0.1","127.0.0.1"
};

static const char host_coordinator[12]="127.0.0.1";

#define PROGNUM_CSCOORDINATOR   0x40021995
#define PROGNUM_CSAGENT         0x41021995
#define PROGNUM_CSPRODUCER      0x42021995
#define VERSNUM 1

#define CSPRODUCER_TIMER 2
#define CSAGENT_TIMER 2

// RPC PROC
#define PROC_EXIT               22
#define PROC_CHECK              40
#define PROC_READY              42
#define PROC_GOPLAY             44
#define CSPRODUCER_GETSTOCKS    101
#define CSPRODUCER_GET          102
#define CSAGENT_GETSTOCKS       201
#define CSAGENT_GET             202
#define CSCOORDINATOR_GETCONFIG 301
#define CSCOORDINATOR_ENDGAME   302

#endif // DEFINE_H
