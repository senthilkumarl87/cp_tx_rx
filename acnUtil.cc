#include "acnUtil.h"

void checkAcn(){

    tinyxml2::XMLDocument doc;
    const char * path = "packet.xml";
    doc.LoadFile(path);

    tinyxml2::XMLElement* packet = doc.FirstChildElement( "packet" );
    tinyxml2::XMLElement* header = packet->FirstChildElement( "header" );

    uint32_t n = atoi(header->Attribute("acnValue"));

    printf("\nThe action field value:%s\n", header->Attribute("acnValue"));

    mainAcnFn(n);

}


std::string checkHdrFields(int *ti)
{
    //printf("\nThe Action field value:%s\n", s2);

    ti[0] = -1;
    ti[1] = -1;

    tinyxml2::XMLDocument doc;
    const char * path = "packet.xml";
    doc.LoadFile(path);

    tinyxml2::XMLElement* packet = doc.FirstChildElement( "packet" );
    tinyxml2::XMLElement* header = packet->FirstChildElement( "header" );

    //uint32_t n = atoi(header->Attribute("acnValue"));

    std::string scnField = header->Attribute("acnField");

    //printf("\nThe action field: %s\n", scnField);

    //printf("\nThe action field value:%s\n", header->Attribute("acnValue"));
    //int *fp = new int(n);

     uint32_t i = 0;

    int inx = 0;
    //printf("\nFirst field pos:%d\n", inx);
    for(tinyxml2::XMLElement* field = header->FirstChildElement( "Field" ); field != NULL; field = field->NextSiblingElement( "Field" ))
    {
        //printf("-----------Field-%d-------------\n", i);
        //printf( "\nName = %s\n", field->Attribute("name") );
        std::string st = field->Attribute("name");

        //printf( "size = %s\n", field->Attribute("size") );\


        //fp[i] = atoi(field->Attribute("size"));
        int t = atoi(field->Attribute("size"));

        int cm = scnField.compare(st);



        if (cm == 0)
        {
            std::string tmp1 = field->GetText();
            printf( "\nText:\n");
            std::cout<<tmp1<<std::endl;

            ti[0] = inx;
            ti[1] = t;

            return tmp1;

            break;
            //printf("\nAction field pos:%d ln:%d\n", ti[0], ti[1]);


        }

        inx = inx + t;

        //fd[i].field = field->GetText();
        //fd[i].fieldLn = atoi(field->Attribute("size"));

        i++;
    }

    //printf("\nLast pos:%d\n", inx-1);







}


void mainAcnFn(int s)
{
    switch(s) {
      case 1:
        testFn();
        break;
      case 2:
        testFn();
        // code block
        break;
      default:
        printf("Default");
        // code block
    }
}


void testFn()
{
    printf("This is a test function");
}
