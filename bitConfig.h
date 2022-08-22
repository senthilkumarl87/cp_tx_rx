#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <iostream>
#include <bitset>
#include <stdint.h>
#include <string.h>
#include <sstream>
#include "struct_classes.h"

#include <iomanip>


void appendZeros(char *binCharVar,int ln, int padCnt);

void charArrCpy(char *a1, char *a2, int nn);

char *split_char(char* char_array, int m1, int m2, int nn);

void print_split_char(char* char_array, int m1, int m2, int nn);

inp_struct toBinary(const std::string& str,int N, bool sp);

std::string str2Binary(std::string str, bool sp);

char insert_byte(char ch, char *chi);

char bit_insert_char(char byte_var, unsigned int index, char bit);

void print_char_as_bin(char *byte_var, int sz);

void print_string_as_bin(std::string byte_var);

int sum_int(int* arr, int n);

void print_char_arr(char* arr, int n);

void print_int_arr(int* arr, int n);

void print_uint32_arr(uint32_t* arr, int n);

void print_char8bit_hex_arr(char* arr, int n);

int *zeros_arr(int n);

char *zeros_char8bit_arr(int n);

char get_index_mask(int index);

char reset_bit(char byte_var, char index_mask);

char bit_insert(char byte_var, unsigned int index, int bit);

bool get_bit(char byte_var, unsigned int index, int bit);

static int* range(int first, int last);

void bit_indexing(int *siz, int arrSize);

int *append_arr(int* aparr, int n, int num);



