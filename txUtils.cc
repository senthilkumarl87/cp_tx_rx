#include "txUtils.h"
#include "rxUtils.h"


int getNumPackets(std::string str,  const char * path)
{
    txData tD_new =  get_txData(path);
    tD_new = fill_header(tD_new, path);
    const inp_struct inp = toBinary(str, str.length(), false);

    return inp.length/tD_new.msg_size;
}



void appLayerPkt(std::string str,  const char * path, struct txStream streamPkt[])
{
    txData tD_new =  get_txData(path);
    tD_new = fill_header(tD_new, path);
    const inp_struct inp = toBinary(str, str.length(), false);



    int first;
    int last;
    int nn;
    const int mm = tD_new.header_size;;

    char *packet_msg2;
    int numPackets = inp.length/tD_new.msg_size;

    int remainderPkt = inp.length - tD_new.msg_size*numPackets;

    if(remainderPkt > 0)
    {
        numPackets++;
    }

    //struct txStream streamPkt[numPackets];

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

    nn = last - first;

    packet_msg2 = (char*)malloc((nn+1) * sizeof(char));
    packet_msg2 = split_char((char *)inp.binary,first, last,inp.length);


    streamPkt[i-1].header_length = mm;
    streamPkt[i-1].headerBin = (char*)malloc((mm+1) * sizeof(char));
    charArrCpy(streamPkt[i-1].headerBin, (char *)tD_new.headerBin, mm);


    streamPkt[i-1].msg_length = nn;
    streamPkt[i-1].msgBin = (char*)malloc((nn+1) * sizeof(char));
    charArrCpy(streamPkt[i-1].msgBin, packet_msg2, nn);

    streamPkt[i-1].numberOfPkt = numPackets;

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


    txBufferFill(streamPkt, numPackets);

    //printf("\n........\n");

    //std::cout<<str2Binary(streamPkt[0].tx8bitBuffer,true);

    //return streamPkt;

}



std::string BinaryStringToText(std::string binaryString) {
    std::string text = "";
    std::stringstream sstream(binaryString);
    while (sstream.good())
    {
        std::bitset<8> bits;
        sstream >> bits;
        text += char(bits.to_ulong());
    }
    return text;
}

void txBufferFill(struct txStream txSArr[], int numPackets)
{
    //int i= 0;
    //printf("\n------------\n");
    std::string allstr = "";
    std::string tmp1;
    std::string tmp2;
    for(int i = 0; i< numPackets; i++) {
        ///Concadinate header and message fields
        //printf("\n.......\n");
        //std::cout<<txSArr[i].msgBin;
        tmp1 = char2string(txSArr[i].msgBin, txSArr[i].msg_length);
        tmp2 = char2string(txSArr[i].headerBin, txSArr[i].header_length);
        allstr = tmp2 + tmp1;
        //std::cout<<tmp1<<" "<<tmp2<<std::endl;

        ///String to char

        //printf("\n**Bin string***\n");
        //std::cout<<allstr;
        //printf("\n---\n");

        txSArr[i].tx8bitBuffer = BinaryStringToText(allstr);
        //std::string strBuff_norm = BinaryStringToText(allstr);
        //std::cout<<BinaryStringToText(allstr);

        //print_string_as_bin(strBuff_norm);


        //std::cout<<str2Binary(txSArr[i].tx8bitBuffer,true);

    }

    //std::cout<<str2Binary(txSArr[0].tx8bitBuffer,true);



}


void fill_msg(inp_struct inp, txData tD)
{

    printf("\nThe headder size in bits: %d, bytes: %d\n", tD.header_size, tD.headerByteChunks);

    int remaining = 8*tD.headerByteChunks - tD.header_size;

    printf("\n the ramining bit to be filled %d\n", remaining);

    print_char_as_bin(tD.txBuff, tD.headerByteChunks);

    printf("\n\n");

    int last = tD.headerByteChunks-1;
    //std::cout << std::bitset<8>(tD.txBuff[last]);

    printf("\n\n");
    int inx = 0;
    char tmp;


    /*
    for(int inx = remaining; inx >= 0;  inx--)
    {
        printf("\n-|%d|-\n", inx);

        tmp = bit_insert_char(tD.txBuff[last],(int)(inx-1),'1');
        std::cout << std::bitset<8>(tmp);
    }*/
    //inx = remaining -1;
    //tmp = bit_insert_char(tD.txBuff[last],(int)(inx-1),'1');
    //std::cout << std::bitset<8>(tmp);

    printf("\n\n");
    //print_char_arr((char *)inp.binary, inp.length);
    //printf("\n.....\n");
    int m1;
    int m2;

    m1 = 0;
    m2 = remaining;

    char *split_char_inp1 = split_char((char *)inp.binary, m1, m2, inp.length);
    //print_char_arr(split_char_inp1,m2-m1);

    //printf("\n..split_char_inp1...\n");


    m1 = remaining;
    m2 = inp.length;
    char *split_char_inp2 = split_char((char *)inp.binary, m1, m2, inp.length);
    //print_char_arr(split_char_inp2,m2-m1);

     //printf("\n..split_char_inp2...\n");

    int ll = 0;
    tmp = tD.txBuff[last];
    for(int inx = remaining; inx > 0;  inx--)
    {
        //printf("\n-|%d|%d|%c|-\n", inx,ll, split_char_inp1[ll]);

        if(split_char_inp1[ll] == '1'){

            tmp = bit_insert_char(tmp,(int)(inx-1),'1');
            //std::cout << std::bitset<8>(tmp);
            }
        if(split_char_inp1[ll] == '0'){

            tmp = bit_insert_char(tmp,(int)(inx-1),'0');
            //std::cout << std::bitset<8>(tmp);
            }

        ll++;
    }

    printf("\n------\n");

    tD.txBuff[last] = tmp;

    print_char_as_bin(tD.txBuff, tD.headerByteChunks);

    printf("\n------\n");

    int t = 0;
    inx = remaining;

    print_char_as_bin(tD.txBuff, tD.byteChunks);

    int msgStart;
    if(remaining>0){
        msgStart = tD.headerByteChunks+1;
    }
    else {
        msgStart = tD.headerByteChunks;
    }
    printf("\n---cc--\n");

    int kk=remaining;


    for(int i = msgStart; i<tD.byteChunks;i++){


        //std::cout << std::bitset<8>(tD.txBuff[i]);
        tmp = tD.txBuff[i];
        for(int cc = 7; cc>=0; cc--){
            if(inp.binary[kk] == ' ') {
                kk++;
                //printf("->%c\n", inp.binary[kk]);
                tmp = bit_insert_char(tmp,(int)(cc),inp.binary[kk]);
                kk++;

                }
            else {
                 //printf("\n->%c\n", inp.binary[kk]);
                 tmp = bit_insert_char(tmp,(int)(cc),inp.binary[kk]);
                kk++;
            }

            //std::cout << std::bitset<8>(tmp);
            tD.txBuff[i] = tmp;



        //printf("\n");
        }

         //printf("\n---***----\n");
    }

    printf("\n--inp---\n");

    //print_char_arr((char *)inp.binary, inp.length);

    print_split_char((char *)inp.binary, remaining,85, inp.length);

    printf("\n--buffer-%d--\n", kk);

    print_char_as_bin(tD.txBuff, tD.byteChunks);






}


