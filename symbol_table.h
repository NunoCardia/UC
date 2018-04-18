#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 100

typedef struct sym_table{
  char node_type[MAX_STR];
  char id[MAX_STR];
  char type[MAX_STR];
  int n_params;
  struct sym_table** params;
  int is_parameter;
  struct sym_table* next;
  struct sym_table* definition;
  int defined;
} sym_table;


sym_table *st,*temp;
