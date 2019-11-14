//!@file

#include "Akinator_Head.h"

int main()
{

    setlocale(LC_ALL, "Russian");

    char* file_name = " то есть кто.txt";

    Tree read_list;
    read_list.File_Read (file_name);

    read_list.Dump();

    printf ("Ok path is %d\n", read_list.Find_Character ("a penguin"));

    read_list.Akinator();

    return 0;
}
