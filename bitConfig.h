#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <iostream>
#include <bitset>
#include <stdint.h>


#include <iomanip>

char insert_byte(char ch, char *chi);

char bit_insert_char(char byte_var, unsigned int index, char bit);

void print_char_as_bin(char *byte_var, int sz);

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



