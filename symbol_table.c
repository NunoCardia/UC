#include "symbol_table.h"


sym_table *create_node(char *node_type,char *name,char *type){
  sym_table *node = (sym_table *) malloc(sizeof(sym_table));
  memset(node,0,sizeof(sym_table));
  strcpy(node->node_type,node_type);
  strcpy(node->type,type);
  strcpy(node->id,name);
  node->n_params = 0;
  node->is_parameter = 0;
  node->defined = 0;
  node->next = NULL;
  node->definition = NULL;
  node->params = (sym_table**) malloc(1000 * sizeof(sym_table*));

  int i;
  for(i=0;i<20;i++){
    node->params[i] = NULL;
  }
  return node;
}


void init_sym_table(){
  st = create_node("GLOBAL","Global","UNKNOWN");
  temp = st;
  temp->next = create_node("FUNC_DECLARATION","getchar","INT");
  temp->next->defined = 1;
  temp->next->n_params = 0;
  temp = temp->next;

  temp->next = create_node("FUNC_DECLARATION","putchar","INT");
  temp->next->defined = 1;
  temp->next->n_params = 1;
  temp->next->params[0] = create_node("VARIABLE",NULL,"INT");
  temp = temp->next;
}
