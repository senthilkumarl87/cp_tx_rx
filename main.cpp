#include <iostream>
#include "bitConfig.h"
#include "xmlConfig.h"
#include "txUtils.h"
#include "rxUtils.h"
#include "linkUtils.h"
#include "acnUtil.h"

using namespace std;

int main()
{

    const char * path = "packet.xml";

    std::string str = "This is a test function for transmitter and receiver";

    printf("\n----Input binary---\n");

    std::cout<<str2Binary(str,true)<<std::endl;


    printf("\n----fn test----------\n");

    int numPackets1 = getNumPackets(str,  path);

    printf("\nPktLn:%d\n", numPackets1);

    struct txStream streamPkt1[numPackets1];

    appLayerPkt(str,  path, streamPkt1);



    int apt;
    int bytLn;

    std::string final_Out = "";

    int *ti = new int(2);



    for(int i = 0; i<numPackets1; i++)
    {
        printf("\nInside the packet %d:\n", i);
        //std::cout<<str2Binary(streamPkt1[i].tx8bitBuffer,true)<<std::endl;


        bytLn = streamPkt1[i].tx8bitBuffer.length();

        //apt =  bytLn*8 - (streamPkt1[i].header_length + streamPkt1[i].msg_length);

        //printf("\napt = %d, bytLn= %d\n", apt, bytLn);

        std::string s1 = str2Binary(streamPkt1[i].tx8bitBuffer,false);

        std::string s2 = s1.substr(0, streamPkt1[i].header_length);





        std::string mp1 = checkHdrFields(ti);

        //printf("\nAcn field--->:");

        std::cout<<mp1<<std::endl;


        printf("\nIn Main:Action field pos:%d ln:%d\n", ti[0], ti[1]);


        std::string acnField = s2.substr(ti[0], ti[1]);

        //std::string tmp = "10";

        std::cout<<"The action field: "<<acnField<<std::endl;

        int cm = acnField.compare(mp1);

        //printf("The action compare: %d\n", cm);

        if(cm==0){

            checkAcn();

        }





        printf("\nHeader:\n");

        std::cout<<s2<<std::endl;


        printf("\nMessage:\n");

        std::string s3 = s1.substr(streamPkt1[i].header_length, streamPkt1[i].msg_length);

        /*if(i == (numPackets1-1))
        {
            s3 = s1.substr(streamPkt1[i].header_length, streamPkt1[i].msg_length+1);
        }*/

        std::cout<<s3<<std::endl;

        final_Out = final_Out + s3;




    }

    /*std::string s1 = str2Binary(streamPkt1[0].tx8bitBuffer,false);

    std::string s2 = s1.substr(0, streamPkt1[0].header_length);

     printf("\nThe Action field value:%s\n", s1);*/



    printf("\nFinal received message:\n");

    std::cout<<final_Out<<std::endl;

    std::cout<<BinaryStringToText(final_Out)<<std::endl;

    //std::cout<<str2Binary(BinaryStringToText(final_Out),true)<<std::endl;






    checkAcn();





    /*
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

    //print_uint16bit_arr(nbrTbl->nodeId, nbrTbl->length);

    uint16_t src = 0x01;
    uint16_t dest = 0x08;

    nodeSim(src, dest); */













    //std::cout<<str2Binary(streamPkt1[0].tx8bitBuffer,true);


    printf("\n----fn-test----------\n");








    printf("\n");
    cout << "test tx-rx chain" << endl;
    return 0;
}
