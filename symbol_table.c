#include "symbol_table.h"


sym_table *create_node(char *node_type,char *name,char *type){
  sym_table *node = (sym_table *) malloc(sizeof(sym_table));
  memset(node,0,sizeof(sym_table));
  
}
