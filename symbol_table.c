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
  for(i=0;i<1000;i++){
    node->params[i] = NULL;
  }
  return node;
}

tree_node *return_tree_node(tree_node *node, int son){
  int i=0;
  tree_node *node1 = node->son;
  while(node1!=NULL){
    if(i==son){
      return node1;
    }
    else{
      node1 = node1->next_brother;
      i++;
    }
  }
  return NULL;
}

int n_childs(tree_node* node){
  int i=0,soma=0;
  tree_node *temp = node->son;
  while(temp!=NULL){
    soma++;
    i++;
    temp = temp->next_brother;
  }
  return soma;
}


char* parse_type(char *nome){
  char *to_return;
  to_return = malloc(MAX_STR*sizeof(char));
  if(strcmp(nome,"IntLit")==0 || strcmp(nome,"Int")==0){
    strcpy(to_return,"int");
  }
  else if(strcmp(nome,"ChrLit")==0 || strcmp(nome,"Char")==0){
    strcpy(to_return,"char");
  }
  else if(strcmp(nome,"Void")==0){
    strcpy(to_return,"void");
  }
  else if(strcmp(nome,"Double")==0 || strcmp(nome,"RealLit")==0){
    strcpy(to_return,"double");
  }
  else if(strcmp(nome,"Short")==0){
    strcpy(to_return,"short");
  }
  else{
    strcpy(to_return,"UNKNOWN");
  }
  return to_return;
}

sym_table *create_variable_node(tree_node *node){
  sym_table *new_node;
  tree_node *node1 = return_tree_node(node,1);
  tree_node *node2 = return_tree_node(node,0);
  if(n_childs(node) <= 1){
      new_node = create_node("VARIABLE",NULL,parse_type(node2->name));
  }
  else{
      new_node = create_node("VARIABLE",node1->value,parse_type(node2->name));
  }
  return new_node;
}

sym_table *create_declaration_node(tree_node *node){
  tree_node *node1 = return_tree_node(node,1);
  tree_node *node2 = return_tree_node(node,0);
  sym_table *new_node = create_node("FUNC_DECLARATION",node1->value,parse_type(node2->name));
  return new_node;
}

sym_table *create_func_table_node(tree_node *node){
  tree_node *node1 = return_tree_node(node,1);
  tree_node *node2 = return_tree_node(node,0);
  sym_table *new_node = create_node("FUNC_TABLE",node1->value,parse_type(node2->name));
  return new_node;
}

void print_function(sym_table *node){
  int i=0;
  printf("%s(",node->type);
  if(node->n_params == 0){
    printf("void");
  }
  else{
    for (i = 0; i < node->n_params; i++) {
      sym_table *arg = node->params[i];
      printf("%s", arg->type);
      if (i != node->n_params - 1) {
        printf(",");
      }
    }
  }
  printf(")");
}

