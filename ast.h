#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 100

typedef struct _tree_node {
    struct _tree_node* father;
    struct _tree_node* next_brother;
    struct _tree_node* son;

    char name[MAX_STR];

    char value[MAX_STR];
} tree_node;

tree_node* create_simple_node(char* name);
tree_node* create_value_node(char* name, char* value);

void add_child(tree_node * father , tree_node * son);
void add_brother(tree_node* father, tree_node* new_son);

void print_points(int n);
void print_terminal(tree_node* node);
void print_tree(tree_node* node, int level);
