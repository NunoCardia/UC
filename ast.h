#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 100

typedef struct sym_table{
  char table_type[MAX_STR];
  char name[MAX_STR];
  char type[MAX_STR];
  int n_params;
  struct sym_table** params;
  int is_parameter;
  struct sym_table* next;
  struct sym_table* definition;
  int defined;
} sym_table;

typedef struct _tree_node {
    struct _tree_node* father;
    struct _tree_node* next_brother;
    struct _tree_node* son;
    char name[MAX_STR];
    char value[MAX_STR];
    //meta 3
    char an_type[MAX_STR];
    int an_n_params;
    sym_table **an_params;
    int line,col;//for location purposes when printing errors
} tree_node;

tree_node* create_simple_node(char* name,int line,int col);
tree_node* create_value_node(char* name, char* value,int line,int col);

void add_child(tree_node * father , tree_node * son);
void add_brother(tree_node* father, tree_node* new_son);

void print_points(int n);
void print_terminal(tree_node* node);
void print_tree(tree_node* node, int level);