txData fill_header(txData tD, const char *path)
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

    //printf("\nNum Fields: %d\n", n);

    uint32_t header_size=0;

    for(uint32_t k=0; k<n; k++)
    {
        //std::cout<<k<<"---"<<f1[k].field<<std::endl;
        header_size = header_size + f1[k].fieldLn;
    }

    tD.header_size = header_size;

    //printf("\nThe header size=%d\n", header_size);

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

    tD.headerBin = (char*)malloc((tD.header_size+1) * sizeof(char));

    charArrCpy((char *)tD.headerBin, tmp1, tD.header_size);

    //tD.headerBin = tmp1;

    //std::cout <<"===>>"<< tmp1<< std::endl;



    //std::cout<<carr<<std::endl;



    //std::cout <<"===>>"<< tD.byteChunks<< std::endl;

    //print_char8bit_hex_arr(tD.txBuff, tD.byteChunks);


    //print_char_as_bin(tD.txBuff, tD.byteChunks);



    char carr[8];
    int inx;
    //printf("The header size:%d bytes \n", header_size/8);

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




        //printf("\n");
        char ch;
        int kk = 0;
        int inx = 0;

        ch = tD.txBuff[byte_cnt];
        for(int i = 8*byte_cnt; i < header_size; i++)
        {
            //printf("\n");
            inx = 8-kk-1;
            //std::cout<<inx<<"-"<<tmp1[i];

            ch = bit_insert_char(ch , inx, tmp1[i]);
            ////printf("\n");
            //std::cout << std::bitset<8>(ch);
            kk++;
        }
        //std::cout << std::bitset<8>(ch);

        tD.txBuff[byte_cnt] = ch;
        //print_char_as_bin(tD.txBuff, byte_cnt + 1);

        tD.headerByteChunks = byte_cnt + 1;

    }
    else{
        //print_char_as_bin(tD.txBuff, byte_cnt);
        tD.headerByteChunks = byte_cnt;
    }






    //std::cout<<"******"<<cbytarr;

    //
    //print_char8bit_hex_arr(cbytarr, 8);

    //insert_byte(ch, char *chi)



    return tD;


}

txData get_txData(const char *path)
{
    txData tD;
    tinyxml2::XMLDocument doc;
    uint32_t n = get_packet_header_field_ln(path);
    uint32_t payloadSize = (uint32_t)get_packet_payload_size(path);

    //int *fp;
    tD.fieldSz = get_packet_header(path);
    //printf("\nMain0. Num Fields: %d\n", n);

    tD.fieldSz = append_arr(tD.fieldSz, n, (int)payloadSize);n=n+1;

    /*printf("\n");
    print_int_arr(tD.fieldSz,n);
    printf("\n");*/

    /*for(int i=0; i<n;i++)
    {
        tD.fieldSz[i] = fp[i];
    }*/

    //tD.fieldSz = fp;

    //delete(fp);

    tD.numFields = n;
    tD.msg_size = tD.fieldSz[tD.numFields-1];

    //print_int_arr(fp, n);

    uint32_t tot = sum_int(tD.fieldSz,n);
    const int chunks = tot / 8;
    const int remainder = tot - chunks*8 ;

    int nn= tD.numFields;
    int header_size = 0;

    for(int i = 0; i < nn-1; i++)
    {
        //printf("\n-%d--\n", tD.fieldSz[i]);
        header_size = header_size + tD.fieldSz[i];
    }

    tD.header_size = header_size;




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

