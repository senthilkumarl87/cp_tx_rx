#pragma once

#ifndef TXUTILS_H_INCLUDED
#define TXUTILS_H_INCLUDED



#endif // TXUTILS_H_INCLUDED

#include <iostream>
#include "bitConfig.h"
#include "xmlConfig.h"
#include "struct_classes.h"

/*
struct fields {
    char *field;
    int fieldLn;
};

struct txData{
    char *txBuff;
    int byteChunks;
    int numAppend;
    int *fieldSz;
    uint32_t numFields;
};*/


void fill_msg(inp_struct inp, txData tD);

txData get_txData(const char *path);

txData fill_header(txData tD, const char *path);

void txBufferFill(struct txStream txSArr[], int numPackets);
