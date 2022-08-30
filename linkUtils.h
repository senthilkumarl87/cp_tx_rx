#ifndef LINKUTILS_H_INCLUDED
#define LINKUTILS_H_INCLUDED



#endif // LINKUTILS_H_INCLUDED

#include "txUtils.h"

#include <iomanip>


void cpyIntArr(int *t1, int *t2, int n);

void print_bool_arr(bool *arr, int n);

struct channel setChannelInfo(struct channel ch);

struct int_struct getAvailChIds(channel ch);

struct optCh getOPtimalLinkId(channel ch);

neighbourTable * updateNeighbourTable();

void updateRtTable();

mine * getMineId();

void routingPath();














