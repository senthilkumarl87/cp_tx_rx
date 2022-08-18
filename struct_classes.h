

#ifndef TXUTILS_H_INCLUDED
#define TXUTILS_H_INCLUDED




#endif // TXUTILS_H_INCLUDED
#pragma once
struct fields {
    const char *field;
    int fieldLn;
};

struct txData{
    char *txBuff;
    int byteChunks;
    int headerByteChunks;
    int numAppend;
    int *fieldSz;
    uint32_t numFields;
};
