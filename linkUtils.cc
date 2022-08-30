#include "linkUtils.h"


struct min_index_int get_min_of_arr(int *arr, int n)
{
    //Intialize the value of min and index
    int minVal = INT_MAX;
    int index = -1;
    // Iterate the array
    for(int i=0; i < n; i++)
    {
        if(arr[i] < minVal)
        {
            //If current value is less than min value
            // then replace it with min value
            minVal = arr[i];
            index = i;
        }
    }

    min_index_int objFn;
    objFn.minVal = minVal;
    objFn.index = index;

    return objFn;
}


struct max_index_int get_max_of_arr(int *arr, int n)
{
    //Intialize the value of max and index
    int maxVal = INT_MIN;
    int index = -1;
    // Iterate the array
    for(int i=0;i<n;i++)
    {
        if(arr[i]>maxVal)
        {
            // If current value is greater than max
            // value then replace it with max value
            maxVal = arr[i];
            index = i;
        }
    }

    max_index_int objFn;
    objFn.maxVal = maxVal;
    objFn.index = index;



    return objFn;
}



void cpyIntArr(int *t1, int *t2, int n)
{

    for(int i=0; i<n; i++)
    {
        t1[i] = t2[i];
    }
}

void print_bool_arr(bool *arr, int n)
{
    printf("\n");
    for(int i=0; i<n; i++)
    {
        std::cout<<arr[i];
        if (i!=n-1)
            printf(",");
    }
    printf("\n");
}

struct channel setChannelInfo(struct channel ch)
{
    //struct channel ch;

    //(char*)malloc((mm+1) * sizeof(char));



    int numCh = 5;

    ch.chId = (int *)malloc((numCh +1)*sizeof(int));
    ch.RSSI = (int *)malloc((numCh +1)*sizeof(int));
    ch.sensitivity = -110;//(int *)malloc((numCh +1)*sizeof(int));
    ch.chAvail = (bool *)malloc((numCh +1)*sizeof(bool));

    int chId[] = {98,99,100,101,102};


    int RSSI[] = {-90,-150,-100,-50,-80};


    ch.numCh = numCh;
    cpyIntArr(ch.chId, chId, numCh);

    cpyIntArr(ch.RSSI, RSSI, numCh);

    for(int i=0; i< numCh; i++)
    {
        if(ch.RSSI[i]>ch.sensitivity)
        {
            ch.chAvail[i] = true;
        }
        else
        {
            ch.chAvail[i] = false;
        }
    }

    //ch.chId = {0,1,2,3,4};

    return ch;


}


int sum_bool_arr(bool *arr, int n)
{
    int tot = 0;
    for(int i = 0; i<n; i++)
    {
        tot = tot + (int) arr[i];
    }

    return tot;
}


struct int_struct getAvailChIds(channel ch)
{
    int totAvailCh = sum_bool_arr(ch.chAvail, ch.numCh);

    printf("\nTotal available channel:%d\n", totAvailCh);





    struct int_struct av;

    int * availIds = new int(totAvailCh);

    av.intVal = new int(totAvailCh);
    av.length = totAvailCh;

    int k = 0;
    for(int i =0; i<ch.numCh; i++)
    {
        //printf("\n---|%d|%d|%d|%d|\n", i, k, );
        if(ch.chAvail[i])
        {
            availIds[k] = ch.chId[i];
            k++;
        }

    }

    cpyIntArr(av.intVal, availIds, totAvailCh);

    //print_int_arr(av.intVal, av.length);

    return av;

}

int get_index_int_arr(int val, int *arr, int n)
{
    int inx = -1;
    for(int i = 0; i<n; i++)
    {
        if(arr[i] == val)
        {
            inx = i;
            break;
        }
    }

    return inx;
}

int *value_inx(int *arr, int * inx, int n)
{
    int *out = new int(n);

    for(int i =0; i<n; i++)
    {
        out[i] = arr[inx[i]];
    }

    return out;
}

int_struct getRSSIofChId(int *chIds, int ln, channel ch)
{

    int *availInx = new int(ln);

    int *availRssi = new int(ln);

    for(int i = 0; i<ln;i++)
    {
        availInx[i] = get_index_int_arr(chIds[i], ch.chId, ch.numCh);

    }

    //printf("\nAvailable inxs\n");


    //print_int_arr(availInx, ln);

    availRssi = value_inx(ch.RSSI, availInx, ln);

    //printf("\nAvailable RSSIs\n");

    //print_int_arr(availRssi, ln);

    int_struct availRssi_st;
    availRssi_st.intVal = new int(ln);
    cpyIntArr(availRssi_st.intVal, availRssi, ln);
    availRssi_st.length = ln;

    return availRssi_st;

}


struct optCh getOPtimalLinkId(channel ch)
{
    int_struct chIds =  getAvailChIds(ch);


    //get_index_int_arr(objFn.minVal, ch.RSSI, ch.numCh);

    int_struct avaiRssi = getRSSIofChId(chIds.intVal, chIds.length, ch);

    //print_int_arr(avaiRssi.intVal, avaiRssi.length);

    max_index_int objFn = get_max_of_arr(avaiRssi.intVal, avaiRssi.length);

