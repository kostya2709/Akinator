#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef char* elem_t;

const int data_size = 20;

struct Node
{
public:

    Node* left;
    Node* right;

    elem_t data;

    Node();

    ~Node();

};

struct Tree
{

public:

    int elem_num;

    Node* first_elem;

    Tree();

    /*! This function inserts a node into your tree!
    @param[in] node_new New node that you want to insert.
    @param[in] node1 The node which precedes the new one.
    @param[in] pos The position to insert. Expects 0 for left or 1 for right.
    \return 0 if the function behaves correctly.
    */
    Insert_Node (Node* node_new, Node* node1, int pos);


    /*! This function inserts a node into your tree! Attention! The function expects that the tree is empty!
    @param[in] node_new New node that you want to insert.
    \return 0 if the function behaves correctly.
    */
    Insert_Node (Node* node_new);

    ~Tree();
};
