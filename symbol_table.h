#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "structures.h"

sym_table *st,*temp;

sym_table *create_node(char *node_type,char *name,char *type);
tree_node *return_tree_node(tree_node *node, int son);
int n_childs(tree_node* node);
char *tolowercase(char *name);
sym_table *create_variable_node(tree_node *node);
sym_table *create_declaration_node(tree_node *node);
sym_table *create_func_table_node(tree_node *node);
void print_function(sym_table *node);
int add_definition(sym_table *st, sym_table *table_node, tree_node *cur_node, sym_table *declaration_node);
int add_to_top(sym_table *st, sym_table *node);
void init_sym_table();
void print_sym_table_elem(sym_table *element);
void print_sym_table(sym_table *table);
