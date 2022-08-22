

#include "rxUtils.h"

char *str2char(std::string s, bool byteNorm)
{
    int mm = s.length();
    int nn;
    char *ch;
    if(byteNorm)
    {
        if(mm % 8 >0 )
        {
            nn = mm + (8 - (mm % 8));

        }
        else{
            nn = mm;
        }
        ch = (char*)malloc((nn+1) * sizeof(char));

        for(int i = 0; i< nn ; i++)
        {
            ch[i] = s[i];

            if(i>mm-1){
                ch[i] = 0;
            }


        }

    }
    else
    {
        char *ch = (char*)malloc((mm+1) * sizeof(char));

        for(int i = 0; i< mm ; i++)
        {
            ch[i] = s[i];

        }


    }

    return ch;
}

std::string char2string(char* a, int length)
{

    //int i;
    std::string s = "";
    for (int i = 0; i < length; i++) {
        s = s + a[i];
    }
    return s;


}


// Function to convert binary to decimal
int binaryToDecimal(std::string n)
{
    std::string num = n;

    // Stores the decimal value
    int dec_value = 0;

    // Initializing base value to 1
    int base = 1;

    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {

        // If the current bit is 1
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }

    // Return answer
    return dec_value;
}

// Function to convert binary to ASCII
std::string setStringtoASCII(std::string str)
{
    // To store size of s
    int N = int(str.size());

    // If given string is not a
    // valid string
    if (N % 8 != 0) {
        return "Not Possible!";
    }

    // To store final answer
    std::string res = "";

    // Loop to iterate through string
    for (int i = 0; i < N; i += 8) {
        int decimal_value
            = binaryToDecimal((str.substr(i, 8)));

        // Apprend the ASCII character
        // equivalent to current value
        res += char(decimal_value);
    }

    // Return Answer
    return res;
}



void rxCollectStream(struct txStream txSArr[], int numPackets)
{
    printf("\nrxCollectStream for %d packets\n", numPackets);


    std::string data="";

    for(int i=0; i< numPackets; i++)
    {
        //printf("\n");
        data = data + char2string(txSArr[i].msgBin, txSArr[i].msg_length);

        //print_char_arr(txSArr[i].msgBin, txSArr[i].msg_length);
        //printf("\n");
        //rxDecodeStream(txSArr[i]);

    }
    printf("\nOut data:\n");

    std::cout<<setStringtoASCII(data);




}



void rxDecodeStream(txStream txS)
{
    //printf("\n-----rx msg-----\n");
    //print_char_arr(txS.msgBin,txS.msg_length);

    int byteln = txS.msg_length/8;

    //printf("\nLn:%d\n", byteln);

    string_struct rexMsg_pkt;

    rexMsg_pkt.length = byteln;

    for(int k=0; k<(byteln);k++){
        int sp = 8;
        int m1 = k*sp;
        int m2=(k+1)*sp;
        char tmp;
        char * tmpByte = split_char(txS.msgBin, m1, m2, txS.msg_length);
        //print_char_arr(tmpByte,m2-m1);

        //printf("\n\n");

        std::string tmpByteStr = char2string(tmpByte, m2-m1);

        //int dec_val = binaryToDecimal(tmpByteStr);

        std::string alp = setStringtoASCII(tmpByteStr);

        std::cout<<alp;

    }
    //std::string * str2 = char2string();

    //std::cout<<tmpByteStr<<"|"<<dec_val<<"|"<<alp;

}

