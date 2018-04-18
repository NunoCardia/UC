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

void print_sym_table_elem(sym_table *element){
  if(strcmp(element->node_type,"GLOBAL")==0){
    printf("===== Global Symbol Table =====\n");
  }
  else if(strcmp(element->node_type,"VARIABLE")==0){
    //print for VARIABLE
  }
  else if(strcmp(element->node_type,"FUNC_DECLARATION")==0){
    //print for FUNC_DECLARATION
  }
  else if(strcmp(element->node_type,"FUNC_TABLE")==0){
    printf("===== Function %s Symbol Table =====\n",element->id);
  }
  else if(strcmp(element->node_type,"RETURN_VALUE")==0){
    printf("return\t%s\n",element->type);
  }
}

void print_sym_table(sym_table *table){
  sym_table *temp = table;
  sym_table *final;
  while (temp->next !=NULL) {
    print_sym_table_elem(temp);
    temp = temp->next;
  }
  temp = temp->next;
  while (temp != NULL) {
    if(temp->definition != NULL){
      print_sym_table_elem(temp);
      final = temp->definition->next;
      while (final != NULL) {
        print_sym_table_elem(final);
        final = final->next;
      }
    }
    temp = temp->next;
  }

}
