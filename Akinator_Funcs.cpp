#include "Akinator_Head.h"

Node::Node(): left (NULL), right (NULL)
{
    this->data = (elem_t)calloc (data_size, sizeof (elem_t));
}

Node::~Node()
{
    free (this->data);
}

Tree::Tree(): elem_num (0), first_elem (0)
{
    Node zero_node;
    this->first_elem = &zero_node;
}

Tree::~Tree()
{
    free (this->first_elem);
}

int Tree::Insert_Node (Node* node_new, Node* node1, int pos)
{
    assert (node_new);
    assert (node1);

    if (pos == 0)
        node1->left = node_new;
    else if (pos == 1)
        node1->right = node_new;
    else
    {
        printf ("Error! Wrong position in Insert_Node\n\
                 Expected 0 for left or 1 for right. Received %d.", pos);
        return -1;
    }

    this->elem_num += 1;

    return 0;
}

int Tree::Insert_Node (Node* node_new)
{
    assert (node_new);

    if (this->elem_num == 0)
    {
        this->first_elem = node_new;
        this->elem_num = 1;
        return 0;
    }

    printf ("Error! Your tree is not empty!\n");
    return -1;
}

