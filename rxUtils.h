
#pragma once
#ifndef RXUTILS_H_INCLUDED
#define RXUTILS_H_INCLUDED



#endif // RXUTILS_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <iostream>
#include <bitset>
#include <stdint.h>
#include <string.h>
#include <bits/stdc++.h>
#include "bitConfig.h"
#include "struct_classes.h"

#include "bitConfig.h"
#include "xmlConfig.h"
#include "txUtils.h"

#include <iomanip>


///multi node rx

int binaryToDecimal(std::string n);
void rxDecodeStream(txStream txS);
void rxCollectStream(struct txStream txS[], int numPackets);
std::string setStringtoASCII(std::string str);
std::string char2string(char* a, int length);
char *str2char(std::string s, bool byteNorm);









