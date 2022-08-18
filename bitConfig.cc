
#include "bitConfig.h"





std::string toBinary(std::string const &str) {
    std::string binary = "";
    for (char const &c: str) {
        binary += std::bitset<8>(c).to_string() + ' ';
    }
    return binary;
}


char insert_byte(char ch, char *chi)
{
    //printf("\n-----\n");
    //print_char_arr(chi,8);
    //printf("\n-----\n");
    char inp;
    for(unsigned int i= 0; i<8 ; i ++){

        inp = chi[i];
        //printf("\nLets see:%c: %d\n", inp, 8-i-1);

        ch = bit_insert_char(ch, 8-i-1, inp);

        //std::cout << std::bitset<8>(ch);
        //ch = bit_insert(ch, i, ();
        }
    return ch;
}

void print_char_as_bin(char *byte_var, int sz)
{
    for(uint32_t i = 0; i<sz; i++)
    {
         std::cout << std::bitset<8>(byte_var[i]);
         if(i!=sz-1)
            std::cout<<",";
    }
    std::cout<<""<<std::endl;


}


void print_char_arr(char* arr, int n)
{
   // print_int_arr(arr, n);

    for(int k= 0; k<n; k++)
    {
        printf("%c",arr[k]);
        //if (k!=n-1)
        //    printf(",");

    }
    printf("\n");
}




void print_int_arr(int* arr, int n)
{
   // print_int_arr(arr, n);

    for(int k= 0; k<n; k++)
    {
        printf("%d",arr[k]);
        if (k!=n-1)
            printf(",");

    }
    printf("\n");
}


void print_uint32_arr(uint32_t* arr, int n)
{
   // print_int_arr(arr, n);

    for(int k= 0; k<n; k++)
    {
        std::cout<<arr[k];
        if (k!=n-1)
            std::cout<<",";

    }
    std::cout<<""<<std::endl;
}

int *zeros_arr(int n)
{
    int *arr = new int(n);

    for(uint32_t i =0; i<n ; i++)
    {
        arr[i] = 0;
    }

    return arr;
}


void print_char8bit_hex_arr(char* carr, int n)
{
    for(int k= 0; k<n; k++)
    {
        //std::cout<< std::setw(2) << std::setfill('0') << std::hex << (int)carr[k];
        printf("%02hhX", carr[k] & 0xff);
        if (k!=n-1)
            std::cout<<",";

    }
    std::cout<<""<<std::endl;
}


char *zeros_char8bit_arr(int n)
{
    char *arr = new char(n);

    for(uint32_t i =0; i<n ; i++)
    {
        arr[i] = 0x00;

        //std::cout<< std::hex << (int)arr[i];
    }

    return arr;
}



int sum_int(int* arr, int n)
{
    //print_int_arr(arr, n);
    int tot = 0;
    for(int k =0; k<n; k++)
        tot = tot + arr[k];
    return tot;
}



static int* range(int first, int last)
{
    int n = last-first;
    static int *p = new int(n);
    int k = 0;
    for(int i = first; i< last; i++)
    {
        p[k] = i;
        k++;
    }

    /*
    for(int i = 0; i< n; i++)
    {
        std::cout << p[i] << ",";
    }
    std::cout<<""<<std::endl;*/

    return p;


}



void bit_indexing(int *siz, int arrSize)
{
    //int siz[] = {16, 2, 1, 32, 64};
    static int* p;


    //print_int_arr(siz, arrSize);

    //int arrSize = sizeof(siz)/sizeof(siz[0]);

    int tot_size = sum_int(siz, arrSize);
    //std::cout << "Array size: " << arrSize << std::endl;

    int first = 0;
    int last = siz[0];
    for(int i =0; i < arrSize; i++)
    {
        std::cout<<"------" <<siz[i] << std::endl;

        //std::cout<< "first, last:"<< first << ","<< first+siz[i]<<std::endl;

        p = range(first, first+siz[i]);



        print_int_arr(p, siz[i]);

        //std::cout<<" *p="<<p[0];

        std::cout<< ""<<std::endl;

        first = first+siz[i];

    }

}

char get_index_mask(int index)
{
    if(index<=0)
    {
        return 0b00000001;
    }
    else if (index == 1)
    {
        return 0b00000010;
    }
    else if (index == 2)
    {
        return 0b00000100;
    }
    else if (index == 3)
    {
        return 0b00001000;
    }
    else if (index == 4)
    {
        return 0b00010000;
    }
        else if (index == 4)
    {
        return 0b00010000;
    }
        else if (index == 5)
    {
        return 0b00100000;
    }
        else if (index == 6)
    {
        return 0b01000000;
    }
        else if (index == 7)
    {
        return 0b10000000;
    }
}



char reset_bit(char byte_var, char index_mask)
{
    char inv_bit_mask = ~index_mask;
    //cout << "inverted bit mask: "<< std::bitset<8>(inv_bit_mask) << endl;



    return inv_bit_mask & byte_var;
}



char bit_insert_char(char byte_var, unsigned int index, char bit)
{
    //cout << "byte variable: " << std::bitset<8>(byte_var) << endl;
    char index_mask = get_index_mask(index);

    //cout << "index mask: " << std::bitset<8>(index_mask) << endl;

    byte_var = reset_bit(byte_var, index_mask);
    //cout << "return: " << std::bitset<8>(byte_var)<< endl;
    if(bit == '1')
    {

        return byte_var | index_mask;
    }
    else
    {
        return byte_var;
    }

}


char bit_insert(char byte_var, unsigned int index, int bit)
{
    //cout << "byte variable: " << std::bitset<8>(byte_var) << endl;
    char index_mask = get_index_mask(index);

    //cout << "index mask: " << std::bitset<8>(index_mask) << endl;

    byte_var = reset_bit(byte_var, index_mask);
    //cout << "return: " << std::bitset<8>(byte_var)<< endl;
    if(bit)
    {

        return byte_var | index_mask;
    }
    else
    {
        return byte_var;
    }

}

bool get_bit(char byte_var, unsigned int index, int bit)
{
    //cout << "byte variable: " << std::bitset<8>(byte_var) << endl;

    char index_mask = get_index_mask(index);

    char bit_and_r = byte_var & index_mask;
    //cout << std::bitset<8>(byte_var) <<"," <<std::bitset<8>(index_mask) << endl;



    char shift = bit_and_r >> index;
    //cout << "bit and :"<< (int)shift<<endl;

    return (int)shift;
}


int *append_arr(int* aparr, int n, int num)
{
    int *arr = new int(n+1);

    for(uint32_t i = 0; i<=n ; i++)
    {
        if (i != n)
            arr[i] = aparr[i];
        else
            arr[i] = num;
    }

    delete(aparr);
    //print_int_arr(arr, n+1);
    return arr;
}



