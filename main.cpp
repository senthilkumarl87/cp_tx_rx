#include <iostream>
#include "bitConfig.h"
#include "xmlConfig.h"
#include "txUtils.h"
#include "rxUtils.h"
#include "linkUtils.h"

using namespace std;

int main()
{

    const char * path = "packet.xml";

    std::string str = "This is a test function for transmitter and receiver";


    printf("\n----fn test----------\n");

    int numPackets1 = getNumPackets(str,  path);

    printf("\nPktLn:%d\n", numPackets1);

    struct txStream streamPkt1[numPackets1];

    ///appLayerPkt(str,  path, streamPkt1);

    struct channel ch;

    ch = setChannelInfo(ch);

    printf("\nCh ln: %d\n", ch.numCh);

    print_int_arr(ch.chId, ch.numCh);

    print_int_arr(ch.RSSI, ch.numCh);

    print_bool_arr(ch.chAvail, ch.numCh);


    struct int_struct av = getAvailChIds(ch);

    printf("\nAvailable channel ids:\n");

    print_int_arr(av.intVal, av.length);

    struct optCh od = getOPtimalLinkId(ch);

    printf("\nThe optimal val = %d and ch id = %d\n", od.rssi, od.chid);

    char destiNationId = 0x82;

    char clusterId = 0x32;

    printf("\n--%cn", destiNationId);

    printf("\n--%cn", clusterId);

    neighbourTable * nbrTbl = updateNeighbourTable();

    printf("\n\n");

    print_uint16bit_arr(nbrTbl->nodeId, nbrTbl->length);










    //std::cout<<str2Binary(streamPkt1[0].tx8bitBuffer,true);


    printf("\n----fn-test----------\n");








    printf("\n");
    cout << "test tx-rx chain" << endl;
    return 0;
}
