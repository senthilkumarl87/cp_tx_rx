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



    print_int_arr(tD_new.fieldSz, tD_new.numFields);


    std::cout<<"-------------------------------------------------"<<endl;

    std::cout<< "chunks:"<<tD_new.byteChunks<<endl;

    print_char8bit_hex_arr(tD_new.txBuff, tD_new.byteChunks);

    std::cout<<"-------------------------------------------------"<<endl;

    printf("\nMain. Num Fields: %d\n", tD_new.numFields);

    tD_new = fill_header(tD_new, path);



    print_char_as_bin(tD_new.txBuff, tD_new.headerByteChunks);

    //std::cout<< "::::"<<tD_new.headerByteChunks;


    //int pysz =  get_packet_payload_size(path);

    //printf("payload size:%d", pysz );

    /*
    //read_packet_xml(path);
    tinyxml2::XMLDocument doc;
    uint32_t n = get_packet_header_field_ln(path);
    uint32_t payloadSize = 80;

    //zeros_arr(int n);

    int *fp;
    fp = get_packet_header(path);

    fp = append_arr(fp, n, (int)payloadSize);n=++n;

    print_int_arr(fp, n);

    uint32_t tot = sum_int(fp,n);
    int chunks = tot / 8;
    int remainder = tot - chunks*8 ;

    std::cout<< "The total size: "<<tot<< " Byte chunks: "<< chunks << " remainder:" << remainder << std::endl;

    int all_chunks;
    if(remainder != 0)
        all_chunks = chunks + 1;
    else
        all_chunks = chunks;

    char *tx_buff = zeros_char8bit_arr(all_chunks);

    std::cout<< "Tx buffer initialize"<< std::endl;

    print_char8bit_hex_arr(tx_buff, all_chunks);



    //get_packet_message(path);
    //print_int_arr(fp,n);

    */
    cout << "test tx-rx chain" << endl;
    return 0;
}
