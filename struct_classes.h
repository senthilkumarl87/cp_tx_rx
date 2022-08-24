

#ifndef TXUTILS_H_INCLUDED
#define TXUTILS_H_INCLUDED




#endif // TXUTILS_H_INCLUDED
#pragma once
struct fields {
    const char *field;
    int fieldLn;
};

struct inp_struct {
    const char *binary;
    int length;

};

struct min_index_int {
    int minVal;
    int index;
};

struct max_index_int {
    int maxVal;
    int index;
};

struct string_struct {
    const char *stringChar;
    int length;

};

struct int_struct {
    int *intVal;
    int length;
};

struct txData{
    char *txBuff;
    const char *headerBin;
    char *msgBin;
    char *packetBin;
    int byteChunks;
    int headerByteChunks;
    int numAppend;
    int header_size;
    int msg_size;
    int *fieldSz;
    uint32_t numFields;
};

struct txStream{
    char *msgBin;
    char *headerBin;
    char *txBuff;
    int numberOfPkt;
    std::string tx8bitBuffer;
    int txBuffLn;
    int msg_length;
    int header_length;
};


struct channel{
        int *chId;
        int *RSSI;
        int sensitivity;
        int numCh;
        bool *chAvail;
};

struct optCh {
    int rssi;
    int chid;
};

struct mine {
    char myAdd;
    char myclusterid;
    char mycheadId;

};

struct cluster {
    int length;
    char myclusterid;
    char *members;

};

struct routeTable {
    int length;
    char *nodeId;
    char *nextNodeId;
    char *cost;

};

struct neighbourTable {
    int length;
    char *nodeId;
    char *cost;
};

struct rreqPkt {
    uint16_t seq;
    char srcNode;
    char DestnodeId;
    char pktTyp;
    uint16_t ttl;
};

struct rrepPkt {
    uint16_t seq;
    char srcNode;
    char DestnodeId;
    char pktTyp;
    uint16_t ttl;
};

struct dataPkt {
    uint16_t seq;
    char srcNode;
    char DestnodeId;
    char pktTyp;
    uint16_t ttl;
};




