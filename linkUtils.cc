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

int16_t_structV *getNxtNode(uint16_t srcNode, uint16_t DestnodeId)
{
    neighbourTable *nbrTbl = updateNeighbourTableById(srcNode);

    printf("\nThe neighbours for node id:%d\n", srcNode);

    print_uint16bit_arr(nbrTbl->nodeId, nbrTbl->length);

    bool isMyNbr = false;
    int16_t_structV *nxt_nodes = (int16_t_structV *)malloc(sizeof(int16_t_structV *));

    mine *myId = getMineId();
    if(myId->myAdd == DestnodeId)
    {
        nxt_nodes->intVal = (uint16_t *)malloc(sizeof(uint16_t));
        nxt_nodes->intVal[0] = myId->myAdd;
        nxt_nodes->length = 1;

        return nxt_nodes;
    }


    for(int i=0; i<nbrTbl->length; i++)
    {
        if(nbrTbl->nodeId[i]==DestnodeId)
        {
            isMyNbr = true;
            nxt_nodes->intVal = (uint16_t *)malloc(sizeof(uint16_t));
            nxt_nodes->intVal[0] = nbrTbl->nodeId[i];
            nxt_nodes->length = 1;
            return nxt_nodes;
            break;
        }
    }

    ///Check the routing table, if rt is not present, the broadcast it to all the neighbours








    return nxt_nodes;

}

void printRtRow(rtRow * rw)
{
    printf("\n|%d|%d|%d|\n", rw->nodeId, rw->nextNodeId, rw->cost);
}

void nodeSim(uint16_t src, uint16_t dest)
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

        ///Generate the rreq packet
        rreqPkt *rq = (rreqPkt *)malloc(sizeof(rreqPkt *));

        rq->DestnodeId = 0x02;
        rq->srcNode = 0x01;

        rq->seq = 0x01;

        int16_t_structV * nxt_node =  getNxtNode(rq->srcNode, rq->DestnodeId);

        printf("\nNext node for src = %d, dest=%d\n", rq->srcNode, rq->DestnodeId);

        print_uint16bit_arr(nxt_node->intVal, nxt_node->length);

        //routeTable *rt = updateRtTable();

        int numNodes = 8;

        uint16_t ndIds[numNodes] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};

        routeTable *rt = initRtTable(numNodes,ndIds);

        printf("\nThe routing table:\n");

        for(int i = 0;i<rt->length; i++){


            printf("\n|%d|%d|%d|\n", rt->nodeId[i], rt->nextNodeId[i], rt->cost[i]);

        }

        rtRow *rw = (rtRow *)malloc(sizeof(rtRow));
        rw->cost = 3;
        rw->nextNodeId = 0x02;
        rw->nodeId = 0x03;

        uint16_t id = 0x03;

        insertInRoutingTable(rt, id, rw);

        printf("\nThe routing table(updated):\n");

        for(int i = 0;i<rt->length; i++){


            printf("\n|%d|%d|%d|\n", rt->nodeId[i], rt->nextNodeId[i], rt->cost[i]);

        }

        rw = getRoutingTableRow(rt, 0x03);

        printf("\n Row of The routing table:\n");

        printRtRow(rw);








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


neighbourTable *updateNeighbourTableById(uint16_t ndId)
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



    neighbourTable *nbrTbl = (neighbourTable *)malloc(sizeof(neighbourTable *));

    for(int k = 0; k< clstr->length; k++)
    {
        if(clstr->node[k].nodeId == ndId)
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



int calCost(int oh, int dr, double pktLoss)
{
    //oh = 1;


    //double pktSucessRt;
    double pktSucessRt = 1-pktLoss;


    double cost = oh*dr/pktSucessRt;

    return cost;
}


void cpyUInt16Arr2Arrp(uint16_t * t1, uint16_t t2[], int n)
{
    for(int i=0;i<n;i++)
    {
        t1[i] = t2[i];
    }
}



routeTable * updateRtTable()
{
    //mine * getMineId()


    routeTable * rt = (routeTable *)malloc(sizeof(routeTable));

    rt->length = 8;

    uint16_t ndId[rt->length] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};

    uint16_t nxtND[rt->length] = {0x01, 0x02, 0x03, 0x04, 0x02, 0x03, 0x04, 0x03};

    uint16_t cost[rt->length] = {0, 1, 1, 1, 2, 2, 2, 3};

    rt->nodeId = (uint16_t *)malloc((rt->length + 1)*sizeof(uint16_t));
    rt->nextNodeId = (uint16_t *)malloc((rt->length + 1)*sizeof(uint16_t));
    rt->cost = (uint16_t *)malloc((rt->length + 1)*sizeof(uint16_t));

    cpyUInt16Arr2Arrp(rt->nodeId,ndId, rt->length);
    cpyUInt16Arr2Arrp(rt->nextNodeId,nxtND, rt->length);
    cpyUInt16Arr2Arrp(rt->cost,cost, rt->length);



    return rt;


}

void insertInRoutingTable(routeTable *rt, uint16_t id, rtRow *rw)
{
    for(int i=0; i<rt->length; i++)
    {
        if(rt->nodeId[i] == id)
        {
            rt->nextNodeId[i] = rw->nextNodeId;
            rt->cost[i] = rw->cost;
        }
    }
}

rtRow * getRoutingTableRow(routeTable *rt, uint16_t id)
{
    rtRow *rw = (rtRow *)malloc(sizeof(rtRow));
    for(int i=0; i<rt->length; i++)
    {
        if(rt->nodeId[i] == id)
        {
            rw->nodeId = rt->nodeId[i];
            rw->nextNodeId = rt->nextNodeId[i];

            rw->cost =rt->cost[i];




        }
    }
    return rw;
}

routeTable * initRtTable(int numNodes, uint16_t ndIds[])
{
    //mine * getMineId()


    routeTable * rt = (routeTable *)malloc(sizeof(routeTable));

    rt->length = numNodes;

    uint16_t nxtND[rt->length];
    uint16_t cost[rt->length];

    for(int i = 0; i< numNodes; i++)
    {
        nxtND[i] = 0x00;
    }
    for(int i = 0; i< numNodes; i++)
    {
        cost[i] = 0;
    }

     //= {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};



    rt->nodeId = (uint16_t *)malloc((rt->length + 1)*sizeof(uint16_t));
    rt->nextNodeId = (uint16_t *)malloc((rt->length + 1)*sizeof(uint16_t));
    rt->cost = (uint16_t *)malloc((rt->length + 1)*sizeof(uint16_t));

    cpyUInt16Arr2Arrp(rt->nodeId,ndIds, rt->length);
    cpyUInt16Arr2Arrp(rt->nextNodeId,nxtND, rt->length);
    cpyUInt16Arr2Arrp(rt->cost,cost, rt->length);



    return rt;


}



