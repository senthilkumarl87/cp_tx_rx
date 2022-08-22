#include <iostream>
#include "bitConfig.h"
#include "xmlConfig.h"
#include "txUtils.h"
#include "rxUtils.h"

using namespace std;

int main()
{

    const char * path = "packet.xml";


    /*
    const uint8_t data[] =
        { 0x54, 0x65, 0x6d, 0x70, 0x6f, 0x72, 0x61, 0x72, 0x79,
          0x20, 0x73, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x20, 0x74,
          0x6f, 0x20, 0x62, 0x65, 0x20, 0x77, 0x72, 0x69, 0x74,
          0x74, 0x65, 0x6e, 0x20, 0x74, 0x6f, 0x20, 0x66, 0x69,
          0x6c, 0x65 };
     *
     */

    txData tD_new =  get_txData(path);



    print_int_arr((int *)tD_new.fieldSz, tD_new.numFields);

    printf("\nheader_size=%d\n", tD_new.header_size);

    printf("\nmsg_size=%d\n", tD_new.msg_size);






    std::cout<<"-------------------------------------------------"<<endl;

    //std::cout<< "chunks:"<<tD_new.byteChunks<<endl;

    //print_char8bit_hex_arr(tD_new.txBuff, tD_new.byteChunks);

    //std::cout<<"-------------------------------------------------"<<endl;

    //printf("\nMain. Num Fields: %d\n", tD_new.numFields);

    tD_new = fill_header(tD_new, path);

    //printf("\nheader 1:");
    //print_char_arr((char *)tD_new.headerBin, tD_new.header_size);
    //printf("\n");



    //print_char_as_bin(tD_new.txBuff, tD_new.headerByteChunks);

    //printf("\n");

    std::string str = "This is a test function for transmitter and receiver";




    const inp_struct inp = toBinary(str, str.length(), false);





    //printf("\nheader 2:");
    //print_char_arr((char *)tD_new.headerBin, tD_new.header_size);
    //printf("\n");


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





    //printf("\nMsg%d: ", i);

    //print_char_arr(packet_msg2, nn);



    streamPkt[i-1].header_length = mm;
    streamPkt[i-1].headerBin = (char*)malloc((mm+1) * sizeof(char));
    charArrCpy(streamPkt[i-1].headerBin, (char *)tD_new.headerBin, mm);


    streamPkt[i-1].msg_length = nn;
    streamPkt[i-1].msgBin = (char*)malloc((nn+1) * sizeof(char));
    charArrCpy(streamPkt[i-1].msgBin, packet_msg2, nn);

    //printf("\nMsg::: ");

    /*
    printf("\nMsg::: ");
    print_char_arr(packet_msg2, nn);
    printf("\n");
    print_char_arr(streamPkt[i-1].msgBin, nn);
    printf("\n"); */

    //strcpy((char *)streamPkt[i-1].msgBin, packet_msg2);

    //strcpy()



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

    //rxDecodeStream(streamPkt[0]);

    rxCollectStream(streamPkt, numPackets);


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
