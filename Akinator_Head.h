#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef char* elem_t;

const int data_size = 20;

const int FILE_NAME_SIZE = 100;

const int ANSWER_SIZE = 30;

struct Node
{
public:

    Node* left;
    Node* right;

    elem_t data;

    Node();

    /*!Returns 1 if the node is the leaf of the tree, else returns 0*/
    int Is_Leaf (void);

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
    int Insert_Node (Node* node1, Node* node_new, int pos);


    /*! This function inserts a node into your tree! Attention! The function expects that the tree is empty!
    @param[in] node_new New node that you want to insert.
    \return 0 if the function behaves correctly.
    */
    int Insert_Node (Node* node_new);

    /*! This function displays all tree's nodes and edges in tree_dump.png.*/
    int Dump (void);

    /*! The Akinator game itself*/
    int Akinator (void);

    /*!This function writes the information about the tree into the file f*/
    int File_Write (FILE* f);

    /*!This function reads the information about the tree from the file f*/
    Tree* File_Read (FILE* f);

    ~Tree();

private:
    /*! An auxiliary function. Prints info about a tree to a GV file.*/
    void Tree_Print (const Node* node1, FILE* f);

    /*! An auxiliary function. Prints info about a tree to a GV file.*/
    void Tree_Info_Dump (const Node* node1, FILE* f);

    /*! An auxiliary function for Akinator.*/
    elem_t Akinator_Cycle (Node* node1, char* answer);

    /*!An auxiliary function for File_Write.*/
    void File_Write_Cycle (Node* node1, FILE* f, int number);

    /*!An auxiliary function to insert tabs into txt file.*/
    void Insert_Tabs (FILE* f, int number);
};
