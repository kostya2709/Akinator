#include "Akinator_Head.h"

char* cur_ptr = (char*)&data_size;

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

int Tree::Insert_Node (Node* node1, Node* node_new, int pos)
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

int Tree::Dump (void)
{
    char* file_name = (char*) calloc (FILE_NAME_SIZE, sizeof (char));
    char* file_png = (char*) calloc (FILE_NAME_SIZE, sizeof (char));


    file_name = "tree_print.gv";
    file_png = "tree_print.png";

    FILE* f = fopen (file_name, "w");


    fprintf (f, "digraph First{\n");
    fprintf (f, "node [shape=\"Mrecord\", style=\"filled\", fillcolor=\"lightblue\"];\n");

    Tree_Print (this->first_elem, f);

    fprintf (f, "}");

    fclose (f);

    system ("dot -Tpng tree_print.gv -o tree_print.png");


    file_name = "tree_dump.gv";
    file_png = "tree_dump.png";

    f = fopen (file_name, "w");

    fprintf (f, "digraph First{\n");
    fprintf (f, "node [shape=\"Mrecord\", style=\"filled\", fillcolor=\"lightblue\"];\n");

    Tree_Info_Dump(this->first_elem, f);

    fprintf (f, "}");

    fclose (f);

    system ("dot -Tpng tree_dump.gv -o tree_dump.png");

    system ("pause");

    return 0;
}

void Tree::Tree_Print (const Node* node1, FILE* f)
{
    if (node1 == this->first_elem)
        fprintf (f, "\"box%0x\" [label=\"%s\"];\n", node1, node1->data);

    if (node1->left)
        {
            fprintf (f, "\"box%0x\" [label=\"%s\"];\n", node1->left, (node1->left)->data);
            fprintf (f, "\"box%0x\" -> \"box%0x\"[label=\"No\", color=\"red\"];\n", node1, node1->left);

            Tree_Print (node1->left, f);
        }


    if (node1->right)
    {
        fprintf (f, "\"box%0x\" [label=\"%s\"];\n", node1->right, (node1->right)->data);
        fprintf (f, "\"box%0x\" -> \"box%0x\"[label=\"Yes\", color=\"green\"];\n", node1, node1->right);

        Tree_Print (node1->right, f);
    }

}

void Tree::Tree_Info_Dump (const Node* node1, FILE* f)
{
    if (node1 == this->first_elem)
        fprintf (f, "\"box%0x\" [label=\"{%s|adress=%0x|left=%0x|right=%0x}\"];\n", node1, node1->data, node1, node1->left, node1->right);

    if (node1->left)
        {
            fprintf (f, "\"box%0x\" [label=\"{%s|adress %0x|left=%0x|right=%0x}\"];\n", node1->left, (node1->left)->data, node1->left, (node1->left)->left, (node1->left)->right);
            fprintf (f, "\"box%0x\" -> \"box%0x\"[label=\"No\", color=\"red\"];\n", node1, node1->left);

            Tree_Info_Dump (node1->left, f);
        }


    if (node1->right)
    {
        fprintf (f, "\"box%0x\" [label=\"{%s|adress=%0x|left=%0x|right=%0x}\"];\n", node1->right, (node1->right)->data, node1->right, (node1->right)->left, (node1->right)->right);
        fprintf (f, "\"box%0x\" -> \"box%0x\"[label=\"Yes\", color=\"green\"];\n", node1, node1->right);

        Tree_Info_Dump (node1->right, f);
    }

}

int Tree::Akinator (void)
{
    printf ("Привет! Поиграем? Загадай кого-нибудь. Спорим, я угадаю? \n");

    char* answer = (char*)calloc (1, ANSWER_SIZE);

    Akinator_Cycle (this->first_elem, answer);

    return 0;
}

