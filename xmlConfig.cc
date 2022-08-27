

#include "xmlConfig.h"



void read_packet_xml(const char * path)
{
    tinyxml2::XMLDocument doc;
    //const char * path = "test.xml";
    doc.LoadFile(path);

}

/*
void print_int_arr(int* arr, int n)
{

    for(int k= 0; k<n; k++)
    {
        std::cout<<arr[k];
        if (k!=n-1)
            std::cout<<",";

    }
    std::cout<<""<<std::endl;
}*/

int get_packet_header_field_ln(const char * path)
{
    tinyxml2::XMLDocument doc;
    //const char * path = "test.xml";
    doc.LoadFile(path);

    tinyxml2::XMLElement* packet = doc.FirstChildElement( "packet" );
    tinyxml2::XMLElement* header = packet->FirstChildElement( "header" );
    //tinyxml2::XMLElement* message = packet->FirstChildElement( "message" );
    //tinyxml2::XMLElement* field11 = header->FirstChildElement( "Field" );
    //tinyxml2::XMLElement* field21 = message->FirstChildElement( "Field" );
    //printf( "header length = %s\n", header->Attribute("numfields"));
    uint32_t n = atoi(header->Attribute("numfields"));

    return n;
}


void get_packet_header_field_info(const char * path, struct fields *fd)
{

    tinyxml2::XMLDocument doc;
    //const char * path = "test.xml";
    doc.LoadFile(path);

    tinyxml2::XMLElement* packet = doc.FirstChildElement( "packet" );
    tinyxml2::XMLElement* header = packet->FirstChildElement( "header" );

    uint32_t n = atoi(header->Attribute("numfields"));

    int *fp = new int(n);


    //fd[0].field ="1101001010111100";
    //fd[0].fieldLn = 16;

    uint32_t i = 0;
    for(tinyxml2::XMLElement* field = header->FirstChildElement( "Field" ); field != NULL; field = field->NextSiblingElement( "Field" ))
    {
        //printf("-----------Field-%d-------------\n", i);
        //printf( "Name = %s\n", field->Attribute("name") );
        //printf( "size = %s\n", field->Attribute("size") );\

        //printf( "Text = %s\n", field->GetText() );
        fp[i] = atoi(field->Attribute("size"));

        fd[i].field = field->GetText();
        fd[i].fieldLn = atoi(field->Attribute("size"));

        i++;
    }

    //return fd[0];

}



int *get_packet_header(const char * path)
{
    tinyxml2::XMLDocument doc;
    //const char * path = "test.xml";
    doc.LoadFile(path);

    tinyxml2::XMLElement* packet = doc.FirstChildElement( "packet" );
    tinyxml2::XMLElement* header = packet->FirstChildElement( "header" );
    //tinyxml2::XMLElement* message = packet->FirstChildElement( "message" );
    //tinyxml2::XMLElement* field11 = header->FirstChildElement( "Field" );
    //tinyxml2::XMLElement* field21 = message->FirstChildElement( "Field" );
    //printf( "header length = %s\n", header->Attribute("numfields"));
    uint32_t n = atoi(header->Attribute("numfields"));
    //std::cout<<"Num int: "<< n << std::endl;
    int *fp = new int(n);



    //std::cout << "---------------------Header--------------------"<<std::endl;
    uint32_t i = 0;
    for(tinyxml2::XMLElement* field = header->FirstChildElement( "Field" ); field != NULL; field = field->NextSiblingElement( "Field" ))
    {
        //printf("-----------Field-%d-------------\n", i);
        //printf( "Name = %s\n", field->Attribute("name") );
        //printf( "size = %s\n", field->Attribute("size") );
        //printf( "Text = %s\n", field->GetText() );
        fp[i] = atoi(field->Attribute("size"));
        i++;
    }

    //std::cout<<"Header field sizes"<<std::endl;

    //print_int_arr(fp, n);

    //std::cout<<"Total size of header: "<< sum_int(fp, n)<<std::endl;

    //bit_indexing(fp, n);

    return fp;


}

int get_packet_payload_size(const char * path)
{
    tinyxml2::XMLDocument doc;

    doc.LoadFile(path);

    tinyxml2::XMLElement* packet = doc.FirstChildElement( "packet" );

    tinyxml2::XMLElement* message = packet->FirstChildElement( "message" );

    //printf( "payload size = %s\n", message->Attribute("payLoadSize"));

    return atoi(message->Attribute("payLoadSize"));
}

void get_packet_message(const char * path)
{
    tinyxml2::XMLDocument doc;
    //const char * path = "test.xml";
    doc.LoadFile(path);

    tinyxml2::XMLElement* packet = doc.FirstChildElement( "packet" );
    //tinyxml2::XMLElement* header = packet->FirstChildElement( "header" );
    tinyxml2::XMLElement* message = packet->FirstChildElement( "message" );
    //tinyxml2::XMLElement* field11 = header->FirstChildElement( "Field" );
    //tinyxml2::XMLElement* field21 = message->FirstChildElement( "Field" );
    printf( "Message length = %s\n", message->Attribute("numfields"));
    std::cout << "---------------------Message--------------------"<<std::endl;
    uint32_t k = 0;
    for(tinyxml2::XMLElement* field = message->FirstChildElement( "Field" ); field != NULL; field = field->NextSiblingElement( "Field" ))
    {
        printf("-----------Field-%d-------------\n", k);
        printf( "Name = %s\n", field->Attribute("name") );
        printf( "size = %s\n", field->Attribute("size") );
        printf( "Text = %s\n", field->GetText() );

        k++;
    }

}

std::string cpyChar2String(std::string s, char * c, int n)
{
    for(int i=0; i<n;i++)
    {
        s[i]=c[i];
    }
}

cluster_struct *getNodeGraph()
{
    const char * path = "nodes.xml";

    cluster_struct *clstr;

    tinyxml2::XMLDocument doc;

    doc.LoadFile(path);

    tinyxml2::XMLElement* nodes = doc.FirstChildElement( "nodes" );

    tinyxml2::XMLElement* node1 = nodes->FirstChildElement( "node" );

    printf("\nNode datails:\n");
    //std::cout<<node1->Attribute("name");

    printf("numNodes: %d\n", atoi(nodes->Attribute("numNodes")));




    uint32_t k = 0;
    for(tinyxml2::XMLElement* node = nodes->FirstChildElement( "node" ); node != NULL; node = node->NextSiblingElement( "node" ))
    {
        printf("-----------Node-%d-------------\n", k);




        printf( "Name = %d and Nbr count= %d\n", atoi(node->Attribute("name")) , atoi(node->Attribute("numNbrs")) );

        int j = 0;
        for(tinyxml2::XMLElement* Nbr = node->FirstChildElement( "Nbr" ); Nbr != NULL; Nbr = Nbr->NextSiblingElement( "Nbr" ))
            {


                printf( "\tNbr Name = %s\n", Nbr->Attribute("name"));






                j++;

            }

            //print_uint16bit_arr(clstr->node[k].nbrs, clstr->node[k].numNbrs);



        k++;
    }

    return clstr;



}






