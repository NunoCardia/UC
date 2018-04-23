#ifndef STRUCTURES_H
#define STRUCTURES_H

#define MAX_STR 100

typedef struct sym_table{
  char node_type[MAX_STR]; //node_type
  char id[MAX_STR];//id
  char type[MAX_STR];//type_t type
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


#endif
