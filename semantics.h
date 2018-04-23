#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "structures.h"
#include "symbol_table.h"
#include "ast.h"

sym_table *is_function(sym_table *st, tree_node *which_node, char *func_name);
void parse_return_node(sym_table *st,tree_node *node, char function_name[MAX_STR]);
void semantics(tree_node *node, sym_table *st, char function_name[MAX_STR], int is_anotated,int error);
void print_an_node(tree_node* n, int an);
void print_an_tree(tree_node* n, int d, int an);
