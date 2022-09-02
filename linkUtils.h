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

neighbourTable *updateNeighbourTableById(uint16_t ndId);

routeTable * updateRtTable();

mine * getMineId();

void routingPath();

void nodeSim(uint16_t src, uint16_t dest);

routeTable * initRtTable(int numNodes, uint16_t ndIds[]);

void insertInRoutingTable(routeTable *rt, uint16_t id, rtRow *rw);

rtRow * getRoutingTableRow(routeTable *rt, uint16_t id);

void printRtRow(rtRow * rw);













