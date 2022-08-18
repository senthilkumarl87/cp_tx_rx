#include "txUtils.h"



void fill_header(txData tD, const char *path)
{
    const int n = tD.numFields-1;

    fields *fD[n]; //= new fields;
    for(uint32_t i =0; i<n; i++)
        fD[i] = new fields;

    fields *f1 = new fields[n];
    //f1[0].fieldLn =16;
    //fields fd= new fields;
    //fields tmp[n];
    get_packet_header_field_info(path, f1);

    //std::cout<<"---"<<f1[0].field<<std::endl;

    printf("\nNum Fields: %d\n", n);

    uint32_t header_size=0;

    for(uint32_t k=0; k<n; k++)
    {
        std::cout<<k<<"---"<<f1[k].field<<std::endl;
        header_size = header_size + f1[k].fieldLn;
    }

    printf("\nThe header size=%d\n", header_size);

    char *headerData = new char[header_size];

    //std::cout << "=>"<<strcat((char *)f1[0].field,(char *)f1[1].field) << std::endl;

    char * tmp1;
    char * tmp2;
    tmp1 = (char *)f1[0].field;

    for(uint32_t kk=0; kk<n-1; kk++)
    {

        tmp2 = (char *)f1[kk+1].field;
        //std::cout << "=>"<<tmp1<<","<< tmp2 << std::endl;
        tmp1 = strcat(tmp1, tmp2);
    }

    std::cout <<"===>>"<< tmp1<< std::endl;



    //std::cout<<carr<<std::endl;



    std::cout <<"===>>"<< tD.byteChunks<< std::endl;

    print_char8bit_hex_arr(tD.txBuff, tD.byteChunks);


    print_char_as_bin(tD.txBuff, tD.byteChunks);



    char carr[8];
    int inx;
    printf("The header size:%d bytes \n", header_size/8);

    int byte_cnt = header_size/8;

    //for(int kk = 0; kk < byte_cnt; kk++)

    //int st = 3;

    for(int st = 0; st < byte_cnt; st++)

    {


    for(int i = 0; i< 8; i++)
    {
        inx = st*8+i;
        //std::cout<<"|"<< tmp1[inx];
        carr[i]= tmp1[inx];


    }
    //std::cout<<""<<std::endl;


    //printf("\nLets see 1:\n");
    //print_char_arr(carr, 8);

    tD.txBuff[st] = insert_byte(tD.txBuff[st], carr);


    }

    int remainder = header_size -  byte_cnt*8;

    if(remainder >0 )
    {

        print_char_as_bin(tD.txBuff, byte_cnt + 1);

    }
    else{
        print_char_as_bin(tD.txBuff, byte_cnt);
    }






    //std::cout<<"******"<<cbytarr;

    //
    //print_char8bit_hex_arr(cbytarr, 8);

    //insert_byte(ch, char *chi)






}

txData get_txData(const char *path)
{
    txData tD;
    tinyxml2::XMLDocument doc;
    uint32_t n = get_packet_header_field_ln(path);
    uint32_t payloadSize = (uint32_t)get_packet_payload_size(path);

    int *fp;
    fp = get_packet_header(path);
    //printf("\nMain0. Num Fields: %d\n", n);

    fp = append_arr(fp, n, (int)payloadSize);n=n+1;

    tD.fieldSz = fp;

    tD.numFields = n;


    //print_int_arr(fp, n);

    uint32_t tot = sum_int(fp,n);
    const int chunks = tot / 8;
    const int remainder = tot - chunks*8 ;

    //std::cout<< "The total size: "<<tot<< " Byte chunks: "<< chunks << " remainder:" << remainder << std::endl;

    int all_chunks;
    if(remainder != 0)
        all_chunks = chunks + 1;
    else
        all_chunks = chunks;
    const int num_chunk = all_chunks;

    char *tx_buff = zeros_char8bit_arr(num_chunk);

    //std::cout<< "Tx buffer initialize"<< std::endl;

    //print_char8bit_hex_arr(tx_buff, all_chunks);

    //std::cout<< "The total size: "<< (int)tot<< " Byte chunks: "<< (int)chunks << " remainder:" << (int)remainder << std::endl;

    //printf("The tot size %d, Byte chunks %d reaminder %d.", tot, chunks, remainder);


    tD.byteChunks = num_chunk;
    tD.numAppend = remainder;
    tD.txBuff = tx_buff;

    return tD;

}