elem_t Tree::Akinator_Cycle (Node* node1, char* answer)
{
    printf ("%s\n", node1->data);
    if (node1->left == 0 && node1->right == 0)
        return (char*)node1->data;

    scanf ("%s", answer);
    if (!strcmp (answer,"Yes"))
    {
        if (node1->right)
            Akinator_Cycle (node1->right, answer);
        else
        {
            printf ("Oops. You can't go there. Please, use other answer.\n");
            Akinator_Cycle (node1, answer);
        }
    }
    else if (!strcmp (answer, "No"))
    {
        if (node1->left)
            Akinator_Cycle (node1->left, answer);
        else
        {
            printf ("Oops. You can't go there. Please, use other answer.\n");
            Akinator_Cycle (node1, answer);
        }
    }
    else
    {
        printf ("Invalid answer! Please, use \"Yes\" or \"No\" instead of %s.\n", answer);
        Akinator_Cycle (node1, answer);
    }
}

int Tree::File_Write (char* file_name)
{
    FILE* f = fopen (file_name, "w");

    (*this).File_Write_Cycle (this->first_elem, f, 1);

    fclose (f);

    return 0;
}

void Tree::File_Write_Cycle (Node* node1, FILE* f, int number)
{
    Insert_Tabs (f, number - 1);
    fprintf (f, "{\n");
    Insert_Tabs (f, number);
    fprintf (f, "\"%s\"", node1->data);
    fprintf (f, "\n");

    if ((node1->left == 0) && (node1->right))
    {
        Insert_Tabs (f, number + 1);
        fprintf (f, "$\n");
    }
    else if (node1->left)
        File_Write_Cycle (node1->left, f, number + 1);


    if ((node1->right == 0) && (node1->left))
    {
        Insert_Tabs (f, number + 1);
        fprintf (f, "$\n");
    }
    else if (node1->right)
        File_Write_Cycle (node1->right, f, number + 1);

    Insert_Tabs (f, number - 1);
    fprintf (f, "}\n");;
}

int Tree::File_Read (char* file_name)
{
    FILE* f = fopen (file_name, "r");

    char* string = (char*)calloc(1, ANSWER_STR);
    fread (string, 1, ANSWER_STR, f);

    cur_ptr = Delete_Str_Trash(string);
    free (string);

    int letter_num = 0;

    Node* node0 = new Node();
    this->first_elem = node0;

    File_Read_Cycle (this->first_elem);
    fclose (f);

    return 0;

}



void Tree::File_Read_Cycle (Node* node1)
{
    if (*cur_ptr == '\0')
        return;

    int letter_num = 0;

    cur_ptr += 2;                   ///Skips a brace and quotes.

    sscanf (cur_ptr, "%[^\"] %n", node1->data, &letter_num);

    cur_ptr += letter_num + 1;      ///Skips the string and quotes.

    if (*cur_ptr == '$')
        ;
    else if (*cur_ptr == '}')
    {
        return;
    }
    else
    {
        Node* node_left = new Node();
        node1->left = node_left;
        File_Read_Cycle(node_left);
    }

        cur_ptr++;

        if (*cur_ptr == '$')
            ;
        else if (*cur_ptr == '}')
            return;
        else
        {
            Node* node_right = new Node();
            node1->right = node_right;
            File_Read_Cycle(node_right);
        }
        if (*cur_ptr == '}')
            cur_ptr++;

}

void Tree::Insert_Tabs (FILE* f, int number)
{
    int i = 0;
    for (i = 0; i < number; i++)
        fprintf (f, "\t");
}

int Node::Is_Leaf (void)
{
    if ((this->left == 0) && (this->right == 0))
        return 1;

    return 0;
}

char* Delete_Str_Trash (char* str)
{
    char* new_str = (char*) calloc (1, strlen (str));

    char* start = new_str;

    int in_quotes = 0;

    while (*str)
    {
        if (*str == '\"')
            if (in_quotes == 0)
                in_quotes = 1;
            else in_quotes = 0;

        if (((*str == ' ') || (*str =='\t') || (*str == '\n'))&& in_quotes == 0)
            ;
        else
        {
            *new_str = *str;
            new_str++;
        }
        str++;
    }

    return start;
}