int add_definition(sym_table *st, sym_table *table_node, tree_node *cur_node, sym_table *declaration_node){
  sym_table *new_node, *last_node;
  int error_given=0,i = 0,childs;

  declaration_node->definition = table_node;
  last_node = table_node;
  tree_node *node2 = return_tree_node(cur_node,0);
  new_node = create_node("RETURN","",parse_type(node2->name));
  declaration_node->definition->next = new_node;
  last_node = new_node;
  tree_node* param_list = return_tree_node(cur_node,2);
  int declaration_node_was_defined = declaration_node->n_params > 0;
  int arg_mismatch = 0;
  if (declaration_node_was_defined) {
    if (strcmp(declaration_node->type,table_node->type)!=0) {
      arg_mismatch = 1;
    }
  }
  childs = n_childs(param_list);
  for(i=0;i < childs ; i++){
    tree_node *param_declaration = return_tree_node(param_list,i);
    int inserted = 0;
    int should_not_insert = 0;
    tree_node *node3 = return_tree_node(param_declaration,0);
    if(n_childs(param_declaration) == 1 && strcmp(parse_type(node3->name),"void")==0){
      if(i < declaration_node->n_params){
        arg_mismatch = 1;
      }
      new_node = create_node("VARIABLE","","void");
      new_node->is_parameter = 1;
      if (declaration_node_was_defined == 0) {
        declaration_node->params[declaration_node->n_params++] = new_node;
      }

      inserted = 1;
    }
    if(!inserted){
      new_node = create_variable_node(param_declaration);
      new_node->is_parameter = 1;
    }

    if(i>=1){
      sym_table *cur_st_node = table_node->next->next;
      while (cur_st_node != NULL) {
        if (strcmp(cur_st_node->id,"")!=0 && strcmp(new_node->id,"")!=0) {
          if (!strcmp(cur_st_node->id, new_node->id)) {
            printf("Line %d, col %d: Symbol %s already defined\n", param_declaration->line, param_declaration->col, cur_st_node->id);
            should_not_insert = 1;
            break;
          }
        }

        if (cur_st_node == last_node) break;
        cur_st_node = cur_st_node->next;
      }
    }

    if (declaration_node_was_defined == 0) {
      if (!inserted) {
        declaration_node->params[declaration_node->n_params++] = new_node;
      }
    } else {
      if (i < declaration_node->n_params) {
        if (strcmp(declaration_node->params[i]->type,new_node->type)!=0) {
          arg_mismatch = 1;
        }
      }
    }
    if (strcmp(parse_type(new_node->type),"void")==0  && (strcmp(new_node->id,"")!=0 || n_childs(param_list) > 1)) {
      tree_node *asd = return_tree_node(param_declaration,0);
      printf("Line %d, col %d: Invalid use of void type in declaration\n", asd->line, asd->col);
      should_not_insert = 1;
      error_given = 1;
      break;
    }

    if (!inserted && !should_not_insert) {
      last_node->next = new_node;
      last_node = new_node;
    }
  }
  if(!error_given){
    if(arg_mismatch || declaration_node->n_params != n_childs(param_list)){
      error_given = 1;
      printf("Line %d, col %d: Conflicting types (got ", cur_node->line, cur_node->col);
      printf("%s(",table_node->type);
      sym_table *cur_st_node = table_node->next->next;
      if (cur_st_node == NULL) {
        printf("void");
      } else {
        while (cur_st_node != NULL) {
          printf("%s",cur_st_node->type);
          if (cur_st_node != last_node) {
            printf(",");
          }
          cur_st_node = cur_st_node->next;
        }
      }
      printf("), expected ");
      print_function(declaration_node);
      printf(")\n");
    }
  }
  if (error_given) {
    declaration_node->definition = NULL;
    free(table_node);
  }
  return error_given;
}

int add_to_top(sym_table *st, sym_table *node){
  if (st->next == NULL) {
    st->next = node;
    return 1;
  }

  while (st->next != NULL) {
    if (strcmp(st->next->node_type,"FUNC_TABLE")==0) {
      sym_table *tmp = st->next;
      st->next = node;
      node->next = tmp;
      return 0;
    }
    st = st->next;
  }

  st->next = node;
  return 1;
}


void init_sym_table(){

  st = create_node("GLOBAL","Global","UNKNOWN");

  temp = st;

  temp->next = create_node("FUNC_DECLARATION","putchar","int");
  temp->next->defined = 1;
  temp->next->n_params = 1;
  temp->next->params[0] = create_node("VARIABLE","","int");
  temp = temp->next;

  temp->next = create_node("FUNC_DECLARATION","getchar","int");
  temp->next->defined = 1;
  temp->next->n_params = 1;
  temp->next->params[0] = create_node("VARIABLE","","void");
  temp = temp->next;


}

void print_sym_table_elem(sym_table *element){
  if(strcmp(element->node_type,"GLOBAL")==0){
    printf("===== Global Symbol Table =====\n");
  }
  else if(strcmp(element->node_type,"VARIABLE")==0){
    if(strcmp(element->id,"") != 0){
      if(element->is_parameter != 0){
        printf("%s\t%s\tparam\n", element->id, element->type);
      }
      else{
        printf("%s\t%s\n", element->id, element->type);
      }
    }
  }
  else if(strcmp(element->node_type,"FUNC_DECLARATION")==0){
    printf("%s\t%s(", element->id, element->type);
    int i;
    for (i = 0; i < element->n_params; i++) {
      sym_table *temp1 = element->params[i];
      printf("%s", temp1->type);
      if (i != element->n_params - 1) {
        printf(",");
      }
    }
    printf(")\n");
  }
  else if(strcmp(element->node_type,"FUNC_TABLE")==0){
    printf("\n===== Function %s Symbol Table =====\n",element->id);
  }
  else if(strcmp(element->node_type,"RETURN")==0){
    printf("return\t%s\n",element->type);
  }
}

void print_sym_table(sym_table *table){
  sym_table *temp1 = table;
  sym_table *final;
  while (temp1!=NULL) {
    print_sym_table_elem(temp1);
    temp1 = temp1->next;
  }
  temp1 = table->next;
  while (temp1 != NULL) {
    if(temp1->definition != NULL){
      print_sym_table_elem(temp1->definition);
      final = temp1->definition->next;
      while (final != NULL) {
        print_sym_table_elem(final);
        final = final->next;
      }
    }
    temp1 = temp1->next;
  }
}
