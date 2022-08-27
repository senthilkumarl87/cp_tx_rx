

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

struct int16_t_struct {
    const uint16_t *intVal;
    int length;

};

struct string_struct1 {
    char *stringChar;
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
    uint16_t myAdd;
    uint16_t myclusterid;
    uint16_t mycheadId;

};
/*
struct mine_b {
    char myAdd;
    char myclusterid;
    char mycheadId;

};*/

struct cluster {
    uint16_t length;
    uint16_t myclusterid;
    uint16_t *members;

};

/*
struct cluster_b {
    int length;
    char myclusterid;
    char *members;

};*/

struct routeTable {
    uint16_t length;
    uint16_t *nodeId;
    uint16_t *nextNodeId;
    uint16_t *cost;

};

/*
struct routeTable {
    int length;
    char *nodeId;
    char *nextNodeId;
    char *cost;

};*/


struct neighbourTable {
    int length;
    uint16_t *nodeId;
    int *cost;
};

struct rreqPkt {
    uint16_t seq;
    uint16_t srcNode;
    uint16_t DestnodeId;
    uint16_t nxtNd;
    char pktTyp;
    uint16_t ttl;
};

struct rrepPkt {
    uint16_t seq;
    uint16_t srcNode;
    uint16_t DestnodeId;
    uint16_t nxtNd;
    char pktTyp;
    uint16_t ttl;
};

struct dataPkt {
    uint16_t seq;
    uint16_t srcNode;
    uint16_t DestnodeId;
    char pktTyp;
    uint16_t ttl;
};

struct cts {
    uint16_t seq;
    uint16_t srcNode;
    uint16_t DestnodeId;
    char pktTyp;

};

struct rts {
    uint16_t seq;
    uint16_t srcNode;
    uint16_t DestnodeId;
    char pktTyp;

};

struct node_struct {
    uint16_t nodeId;
    uint16_t clusterId;
    uint16_t *nbrs;
    neighbourTable *neighbours;
    uint32_t numNbrs;
};

struct cluster_struct {
    node_struct *node;
    uint16_t clusterId;
    uint32_t length;
};







/*

struct neighbourTable {
    int length;
    char *nodeId;
    int *cost;
};

struct rreqPkt {
    uint16_t seq;
    char srcNode;
    char DestnodeId;
    char nxtNd;
    char pktTyp;
    uint16_t ttl;
};

struct rrepPkt {
    uint16_t seq;
    char srcNode;
    char DestnodeId;
    char nxtNd;
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

struct cts {
    uint16_t seq;
    char srcNode;
    char DestnodeId;
    char pktTyp;

};

struct rts {
    uint16_t seq;
    char srcNode;
    char DestnodeId;
    char pktTyp;

};

struct nodes {
    char nodeId;
    neighbourTable *neighbours;
    uint32_t length;
};





*/

