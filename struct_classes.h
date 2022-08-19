

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

struct string_struct {
    const char *stringChar;
    int length;

};

struct txData{
    char *txBuff;
    int byteChunks;
    int headerByteChunks;
    int numAppend;
    int header_size;
    int *fieldSz;
    uint32_t numFields;
};