    //printf("\n--%d- %d\n", objFn.index, objFn.maxVal);

    int optId = chIds.intVal[objFn.index];

    //printf("\nThe optimal val = %d and ch id = %d\n", objFn.maxVal, optId);

    struct optCh od;
    od.chid = optId;
    od.rssi = objFn.maxVal;


    //print_int_arr(chIds.intVal, chIds.length);

    //printf("\nThe %d\n", );

    return od;
}

void charArrCpyMem(char *a1, char *a2, int n)
{
    a1 = (char*)malloc((n+1) * sizeof(char));

    for(int i =0; i< n;i++)
    {
        a1[i] = a2[i];
    }
}

void uint16ArrCpyMem(uint16_t *a1, uint16_t *a2, int n)
{
    a1 = (uint16_t*)malloc((n+1) * sizeof(uint16_t));

    for(int i =0; i< n;i++)
    {
        a1[i] = a2[i];
    }
}

void nodeSim()
{
   /* char arr[][] = {
                        {0x02, 0x03, 0x04},
                        {0x01, 0x03, 0x05},
                        {0x01, 0x02, 0x09, 0x06},
                        {0x01, 0x03, 0x07},
                        {0x02, 0x06, 0x08},
                        {0x03, 0x05, 0x07, 0x08},
                        {0x04, 0x06, 0x08}
                    }; */

    node_struct nd;
    int numNodes = 7;
    neighbourTable nt[numNodes];

    int numNbrs;
    int length;
    int i;

    i =0;
    numNbrs = 3;
    int16_t_struct nb[numNodes];
    uint16_t nbrs1[numNbrs] = {0x02, 0x03, 0x04};
    uint16ArrCpyMem((uint16_t *)nb[i].intVal, nbrs1, numNbrs);nb[i].length = numNbrs;
    printf("\nprint struct\n");
    print_uint16bit_arr((uint16_t *)nb[i].intVal, nb[i].length);
    printf("\n--print struct--\n");


    int cost1[numNbrs] = {1, 1, 1};
    //length = 3;


    nt[i].length = numNbrs;
    printf("\nNode = %d, Nbr count:%d\n", i, nt[0].length);
    //nt[i].nodeId = (uint16_t*)malloc((numNbrs+1) * sizeof(uint16_t));
    nt[i].cost = (int*)malloc((numNbrs+1) * sizeof(int));
    uint16ArrCpyMem(nt[i].nodeId, nbrs1, nt[i].length);
    cpyIntArr(nt[i].cost, cost1, nt[i].length);
    print_uint16bit_arr(nt[i].nodeId, numNbrs );




    /*

    i =1;
    numNbrs = 3;
    char nbrs2[numNbrs] = {0x01, 0x03, 0x05};

    int cost2[numNbrs] = {1, 1, 1};
    //length = numNbrs;


    nt[i].length = numNbrs;
    printf("\nNode = %d, Nbr count:%d\n", i, nt[0].length);
    nt[i].nodeId = (char*)malloc((numNbrs+1) * sizeof(char));
    nt[i].cost = (int*)malloc((numNbrs+1) * sizeof(int));
    charArrCpy(nt[i].nodeId, nbrs2, nt[i].length);
    cpyIntArr(nt[i].cost, cost2, nt[i].length);
    print_char8bit_hex_arr(nt[i].nodeId, numNbrs );*/








}

mine * getMineId()
{
    mine *myID = (mine *)malloc(sizeof(mine *));

    myID->myAdd = 0x01;
    myID->mycheadId = 0x03;
    myID->myclusterid = 0x01;

    return myID;

}


neighbourTable *updateNeighbourTable()
{

    const char * path = "nodes.xml";

    cluster_struct *clstr = getNodeGraph(path);

    /*printf("\nOut: %d\n", clstr->length);

    for(int k = 0; k< clstr->length; k++)
    {

        printf("\nNode:%d(%d Neighbours)\n", clstr->node[k].nodeId, clstr->node[k].numNbrs);

        for(int j = 0; j < clstr->node[k].numNbrs; j++)
        {
            printf("\t%d", clstr->node[k].nbrs[j]);
        }
    }*/

    mine *myId = getMineId();

    //printf("\nMy node ID: %d \n", myId->myAdd);

    neighbourTable *nbrTbl = (neighbourTable *)malloc(sizeof(neighbourTable *));

    for(int k = 0; k< clstr->length; k++)
    {
        if(clstr->node[k].nodeId == myId->myAdd)
        {
            int numNbrs1 = clstr->node[k].numNbrs;

            nbrTbl->nodeId = (uint16_t *)malloc((numNbrs1+1) * sizeof(uint16_t));
            nbrTbl->cost = (int *)malloc((numNbrs1+1) * sizeof(int));
            nbrTbl->length = numNbrs1;
            //printf("\nMy neighbour: \n");
            for(int j = 0; j < clstr->node[k].numNbrs; j++)
            {


                nbrTbl->nodeId[j] = clstr->node[k].nbrs[j];

                nbrTbl->cost[j] = 1;

                //printf("\t%d", nbrTbl->nodeId[j]);

            }

            break;
        }
    }


    return nbrTbl;






}



void updateRtTable()
{
    //mine * getMineId()

}
