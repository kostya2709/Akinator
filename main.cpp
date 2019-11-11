//!@file

#include "Akinator_Head.h"

int main()
{
    printf ("hey\n");

    Node node1;
    node1.data = "start";

    Node node2;
    node2.data = "2";

    Node node3;
    node3.data = "3";

    Node node4;
    node4.data = "4";

    Node node5;
    node5.data = "5";

    Node node6;
    node6.data = "6";

    Node node7;
    node7.data = "7";

    Tree akin_tree;
    akin_tree.Insert_Node (&node1);
    akin_tree.Insert_Node (&node1, &node2, 0);
    akin_tree.Insert_Node (&node1, &node6, 1);

    akin_tree.Insert_Node (&node2, &node3, 0);
    akin_tree.Insert_Node (&node2, &node4, 1);

    akin_tree.Insert_Node (&node3, &node5, 0);

    akin_tree.Insert_Node (&node6, &node7, 1);

    akin_tree.Tree_Dump();

    return 0;
}
