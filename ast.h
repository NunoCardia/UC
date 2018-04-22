#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"

tree_node* create_simple_node(char* name,int line,int col);
tree_node* create_value_node(char* name, char* value,int line,int col);

void add_child(tree_node * father , tree_node * son);
void add_brother(tree_node* father, tree_node* new_son);

void print_points(int n);
void print_terminal(tree_node* node);
void print_tree(tree_node* node, int level);
