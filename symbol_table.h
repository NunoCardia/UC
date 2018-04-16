#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ast.h"

#define MAX_STR 100

typedef struct sym_table{
  char node_type[MAX_STR]; //node_type
  char name[MAX_STR];//id
  char type[MAX_STR];//type_t type
  int n_params;
  struct sym_table** params;
  int is_parameter;
  struct sym_table* next;
  struct sym_table* definition;
  int defined;
} sym_table;