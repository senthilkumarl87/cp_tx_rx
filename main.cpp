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

    appLayerPkt(str,  path, streamPkt1);

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

    updateNeighbourTable();










    //std::cout<<str2Binary(streamPkt1[0].tx8bitBuffer,true);


    printf("\n----fn-test----------\n");



    /*



    txData tD_new =  get_txData(path);



    print_int_arr((int *)tD_new.fieldSz, tD_new.numFields);

    printf("\nheader_size=%d\n", tD_new.header_size);

    printf("\nmsg_size=%d\n", tD_new.msg_size);






    std::cout<<"-------------------------------------------------"<<endl;


    tD_new = fill_header(tD_new, path);




    const inp_struct inp = toBinary(str, str.length(), false);


    int first;
    int last;
    int nn;
    const int mm = tD_new.header_size;;

    char *packet_msg2;
    int numPackets = inp.length/tD_new.msg_size;

    int remainderPkt = inp.length - tD_new.msg_size*numPackets;
    //printf("\nN=%d,Remainder %d\n", numPackets, remainderPkt);

    if(remainderPkt > 0)
    {
        numPackets++;
    }


    struct txStream streamPkt[numPackets];

    //printf("\nheader 3:");
    //print_char_arr((char *)tD_new.headerBin, tD_new.header_size);
    //printf("\n");

    ///Packet generation
    for(int i=1; i<=numPackets; i++){

    //int i= 2;
    first = (i-1)*tD_new.msg_size;
    if(i*tD_new.msg_size < inp.length){
        last = i*tD_new.msg_size;
    }
    else {
            printf("\nPacket ended\n");
        last = inp.length;
    }


    //printf("\nBoundry- %d- %d-%d\n", i, first, last);

    nn = last - first;

    packet_msg2 = (char*)malloc((nn+1) * sizeof(char));
    packet_msg2 = split_char((char *)inp.binary,first, last,inp.length);



    streamPkt[i-1].header_length = mm;
    streamPkt[i-1].headerBin = (char*)malloc((mm+1) * sizeof(char));
    charArrCpy(streamPkt[i-1].headerBin, (char *)tD_new.headerBin, mm);


    streamPkt[i-1].msg_length = nn;
    streamPkt[i-1].msgBin = (char*)malloc((nn+1) * sizeof(char));
    charArrCpy(streamPkt[i-1].msgBin, packet_msg2, nn);





    if(last == inp.length)
        break;

    }

    printf("\nTest packets\n");
    for(int inx=0; inx<numPackets; inx++)
    {
        printf("\RX Header part:\n");
        print_char_arr((char *)streamPkt[inx].headerBin, streamPkt[inx].header_length);
        printf("\n");

        printf("\nRX Message part:\n");
        print_char_arr((char *)streamPkt[inx].msgBin, streamPkt[inx].msg_length);
        printf("\n");
    }


    printf("\Input binary\n");
    print_char_arr((char *)inp.binary, inp.length);
    printf("\n");

    txBufferFill(streamPkt, numPackets);

    printf("\n........\n");

    std::cout<<str2Binary(streamPkt[0].tx8bitBuffer,true); */



    //rxCollectStream(streamPkt, numPackets);


    /*
    for (int i = 0; i < inp.length; i++)
        std::cout << inp.binary[i];
    printf("\n-----\n");

    fill_msg(inp, tD_new);*/




    //std::string binary = toBinary(str);
    //std::cout << binary << std::endl;




    printf("\n");
    cout << "test tx-rx chain" << endl;
    return 0;
}
