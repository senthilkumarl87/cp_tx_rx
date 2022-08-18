//#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include "tinyxml2.h"

#include <iostream>
#include <bitset>
#include <stdint.h>

#include <string>

#include "bitConfig.h"

#include "struct_classes.h"



//fields get_default_header_values(const char * path)
void read_packet_xml(const char * path);

int get_packet_header_field_ln(const char * path);

void get_packet_header_field_info(const char * path, struct fields *fd);

int * get_packet_header(const char * path);

void get_packet_message(const char * path);

int get_packet_payload_size(const char * path);








