//!@file

#include "Akinator_Head.h"

int main()
{

    char* file_name = " то есть кто.txt";

    Tree read_list;
    read_list.File_Read (file_name);

    read_list.Dump();

    read_list.Akinator();

    return 0;
}
