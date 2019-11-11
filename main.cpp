//!@file

#include "Akinator_Head.h"

int main()
{

    Node node1;
    node1.data = "Are you from Europe?";

    Node node2;
    node2.data = "2";

    Node node3;
    node3.data = "3";

    Node node4;
    node4.data = "4";

    Node node5;
    node5.data = "5";

    Node node6;
    node6.data = "Your blood is a tomato sauce, your nerves are pasta?";

    Node node7;
    node7.data = "You are from Italy!";

    Node node8;
    node8.data = "8";

    Node node9;
    node9.data = "9";

    Node node10;
    node10.data = "10";

    Node node11;
    node11.data = "11";

    Node node12;
    node12.data = "12";

    Node node13;
    node13.data = "13";

    Node node14;
    node14.data = "14";

    Node node15;
    node15.data = "15";

    Tree akin_tree;
    akin_tree.Insert_Node (&node1);
    akin_tree.Insert_Node (&node1, &node2, 0);
    akin_tree.Insert_Node (&node1, &node6, 1);

    akin_tree.Insert_Node (&node2, &node3, 0);
    akin_tree.Insert_Node (&node2, &node4, 1);

    akin_tree.Insert_Node (&node3, &node5, 0);
    akin_tree.Insert_Node (&node3, &node8, 1);

    akin_tree.Insert_Node (&node6, &node9, 0);
    akin_tree.Insert_Node (&node6, &node7, 1);

    akin_tree.Insert_Node (&node4, &node10, 0);
    akin_tree.Insert_Node (&node4, &node11, 1);

    akin_tree.Insert_Node (&node9, &node12, 0);
    akin_tree.Insert_Node (&node9, &node13, 1);

    //akin_tree.Insert_Node (&node7, &node14, 0);
    //akin_tree.Insert_Node (&node7, &node15, 1);

    FILE* file_w = fopen ("Europe guide.txt", "w");
    akin_tree.File_Write(file_w);
    fclose (file_w);

    akin_tree.Dump();

    akin_tree.Akinator();

    return 0;
}
