//!@file

#include "Akinator_Head.h"

int main()
{
    printf ("hey\n");

    Node node1;
    node1.data = "heeey";

    Tree akin_tree;
    akin_tree.Insert_Node (&node1);
    akin_tree.Insert_Node (&node1, &node1, 1);

    printf ("str = %s\n, size = %d\n", node1.data, akin_tree.elem_num);

    return 0;
}
