#include <iostream>
#include "bitConfig.h"
#include "xmlConfig.h"
#include "txUtils.h"

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

    printf("\nheader: ");

    print_char_arr(tD_new.headerBin, tD_new.header_size);

    printf("\n");



    //print_char_as_bin(tD_new.txBuff, tD_new.headerByteChunks);

    //printf("\n");

    std::string str = "this is a test function for transmitter and receiver";


    inp_struct inp = toBinary(str, str.length(), false);

    print_char_arr((char *)inp.binary, inp.length);

    char *packet_msg1 = split_char((char *)inp.binary,0,tD_new.msg_size,inp.length);

    printf("\Msg: ");

    print_char_arr(packet_msg1, tD_new.msg_size);

    printf("\n");


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
