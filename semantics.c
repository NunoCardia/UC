#include "semantics.h"

//TODO convert name to symbols in error statements
//TODO got YYLTYPE to work BUT NEEDS TO BE CHANGED

void print_an_node(tree_node* n, int an) {
  if (!an) {

    print_node(n);
    return;
  }

  if (strcmp(n->name,"Id")==0 || strcmp(n->name,"ChrLit")==0 || strcmp(n->name,"IntLit")==0 || strcmp(n->name,"RealLit")==0) {
    if (strcmp(n->an_type,"UNKNOWN")==0 || strcmp(n->an_type,"")==0) {
      printf("%s(%s)\n", n->name, n->value);
    } else if (n->an_n_params > 0) {
      printf("%s(%s) - %s", n->name, n->value, n->an_type);
      printf("(");

      int i;

      for (i = 0; i < n->an_n_params; i++) {
        sym_table *arg = n->an_params[i];

        printf("%s", arg->type);
        if (i != n->an_n_params - 1) printf(",");
      }
      printf(")\n");
    } else {
      printf("%s(%s) - %s\n", n->name, n->value, n->an_type);

    }
  } else {
    if (strcmp(n->an_type,"UNKNOWN")==0 || strcmp(n->an_type,"")==0) {
      printf("%s\n", n->name);
    } else {
      printf("%s - %s\n", n->name,n->an_type);
    }
  }
}

void print_an_tree(tree_node* n, int d, int an) {
  int i, k,childs;
  for (k = 0; k < d; k++)
    printf("..");

  print_an_node(n, an);

  childs = n_childs(n);
  for (i = 0; i < childs; i++) {
    tree_node *t1 = return_tree_node(n,i);
    print_an_tree(t1, d + 1, an);
  }
}

void print_function_type(sym_table *decl_node) {
  printf("%s", decl_node->type);
  printf("(");
  if (decl_node->n_params == 0) {
    printf("void");
  } else {
    int i;
    for (i = 0; i < decl_node->n_params; i++) {
      sym_table *arg = decl_node->params[i];
      printf("%s", arg->type);
      if (i != decl_node->n_params - 1) {
        printf(",");
      }
    }
  }

  printf(")");
}

sym_table *is_sym_function(sym_table *st, sym_table *node) {
  sym_table *cur_st_node = st;

  while (cur_st_node != NULL) {
    if (strcmp(node->id,"")!=0) {
      if (!strcmp(cur_st_node->id, node->id) && strcmp(cur_st_node->node_type,"FUNC_DECLARATION")==0) {
        return cur_st_node;
      }
    }
    cur_st_node = cur_st_node->next;
  }

  return NULL;
}

void set_function_type(sym_table *st, tree_node *node) {
  sym_table *cur_st_node = st->next;
  tree_node *t1 = return_tree_node(node,0);
  char *function_name = t1->value;

  while (cur_st_node != NULL) {
    if (!strcmp(cur_st_node->id, function_name)) {
      strcpy(node->an_type,cur_st_node->type);
    }

    cur_st_node = cur_st_node->next;
  }
}

void operator_applied2(tree_node *operator, tree_node *node1, tree_node *node2) {
  printf("Line %d, col %d: Operator %s cannot be applied to types ", operator->line, operator->col, operator->value);
  printf("%s",node1->an_type);
  printf(", ");
  printf("%s",node2->an_type);
  printf("\n");
}

void operator_applied1(tree_node *operator, tree_node *node1) {
  printf("Line %d, col %d: Operator %s cannot be applied to type ",operator->line, operator->col, operator->value);
  print_node(node1);
  printf("\n");
}

void operator_applied1_function(tree_node *operator, sym_table *decl_node) {
  printf("Line %d, col %d: Operator %s cannot be applied to type ", operator->line, operator->col, operator->value);
  print_function_type(decl_node);
  printf("\n");
}




sym_table *is_function(sym_table *st, tree_node *node, char function_name[MAX_STR]) {
  sym_table *cur_st_node = st;

  if (strcmp(node->value,"")==0) {
    return NULL;
  }
  if (strcmp(function_name,"")!=0) {
    while (cur_st_node != NULL) {
      if (!strcmp(cur_st_node->id, function_name) && strcmp(cur_st_node->node_type,"FUNC_DECLARATION")==0) {
        if (cur_st_node->definition == NULL) break;

        cur_st_node = cur_st_node->definition->next;

        while (cur_st_node != NULL) {
          if (strcmp(cur_st_node->id,"")!=0) {
            if (!strcmp(cur_st_node->id, node->name)) {
              return NULL;
            }
          }

          cur_st_node = cur_st_node->next;
        }

        break;
      }

      cur_st_node = cur_st_node->next;
    }
  }

  // now check if function_name corresponds to some global function
  cur_st_node = st;
  while (cur_st_node != NULL) {
    if (strcmp(node->value,"")!=0) {
      if (!strcmp(cur_st_node->id, node->name) && strcmp(cur_st_node->node_type,"FUNC_DECLARATION")==0) {
        return cur_st_node;
      }
    }

    cur_st_node = cur_st_node->next;
  }
  return NULL;
}

int parse_func_definition(sym_table *st,tree_node *node){
  sym_table *table_node = create_func_table_node(node);
  tree_node *t1 = NULL;
  sym_table *cur_st_node = st;
  sym_table *declaration_node = NULL;

  int print_conflicting_type = 0;

  while (cur_st_node != NULL) {
    if (!strcmp(cur_st_node->id, table_node->id)) {
      if (strcmp(cur_st_node->node_type,"FUNC_DECLARATION")!=0 || (strcmp(cur_st_node->node_type,"FUNC_DECLARATION")==0 && cur_st_node->definition != NULL)) {
        sym_table *func_node = is_sym_function(st, cur_st_node);

        if (func_node) {
          t1 = return_tree_node(node,1);
          printf("Line %d, col %d: Symbol %s already defined\n", node->line, t1->col, cur_st_node->id);
          return 1;
        } else {
          print_conflicting_type = 1;
        }

        break;
      }
      declaration_node = cur_st_node;
    }
    cur_st_node = cur_st_node->next;
  }
  sym_table *temp = last;
  if (declaration_node == NULL) {
    declaration_node = create_node("FUNC_DECLARATION", table_node->id, table_node->type);
    add_to_top(st, declaration_node);
    last = declaration_node;
  }

  int error_given = add_definition(st, table_node, node, declaration_node);
  if (print_conflicting_type) {
    t1 = return_tree_node(node,1);
    printf("Line %d, col %d: Conflicting types (got ", node->line, node->col);
    print_function_type(declaration_node);
    printf(", expected %s)\n",cur_st_node->type);
    error_given = 1;
  }

  if (error_given) {
    last = temp;
    temp->next = NULL;
  }
  return error_given;
}

void parse_return_node(sym_table *st,tree_node *node, char function_name[MAX_STR]){
  int i;
  char type[MAX_STR];
  strcpy(type,"UNKNOWN");
  sym_table *return_st = st;
  while (return_st != NULL) {
    if(strcmp(return_st->id,function_name)==0){
      strcpy(type,return_st->type);
      break;
    }
    return_st = return_st->next;
  }
  tree_node *t1 = return_tree_node(node,0);
  sym_table *func_node = is_function(st,t1, function_name);
  if (func_node != NULL) {
    printf("Line %d, col %d: Conflicting types (got ", node->line, node->col);
    printf("%s(", t1->name);

    for (i = 0; i < t1->an_n_params; i++) {
      sym_table *arg = t1->an_params[i];

      printf("%s", arg->type);
      if (i != t1->an_n_params - 1) printf(",");
    }

    printf(")");

    printf(", expected ");
    printf("%s)\n", type);
    return;
  }
}

void parse_func_declaration(sym_table *st, tree_node *node, char function_name[MAX_STR]){
  sym_table *declaration_node = create_declaration_node(node);
  tree_node* param_list = return_tree_node(node,2);
  int to_insert = 1,i=0,childs = 0;
  childs = n_childs(param_list);
  for(i=0;i<childs;i++){
    tree_node *param_declaration = return_tree_node(param_list,i);
    sym_table *to_table = create_variable_node(param_declaration);
    to_table->is_parameter = 1;
    declaration_node->params[declaration_node->n_params++] = to_table;
    if(strcmp(to_table->type,"void")==0 && (strcmp(to_table->id,"")!=0 || childs > 1)){

      tree_node *error_node = return_tree_node(param_declaration,0);
      printf("Line %d, col %d: Invalid use of void type in declaration\n", error_node->line, error_node->col);
      to_insert = 0;
      break;
    }
    if (i >= 1) {
      int u;
      for (u = 0; u < i; u++) {
        if (strcmp(to_table->id,"")!=0 && strcmp(declaration_node->params[u]->id,"")!=0) {
          if (!strcmp(to_table->id, declaration_node->params[u]->id)) {
            printf("Line %d, col %d: Symbol %s already defined\n", param_declaration->line, param_declaration->col, declaration_node->params[i]->id);
            break;
          }
        }
      }
    }
  }
  sym_table *cur_st_node = st;
  int arg_mismatch = 0;
  int duplicate = 0;

  if (to_insert) {
    while (cur_st_node != NULL) {
      if (!strcmp(cur_st_node->id, declaration_node->id)) {
        if (strcmp(cur_st_node->node_type,"FUNC_DECLARATION")!=0) {
          printf("Line %d, col %d: Conflicting types (got ", node->line, node->col);
          print_function_type(declaration_node);
          printf(", expected %s)\n",cur_st_node->type);
          return;
        } else {
          if (strcmp(cur_st_node->type,declaration_node->type)!=0) {
            arg_mismatch = 1;
          }

          if (cur_st_node->n_params != declaration_node->n_params) {
            arg_mismatch = 1;
          }

          int i;

          for (i = 0; i < cur_st_node->n_params && i < declaration_node->n_params; i++) {
            if (strcmp(cur_st_node->params[i]->type,declaration_node->params[i]->type)!=0) {
              arg_mismatch = 1;
            }
          }
          duplicate = 1;
        }

        break;
      }

      cur_st_node = cur_st_node->next;
    }
  }

  if (arg_mismatch) {
    printf("Line %d, col %d: Conflicting types (got ", node->line, node->col);
    print_function_type(declaration_node);
    printf(", expected ");
    print_function_type(cur_st_node);
    printf(")\n");
  } else {
    if (!duplicate && to_insert) {
      if (add_to_top(st, declaration_node) == 1) {
        last = declaration_node;
      }
    }
  }
}

void parse_declaration(sym_table *st,tree_node *node,char function_name[MAX_STR]){
  sym_table *cur_st_node = st;
  sym_table *func_node;
  int duplicate = 0;
  sym_table *new_node = create_variable_node(node);
  tree_node *t1 = return_tree_node(node,1);
  func_node = is_function(st, t1, function_name);
  if (func_node != NULL && function_name == NULL) {
    printf("Line %d, col %d: Conflicting types (got ", node->line, node->col);
    printf("%s",new_node->type);
    printf(", expected ");
    print_function_type(func_node);
    printf(")\n");
    return;
  }
  if (strcmp(new_node->type,"void")==0) {
    t1 = return_tree_node(node,0);
    printf("Line %d, col %d: Invalid use of void type in declaration\n", t1->line, t1->col);
    return;
  }


  if (strcmp(function_name,"")!=0) { // variaveis globais podem ser declaradas duas vezes
    while (cur_st_node != NULL) {
      if (!strcmp(cur_st_node->id, function_name)) {
        func_node = cur_st_node;
      }
      cur_st_node = cur_st_node->next;
    }
    cur_st_node = func_node->definition->next;
    while (cur_st_node != NULL) {
      t1 = return_tree_node(node,n_childs(node) - 1);
      if (strcmp(cur_st_node->id,"")!=0 && !strcmp(cur_st_node->id, t1->value)) {
        printf("Line %d, col %d: Symbol %s already defined\n", node->line, node->col,t1->value);
        duplicate = 1;
        break;
      }

      cur_st_node = cur_st_node->next;
    }
  } else {
    while (cur_st_node != NULL) {
      if (!strcmp(cur_st_node->id, new_node->id)) { // check if preivous decl was something else
        if (strcmp(cur_st_node->type,new_node->type)!=0) {
          printf("Line %d, col %d: Conflicting types (got %s", node->line, node->col, new_node->type);
          printf(", expected %s)\n", cur_st_node->type);
        }
        duplicate = 1;
      }
      cur_st_node = cur_st_node->next;
    }
  }
  if (strcmp(function_name,"")==0) {
    if (!duplicate) {
      if (add_to_top(st, new_node) == 1) {
        last = new_node;
      }
    }
  } else {
    if (!duplicate) {
      cur_st_node = st;

      while (cur_st_node != NULL) {
        if (!strcmp(cur_st_node->id, function_name)) {
          func_node = cur_st_node;
        }

        cur_st_node = cur_st_node->next;
      }

      cur_st_node = func_node->definition;
      while (cur_st_node->next != NULL) {
        cur_st_node = cur_st_node->next;
      }

      cur_st_node->next = new_node;
    }
  }
}

void parse_id(tree_node *node, sym_table *st, char function_name[MAX_STR], int is_anotated){
  if (!is_anotated) { // todo: check for duplicate but not annotate
    return;
  }
  sym_table *cur_st_node = st->next;
  cur_st_node = st->next;
  if (strcmp(function_name,"")!= 0) {
    while (cur_st_node != NULL) {
      if (strcmp(cur_st_node->id,"")!=0) {
        //printf("cur_st_node->id %s\tcur_st_node->node_type %s \n",cur_st_node->id,cur_st_node->node_type);
        if (strcmp(cur_st_node->id,function_name)==0 && strcmp(cur_st_node->node_type,"FUNC_DECLARATION")==0) {
          if (cur_st_node->definition == NULL) break;
          cur_st_node = cur_st_node->definition->next;
          while (cur_st_node != NULL && strcmp(cur_st_node->node_type,"FUNC_TABLE")!=0) {
            if (strcmp(cur_st_node->id,"")!=0) {
              if (!strcmp(cur_st_node->id, node->value)) {
                strcpy(node->an_type,cur_st_node->type);
                return;
              }
            }
            cur_st_node = cur_st_node->next;
          }
          break;
        }
      }
      cur_st_node = cur_st_node->next;
    }
  }

  cur_st_node = st->next;

  // second thing to do is verify if node corresponds to a function
  if (strcmp(function_name,"")!= 0) { // find declaration
    while (cur_st_node != NULL) {
      if (strcmp(cur_st_node->node_type,"FUNC_DECLARATION")==0) {
        if (!strcmp(cur_st_node->id, node->value)) {
          strcpy(node->an_type,cur_st_node->type);
          node->an_params = cur_st_node->params;
          node->an_n_params = cur_st_node->n_params;

          int i;
          for (i = 0; i < cur_st_node->n_params; i++) {
            sym_table *param = (sym_table*) malloc(sizeof(sym_table));
            strcpy(param->type,cur_st_node->params[i]->type);
            node->an_params[i] = param;
          }
          return;
        }
      }
      cur_st_node = cur_st_node->next;
    }
  }

  // check global variables

  cur_st_node = st->next;

  while (cur_st_node != NULL) {
    if (!strcmp(cur_st_node->id, node->value)) {
      strcpy(node->an_type,cur_st_node->type);
      return;
    }
    cur_st_node = cur_st_node->next;
  }
  strcpy(node->an_type,"UNKNOWN");
  printf("Line %d, col %d: Unknown symbol %s\n", node->line, node->col, node->value);
}

void parse_add(tree_node *node, sym_table *st, char function_name[MAX_STR]){

  sym_table *func_node1 = is_function(st, return_tree_node(node,0), function_name);
  sym_table *func_node2 = is_function(st, return_tree_node(node,1), function_name);
  tree_node *t1,*t2;

  if (func_node1 && !func_node2) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ", node->line, node->col, node->value);
    print_function_type(func_node1);
    printf(", ");
    t1 = return_tree_node(node,1);
    printf("%s\n",t1->an_type);*/
    return;
  } else if (!func_node1 && func_node2) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ", node->line, node->col, node->value);
    t1 = return_tree_node(node,0);
    printf("%s",t1->an_type);
    printf(", ");
    print_function_type(func_node2);
    printf("\n");*/
    return;
  } else if (func_node1 && func_node2) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ", node->line, node->col, node->value);
    print_function_type(func_node1);
    printf(", ");
    print_function_type(func_node2);
    printf("\n");*/
    return;
  }

  t1 = return_tree_node(node,0);
  int first_undef = (strcmp(t1->an_type,"undef")==0) ? 1 : 0;
  t1 = return_tree_node(node,1);
  int second_undef = (strcmp(t1->an_type,"undef")==0) ? 1 : 0;

  if (first_undef && !second_undef) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ", node->line, node->col, node->value);
    printf("undef");
    printf(", ");
    t1 = return_tree_node(node,1);
    printf("%s\n",t1->an_type);
    strcpy(node->an_type,"undef");*/
    return;
  } else if (!first_undef && second_undef) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ", node->line, node->col, node->value);
    t1 = return_tree_node(node,0);
    printf("%s",t1->an_type);
    printf(", ");
    printf("undef");
    printf("\n");
    strcpy(node->an_type,"undef");*/
    return;
  } else if (first_undef && second_undef) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ",node->line, node->col, node->value);
    printf("undef");
    printf(", ");
    printf("undef");
    printf("\n");
    strcpy(node->an_type,"undef");*/
    return;
  }
  t1 = return_tree_node(node,0);
  t2 = return_tree_node(node,1);
  if (strcmp(t1->an_type,"void")==0 || strcmp(t2->an_type,"void")==0) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ",node->line, node->col, node->value);
    printf("%s",t1->an_type);
    printf(", ");
    printf("%s",t2->an_type);
    printf("\n");*/
    return;
  }

  if (strcmp(t1->an_type,t2->an_type)==0) {
    if (strcmp(t1->an_type,"char")==0) { // both are chars
      strcpy(node->an_type,"char");
    } else if (strcmp(t1->an_type,"void")==0) {
      ////operator_applied2(node, t1, t2);
    } else if(strcmp(t1->an_type,"short")==0) {
      strcpy(node->an_type,"short");
    }else {
      strcpy(node->an_type,t1->an_type);
    }
  } else {
    if ((strcmp(t1->an_type,"char")==0 && strcmp(t2->an_type,"int")==0) ||
        (strcmp(t1->an_type,"int")==0 && strcmp(t2->an_type,"char")==0)) { // one is char, the other is int

      if (strcmp(t1->name,"ChrLit")==0) {
        strcpy(t1->an_type,"int");
      }
      if (strcmp(t2->name,"ChrLit")==0) {
        strcpy(t2->an_type,"int");
      }
      strcpy(node->an_type,"int");
    }

    if(strcmp(t1->an_type,"double")==0 || strcmp(t2->an_type,"double")==0){
          strcpy(node->an_type,"double");
    }

    if((strcmp(t1->an_type,"short")==0 && strcmp(t2->an_type,"int")==0) ||
        (strcmp(t1->an_type,"int")==0 && strcmp(t2->an_type,"short")==0)){
          strcpy(node->an_type,"int");
    }

    if((strcmp(t1->an_type,"short")==0 && strcmp(t2->an_type,"char")==0) ||
        (strcmp(t1->an_type,"char")==0 && strcmp(t2->an_type,"short")==0)){
          strcpy(node->an_type,"short");
    }
    if((strcmp(t1->an_type,"char")==0 && strcmp(t2->an_type,"char")==0)){
          strcpy(node->an_type,"char");
    }
  }
}

void parse_sub(tree_node *node, sym_table *st, char function_name[MAX_STR]){
  tree_node *t1,*t2;
  t1 = return_tree_node(node,0);
  t2 = return_tree_node(node,1);
  sym_table *func_node1 = is_function(st, t1, function_name);
  sym_table *func_node2 = is_function(st, t2, function_name);

  if (func_node1 && !func_node2) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ", node->line, node->col,node->value);
    print_function_type(func_node1);
    printf(", ");
    printf("%s\n",t2->an_type);*/
    return;
  } else if (!func_node1 && func_node2) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ",  node->line, node->col,node->value);
    printf("%s",t1->an_type);
    printf(", ");
    print_function_type(func_node2);
    printf("\n");*/
    return;
  } else if (func_node1 && func_node2) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ",  node->line, node->col,node->value);
    print_function_type(func_node1);
    printf(", ");
    print_function_type(func_node2);
    printf("\n");*/
    return;
  }

  int first_undef = (strcmp(t1->an_type,"undef")==0) ? 1 : 0;
  int second_undef = (strcmp(t2->an_type,"undef")==0) ? 1 : 0;

  if (first_undef && !second_undef) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ",  node->line, node->col,node->value);
    printf("undef");
    printf(", ");
    printf("%s\n",t2->an_type);
    strcpy(node->an_type,"undef");*/
    return;
  } else if (!first_undef && second_undef) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ", node->line, node->col,node->value);
    printf("%s",t1->an_type);
    printf(", ");
    printf("undef");
    printf("\n");
    strcpy(node->an_type,"undef");*/
    return;
  } else if (first_undef && second_undef) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ",  node->line, node->col,node->value);
    printf("undef");
    printf(", ");
    printf("undef");
    printf("\n");
    strcpy(node->an_type,"undef");*/
    return;
  }

  if (strcmp(t1->an_type,"void")==0 || strcmp(t2->an_type,"void")==0) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ",node->line, node->col,node->value);
    printf("%s",t1->an_type);
    printf(", ");
    printf("%s",t2->an_type);
    printf("\n");*/
    return;
  }
  if(strcmp(t1->an_type,"double")==0 || strcmp(t2->an_type,"double")==0){
        strcpy(node->an_type,"double");
  }
  else if((strcmp(t1->an_type,"short")==0 && strcmp(t2->an_type,"char")==0) ||
      (strcmp(t1->an_type,"char")==0 && strcmp(t2->an_type,"short")==0)){
        strcpy(node->an_type,"short");
  }
  else if(strcmp(t1->an_type,t2->an_type)==0){
    strcpy(node->an_type,t1->an_type);
  }
  else{
      strcpy(node->an_type,"int");
  }

}

void parse_comma(tree_node *node, sym_table *st, char function_name[MAX_STR]){
  tree_node *t1,*t2,*t3;
  int i,childs;
  t1 = return_tree_node(node,0);
  t2 = return_tree_node(node,1);
  sym_table *func_node1 = is_function(st, t1, function_name);
  sym_table *func_node2 = is_function(st, t2, function_name);

  int first_undef = (strcmp(t1->an_type,"undef")==0) ? 1 : 0;
  int second_undef = (strcmp(t2->an_type,"undef")==0) ? 1 : 0;

  if (func_node1 && !func_node2) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ",node->line, node->col,node->value);
    print_function_type(func_node1);
    printf(", ");
    printf("%s\n",t2->an_type);*/
  } else if (!func_node1 && func_node2) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ",node->line, node->col,node->value);
    printf("%s",t1->an_type);
    printf(", ");
    print_function_type(func_node2);
    printf("\n");*/
    return;
  } else if (func_node1 && func_node2) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ",node->line, node->col,node->value);
    print_function_type(func_node1);
    printf(", ");
    print_function_type(func_node2);
    printf("\n");*/
    return;
  }

  if (first_undef && !second_undef) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ", node->line, node->col,node->value);
    printf("undef");
    printf(", ");
    printf("%s\n",t2->an_type);*/
  } else if (!first_undef && second_undef) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ", node->line, node->col,node->value);
    printf("%s",t1->an_type);
    printf(", ");
    printf("undef");
    printf("\n");*/
    return;
  } else if (first_undef && second_undef) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ", node->line, node->col,node->value);
    printf("undef");
    printf(", ");
    printf("undef");
    printf("\n");*/

    return;
  }

  childs = n_childs(node);
  for (i = 0; i < childs; i++) {
    t3 = return_tree_node(node,i);
    if (strcmp(t3->an_type,"UNKNOWN")!=0) {
      strcpy(node->an_type,t3->an_type);
    }
  }
}

void parse_mul_div(tree_node *node, sym_table *st, char function_name[MAX_STR]){
  tree_node *t1,*t2;
  t1 = return_tree_node(node,0);
  t2 = return_tree_node(node,1);
  sym_table *func_node1 = is_function(st,t1, function_name);
  sym_table *func_node2 = is_function(st,t2, function_name);
  if (func_node1 && !func_node2) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ", node->line, node->col, node->value);
    print_function_type(func_node1);
    printf(", ");
    printf("%s\n",t2->an_type);
    strcpy(node->an_type,"int");*/
    return;
  } else if (!func_node1 && func_node2) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ", node->line, node->col, node->value);
    printf("%s",t1->an_type);
    printf(", ");
    print_function_type(func_node2);
    printf("\n");
    strcpy(node->an_type,"int");*/
    return;
  } else if (func_node1 && func_node2) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ", node->line, node->col, node->value);
    print_function_type(func_node1);
    printf(", ");
    print_function_type(func_node2);
    printf("\n");
    strcpy(node->an_type,"int");*/
    return;
  }

  if (strcmp(t1->an_type,"void")==0 || strcmp(t2->an_type,"void")==0) { // first is void or second is void
    ////operator_applied2(node, t1, t2);
  } else {
    if(strcmp(t1->an_type,"double")==0 || strcmp(t2->an_type,"double")==0){
          strcpy(node->an_type,"double");
    }
    else if((strcmp(t1->an_type,"short")==0 && strcmp(t2->an_type,"char")==0) ||
        (strcmp(t1->an_type,"char")==0 && strcmp(t2->an_type,"short")==0)){
          strcpy(node->an_type,"short");
    }
    else if(strcmp(t1->an_type,t2->an_type)==0){
      strcpy(node->an_type,t1->an_type);
    }
    else{
        strcpy(node->an_type,"int");
    }
  }
  if(strcmp(t1->an_type,"undef")==0 || strcmp(t2->an_type,"undef")==0){
    strcpy(node->an_type,"undef");
  }
}

void parse_mod(tree_node *node, sym_table *st, char function_name[MAX_STR]){
  tree_node *t1,*t2;
  t1 = return_tree_node(node,0);
  t2 = return_tree_node(node,1);
  sym_table *func_node1 = is_function(st,t1, function_name);
  sym_table *func_node2 = is_function(st,t2, function_name);
  if (func_node1 && !func_node2) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ", node->line, node->col, node->value);
    print_function_type(func_node1);
    printf(", ");
    printf("%s\n",t2->an_type);
    strcpy(node->an_type,"int");*/
    return;
  } else if (!func_node1 && func_node2) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ", node->line, node->col, node->value);
    printf("%s",t1->an_type);
    printf(", ");
    print_function_type(func_node2);
    printf("\n");
    strcpy(node->an_type,"int");*/
    return;
  } else if (func_node1 && func_node2) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ", node->line, node->col, node->value);
    print_function_type(func_node1);
    printf(", ");
    print_function_type(func_node2);
    printf("\n");
    strcpy(node->an_type,"int");*/
    return;
  }

  if (strcmp(t1->an_type,"void")==0 || strcmp(t2->an_type,"void")==0) { // first is void or second is void
    ////operator_applied2(node, t1, t2);
  }else if((strcmp(t1->an_type,"int")==0 && strcmp(t2->an_type,"double")==0) ||
      (strcmp(t1->an_type,"double")==0 && strcmp(t2->an_type,"int")==0)){
        //operator_applied2(node,t1,t2);
        strcpy(node->an_type,"undef");
  }else if((strcmp(t1->an_type,"char")==0 && strcmp(t2->an_type,"double")==0) ||
      (strcmp(t1->an_type,"double")==0 && strcmp(t2->an_type,"char")==0)){
        //operator_applied2(node,t1,t2);
        strcpy(node->an_type,"undef");
  }
  else if((strcmp(t1->an_type,"double")==0 && strcmp(t2->an_type,"short")==0) ||
      (strcmp(t1->an_type,"short")==0 && strcmp(t2->an_type,"double")==0)){
        //operator_applied2(node,t1,t2);
        strcpy(node->an_type,"undef");
  }
  else if(strcmp(t1->an_type,"double")==0 && strcmp(t2->an_type,"double")==0){
        //operator_applied2(node,t1,t2);
        strcpy(node->an_type,"undef");
  }
  else {
    /*if(strcmp(t1->an_type,"double")==0 || strcmp(t2->an_type,"double")==0){
          strcpy(node->an_type,"double");
    }
    else if((strcmp(t1->an_type,"short")==0 && strcmp(t2->an_type,"char")==0) ||
        (strcmp(t1->an_type,"char")==0 && strcmp(t2->an_type,"short")==0)){
          strcpy(node->an_type,"short");
    }
    else if(strcmp(t1->an_type,t2->an_type)==0){
      strcpy(node->an_type,t1->an_type);
    }
    else{
        strcpy(node->an_type,"int");
    }*/
    strcpy(node->an_type,"int");
  }

  if(strcmp(t1->an_type,"undef")==0 || strcmp(t2->an_type,"undef")==0){
    strcpy(node->an_type,"undef");
  }


}


void parse_eq_ne(tree_node *node, sym_table *st, char function_name[MAX_STR]){
  tree_node *t1,*t2;
  t1 = return_tree_node(node,0);
  t2 = return_tree_node(node,1);
  sym_table *func_node1 = is_function(st, t1, function_name);
  sym_table *func_node2 = is_function(st, t2, function_name);

  if (func_node1 && !func_node2) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ", node->line, node->col, node->value);
    print_function_type(func_node1);
    printf(", ");
    printf("%s\n",t2->an_type);

    strcpy(node->an_type,"int");*/

    return;
  } else if (!func_node1 && func_node2) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ",node->line, node->col, node->value);
    printf("%s",t1->an_type);
    printf(", ");
    print_function_type(func_node2);
    printf("\n");*/

    strcpy(node->an_type,"int");

    return;
  } else if (func_node1 && func_node2) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ",node->line, node->col, node->value);
    print_function_type(func_node1);
    printf(", ");
    print_function_type(func_node2);
    printf("\n");
    strcpy(node->an_type,"int");*/
    return;
  }

  if (strcmp(t1->an_type,"void")==0 || strcmp(t2->an_type,"void")==0) { // first is void or second is void
    //operator_applied2(node, t1, t2);
    strcpy(node->an_type,"int");
  } else if (strcmp(t1->an_type,"undef")==0 || strcmp(t2->an_type,"undef")==0) {
    //operator_applied2(node, t1, t2);
    strcpy(node->an_type,"int");
  } else if (strcmp(t1->an_type,t2->an_type)!=0) {
    if ((strcmp(t1->an_type,"char")==0 && strcmp(t2->an_type,"int")==0) || (strcmp(t1->an_type,"int")==0 && strcmp(t2->an_type,"char")==0)) {

    } else {
        //operator_applied2(node, t1, t2); // here
        strcpy(node->an_type,"int");
    }
    strcpy(node->an_type,"int");
  } else if (strcmp(t1->an_type,t2->an_type)==0) {
    strcpy(node->an_type,"int");
  } else{
    strcpy(node->an_type,"int");
  }
}

void parse_and_or(tree_node *node, sym_table *st, char function_name[MAX_STR]){
  tree_node *t1,*t2;
  t1 = return_tree_node(node,0);
  t2 = return_tree_node(node,1);
  sym_table *func_node1 = is_function(st, t1, function_name);
  sym_table *func_node2 = is_function(st, t2, function_name);

  strcpy(node->an_type,"int");


  int first_void = strcmp(t1->an_type,"void")==0 && func_node1 == NULL;
  int second_void = strcmp(t1->an_type,"void")==0 && func_node2 == NULL;

  if (first_void && second_void) {
    //printf("Line %d, col %d: Operator %s cannot be applied to types void, void\n", node->line, node->col, node->value);
    return;
  } else if (first_void && !second_void) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types void, ", node->line, node->col, node->value);

    if (func_node2 != NULL) {
      print_function_type(func_node2);
    } else {
      printf("%s",t2->an_type);
    }

    printf("\n");*/

    return;
  } else if (!first_void && second_void) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ", node->line, node->col, node->value);

    if (func_node1 != NULL) {
      print_function_type(func_node1);
    } else {
      printf("%s",t1->an_type);
    }

    printf(", void\n");*/
    return;

  }

  if (func_node1 && !func_node2) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ", node->line, node->col, node->value);
    print_function_type(func_node1);
    printf(", ");
    printf("%s\n",t2->an_type);
    printf("\n");

    strcpy(node->an_type,"int");;*/

    return;
  } else if (!func_node1 && func_node2) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ", node->line, node->col, node->value);
    printf("%s",t1->an_type);
    printf(", ");
    print_function_type(func_node2);
    printf("\n");

    strcpy(node->an_type,"int");;*/

    return;
  } else if (func_node1 && func_node2) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ",node->line, node->col, node->value);
    print_function_type(func_node1);
    printf(", ");
    print_function_type(func_node2);
    printf("\n");

    strcpy(node->an_type,"int");;*/

    return;
  }

  int first_undef = (strcmp(t1->an_type,"undef")==0) ? 1 : 0;
  int second_undef = (strcmp(t2->an_type,"undef")==0) ? 1 : 0;

  if (first_undef && !second_undef) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ", node->line, node->col, node->value);
    printf("undef");
    printf(", ");
    printf("%s\n",t2->an_type);*/
  } else if (!first_undef && second_undef) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ",node->line, node->col, node->value);
    printf("%s",t1->an_type);
    printf(", ");
    printf("undef");
    printf("\n");*/

    return;
  } else if (first_undef && second_undef) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ",node->line, node->col, node->value);
    printf("undef");
    printf(", ");
    printf("undef");
    printf("\n");*/

    return;
  }

  strcpy(node->an_type,"int");
}

void parse_ge_le_lt_gt(tree_node *node, sym_table *st, char function_name[MAX_STR]){
  tree_node *t1,*t2;
  t1 = return_tree_node(node,0);
  t2 = return_tree_node(node,1);
  sym_table *func_node1 = is_function(st, t1, function_name);
  sym_table *func_node2 = is_function(st, t2, function_name);

  if (func_node1 && !func_node2) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ", node->line, node->col, node->value);
    print_function_type(func_node1);
    printf(", ");
    printf("%s\n",t2->an_type);

    strcpy(node->an_type,"int");*/

    return;
  } else if (!func_node1 && func_node2) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ", node->line, node->col, node->value);
    printf("%s",t1->an_type);
    printf(", ");
    print_function_type(func_node2);
    printf("\n");

    strcpy(node->an_type,"int");*/

    return;
  } else if (func_node1 && func_node2) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ", node->line, node->col, node->value);
    print_function_type(func_node1);
    printf(", ");
    print_function_type(func_node2);
    printf("\n");

    strcpy(node->an_type,"int");*/

    return;
  }

  if (strcmp(t1->an_type,"void")==0 || strcmp(t2->an_type,"void")==0) { // first is void or second is void
    //operator_applied2(node, t1, t2);
    strcpy(node->an_type,"int");
  } else if (strcmp(t1->an_type,"undef")==0 || strcmp(t2->an_type,"undef")==0) {
    //operator_applied2(node, t1, t2);
    strcpy(node->an_type,"int");
  } else if (strcmp(t1->an_type,t2->an_type)!=0) {
    if ((strcmp(t1->an_type,"char")==0 && strcmp(t2->an_type,"int")==0) || (strcmp(t1->an_type,"int")==0 && strcmp(t2->an_type,"char")==0)) {

    } else {
        //operator_applied2(node, t1, t2); // here
        strcpy(node->an_type,"int");
    }
    strcpy(node->an_type,"int");
  } else if (strcmp(t1->an_type,t2->an_type)==0) {
    strcpy(node->an_type,"int");
  } else{
    strcpy(node->an_type,"int");
  }
}

void parse_plus_minus(tree_node *node, sym_table *st, char function_name[MAX_STR]){
  tree_node *t1;
  t1 = return_tree_node(node,0);
  sym_table *func_node = is_function(st, t1, function_name);

  strcpy(node->an_type,"int");

  if (strcmp(t1->an_type,"undef")==0) {
    //operator_applied1(node, t1);
    strcpy(node->an_type,"int");
    return;
  }

  if (func_node != NULL) {
    //operator_applied1_function(node, func_node);
    strcpy(node->an_type,"int");
    return;
  }

  if (strcmp(t1->an_type,"void")==0) {
    //operator_applied1(node, t1);
  } else {
    strcpy(node->an_type,t1->an_type);
  }
}

void parse_bitwise_and_or_xor(tree_node *node, sym_table *st, char function_name[MAX_STR]){
  tree_node *t1,*t2;
  t1 = return_tree_node(node,0);
  t2 = return_tree_node(node,1);
  sym_table *func_node1 = is_function(st, t1, function_name);
  sym_table *func_node2 = is_function(st, t2, function_name);

  strcpy(node->an_type,"int");


  int first_void = strcmp(t1->an_type,"void")==0 && func_node1 == NULL;
  int second_void = strcmp(t1->an_type,"void")==0 && func_node2 == NULL;

  if (first_void && second_void) {
    //printf("Line %d, col %d: Operator %s cannot be applied to types void, void\n", node->line, node->col, node->value);
    return;
  } else if (first_void && !second_void) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types void, ", node->line, node->col, node->value);

    if (func_node2 != NULL) {
      print_function_type(func_node2);
    } else {
      printf("%s",t2->an_type);
    }

    printf("\n");*/

    return;
  } else if (!first_void && second_void) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ", node->line, node->col, node->value);

    if (func_node1 != NULL) {
      print_function_type(func_node1);
    } else {
      printf("%s",t1->an_type);
    }

    printf(", void\n");*/
    return;
  }

  if (func_node1 && !func_node2) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ", node->line, node->col, node->value);
    print_function_type(func_node1);
    printf(", ");
    printf("%s\n",t2->an_type);
    printf("\n");

    strcpy(node->an_type,"int");;*/

    return;
  } else if (!func_node1 && func_node2) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ", node->line, node->col, node->value);
    printf("%s",t1->an_type);
    printf(", ");
    print_function_type(func_node2);
    printf("\n");

    strcpy(node->an_type,"int");;*/

    return;
  } else if (func_node1 && func_node2) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ",node->line, node->col, node->value);
    print_function_type(func_node1);
    printf(", ");
    print_function_type(func_node2);
    printf("\n");

    strcpy(node->an_type,"int");;*/

    return;
  }

  int first_undef = (strcmp(t1->an_type,"undef")==0) ? 1 : 0;
  int second_undef = (strcmp(t2->an_type,"undef")==0) ? 1 : 0;

  if (first_undef && !second_undef) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ", node->line, node->col, node->value);
    printf("undef");
    printf(", ");
    printf("%s\n",t2->an_type);*/
  } else if (!first_undef && second_undef) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ",node->line, node->col, node->value);
    printf("%s",t1->an_type);
    printf(", ");
    printf("undef");
    printf("\n");*/

    return;
  } else if (first_undef && second_undef) {
    /*printf("Line %d, col %d: Operator %s cannot be applied to types ",node->line, node->col, node->value);
    printf("undef");
    printf(", ");
    printf("undef");
    printf("\n");*/

    return;
  }

  strcpy(node->an_type,"int");
}


void parse_not(tree_node *node, sym_table *st, char function_name[MAX_STR]){
  tree_node *t1 = return_tree_node(node,0);
  sym_table *func_node = is_function(st, t1, function_name);

  strcpy(node->an_type,"int");

  if (strcmp(t1->an_type,"undef")==0) {
    strcpy(node->an_type,"int");
    //operator_applied1(node, t1);
    return;
  }

  if (func_node != NULL) {
    //operator_applied1_function(node, func_node);
    strcpy(node->an_type,"int");
    return;
  }

  if (strcmp(t1->an_type,"void")==0) {
    //operator_applied1(node, t1);
    strcpy(node->an_type,"int");
  } else {
    strcpy(node->an_type,"int");
  }
}

void parse_store(tree_node *node, sym_table *st, char function_name[MAX_STR]){
  tree_node *t1,*t2;
  t1 = return_tree_node(node,0);
  t2 = return_tree_node(node,1);
  sym_table *func_node = is_function(st, t2, function_name);

  int id_found = strcmp(t1->name,"Id")==0 ? 1 : 0;

  strcpy(node->an_type,t1->an_type);

  if (!id_found) {
    printf("Line %d, col %d: Lvalue required\n", t1->line, t1->col);
    strcpy(node->an_type,t1->an_type);
    return;
  }

  if (func_node != NULL) {
    //printf("Line %d, col %d: Operator %s cannot be applied to types ", node->line, node->col, node->value);
    //print_node(t1);
    //printf(", ");
    //print_function_type(func_node);
    //printf("\n");

    return;
  }

  if (strcmp(t2->an_type,"void")==0) {
    //printf("Line %d, col %d: Operator %s cannot be applied to types ", node->line, node->col, node->value);
    //printf("%s",t1->an_type);
    //printf(", ");
    //printf("%s\n",t2->an_type);

    return;
  }

  // verify if node can be stored or not

  if (strcmp(t2->an_type,"undef")==0) {
    //printf("Line %d, col %d: Operator %s cannot be applied to types ", node->line, node->col, node->value);
    //printf("%s",t1->an_type);
    //printf(", ");
    //printf("%s\n",t2->an_type);
    return;
  }

  int error = 1;

  if ((strcmp(t1->an_type,"char")==0 && strcmp(t2->an_type,"int")==0) || (strcmp(t1->an_type,"int")==0 && strcmp(t2->an_type,"char")==0)) { // one is int, other is char
    error = 0;

  } else if (strcmp(t1->an_type,t2->an_type)==0) {
    error = 0;
  }

  if (error) {
    //printf("Line %d, col %d: Operator %s cannot be applied to types ", node->son->line, node->son->col, node->value);
    //printf("%s",t1->an_type);
    //printf(", ");
    //printf("%s\n",t2->an_type);
  } else {
    strcpy(node->an_type,t1->an_type);
  }
}

void parse_call(tree_node *node, sym_table *st, char function_name[MAX_STR],int is_anotated){
  tree_node *t1;
  t1 = return_tree_node(node,0);
  if (is_anotated) {
    set_function_type(st, node);
  }
  int args_sent_in = n_childs(node) - 1;

  int expected_args;

  sym_table *cur_st_node = st;

  while (cur_st_node != NULL) {
    if (!strcmp(cur_st_node->id, t1->value)) {
      expected_args = cur_st_node->n_params;

      if (expected_args == 1) {
        if (strcmp(cur_st_node->params[0]->type,"void")==0) {
          expected_args = 0;
        }
      }
      break;
    }
    cur_st_node = cur_st_node->next;
  }

  if (cur_st_node == NULL) {
    printf("Line %d, col %d: Symbol %s is not a function\n", node->line, node->col, t1->value);
    return;
  }

  if (args_sent_in != expected_args) {
    printf("Line %d, col %d: Wrong number of arguments to function %s (got %d, required %d)\n", node->line, node->col, t1->value, args_sent_in, expected_args);
    return;
  }

  int i;
  for (i = 0; i < args_sent_in && i < expected_args; i++) {
    tree_node *t2 = return_tree_node(node,i+1);

    sym_table *func_node = is_function(st, t2, function_name);

    if (func_node != NULL) {
      printf("Line %d, col %d: Conflicting types (got ", t2->line, t2->col);
      print_function_type(func_node);
      printf(", expected ");
      printf("%s)\n",cur_st_node->params[i]->type);
      continue;
    }
  }
}

void parse_if(tree_node *node, sym_table *st, char function_name[MAX_STR]){
  tree_node *t1 = return_tree_node(node,0);
  sym_table *func_node = is_function(st, t1, function_name);

  if (func_node != NULL) {

    printf("Line %d, col %d: Conflicting types (got ", t1->line, t1->col);
    print_function_type(func_node);
    printf(", expected int)\n");
    return;
  }

  if (strcmp(t1->an_type,"undef")==0) {
    printf("Line %d, col %d: Conflicting types (got undef, expected int)\n", t1->line, t1->col);
  }

  if (strcmp(t1->an_type,"void")==0) {
    printf("Line %d, col %d: Conflicting types (got void, expected int)\n", t1->line, t1->col);
  }
}

void parse_while(tree_node *node, sym_table *st, char function_name[MAX_STR]){
  tree_node *t1 = return_tree_node(node,0);
  sym_table *func_node = is_function(st, t1, function_name);

  if (func_node != NULL) {

    printf("Line %d, col %d: Conflicting types (got ", t1->line, t1->col);
    print_function_type(func_node);
    printf(", expected int)\n");
    return;
  }

  if (strcmp(t1->an_type,"undef")==0) {
    printf("Line %d, col %d: Conflicting types (got undef, expected int)\n", t1->line, t1->col);
  }

  if (strcmp(t1->an_type,"void")==0) {
    printf("Line %d, col %d: Conflicting types (got void, expected int)\n", t1->line, t1->col);
  }
}

void semantics(tree_node *node, sym_table *st, char function_name[MAX_STR], int is_anotated,int error){
  int i=0,childs = 0;
  tree_node *t1 = NULL;
  if(strcmp(node->name,"FuncDeclaration")==0){
    is_anotated = 0;
  }
  if(strcmp(node->name,"FuncDefinition")==0){
    //check if function definition has errors
    error = parse_func_definition(st,node);
    t1 = return_tree_node(node,1);
    function_name = (char *) strdup(t1->value);
    childs = n_childs(node);
    for(i=0;i<childs;i++){
      t1 = return_tree_node(node,i);
      if(strcmp(t1->name,"FuncBody")==0){
        semantics(t1,st,function_name,is_anotated,error);
      }
    }
  }
  else{
    childs = n_childs(node);
    for(i=0;i<childs;i++){
      t1 = return_tree_node(node,i);
      semantics(t1,st,function_name,is_anotated,error);
    }
  }
  if(strcmp(node->name,"Return")==0){
    parse_return_node(st,node,function_name);
  }
  else if(strcmp(node->name,"Declaration")==0){
    is_anotated = 0;
    if(!error){
      parse_declaration(st,node,function_name);
    }
  }
  else if(strcmp(node->name,"FuncDeclaration")==0){
    parse_func_declaration(st,node,function_name);
  }
  else if(strcmp(node->name,"IntLit")==0 || strcmp(node->name,"ChrLit")==0){
    if(node->father!= NULL){
      if(strcmp(node->father->name,"Declaration")==0){
        strcpy(node->an_type,"int");
      }
    }
    if(is_anotated == 1){
      strcpy(node->an_type,"int");
    }
  }
  else if(strcmp(node->name,"RealLit")==0){
    if(strcmp(node->father->name,"Declaration")==0){
      strcpy(node->an_type,"double");
    }
    if(is_anotated == 1){
      strcpy(node->an_type,"double");
    }
  }
  else if(strcmp(node->name,"Id")==0){
    if(node->father!=NULL){
      if(strcmp(node->father->name,"Declaration")==0){
        is_anotated = 0;
        parse_id(node,st,function_name,is_anotated);
      }
      else{
        parse_id(node,st,function_name,is_anotated);
      }
    }
    else{
      parse_id(node,st,function_name,is_anotated);
    }
  }
  else if(strcmp(node->name,"Add")==0){
    parse_add(node,st,function_name);
  }
  else if(strcmp(node->name,"Sub")==0){
    parse_sub(node,st,function_name);
  }
  else if(strcmp(node->name,"Comma")==0){
    parse_comma(node,st,function_name);
  }
  else if(strcmp(node->name,"Mul")==0 || strcmp(node->name,"Div")==0){
    parse_mul_div(node,st,function_name);
  }
  else if(strcmp(node->name,"Mod")==0){
    parse_mod(node,st,function_name);
  }
  else if(strcmp(node->name,"Eq")==0 || strcmp(node->name,"Ne")==0){
    parse_eq_ne(node,st,function_name);
  }
  else if(strcmp(node->name,"And")==0 || strcmp(node->name,"Or")==0){
    parse_and_or(node,st,function_name);
  }
  else if(strcmp(node->name,"Ge")==0 || strcmp(node->name,"Gt")==0 || strcmp(node->name,"Le")==0 || strcmp(node->name,"Lt")==0){
    parse_ge_le_lt_gt(node,st,function_name);
  }
  else if(strcmp(node->name,"Minus")==0 || strcmp(node->name,"Plus")==0){
    parse_plus_minus(node,st,function_name);
  }
  else if(strcmp(node->name,"Not")==0){
    parse_not(node,st,function_name);
  }
  else if(strcmp(node->name,"BitWiseAnd")==0 || strcmp(node->name,"BitWiseOr")==0  || strcmp(node->name,"BitWiseXor")==0){
    parse_bitwise_and_or_xor(node,st,function_name);
  }
  else if(strcmp(node->name,"Store")==0){
    parse_store(node,st,function_name);
  }
  else if(strcmp(node->name,"Call")==0){
    if(node->father!=NULL){
      if(strcmp(node->father->name,"Declaration")==0){
        is_anotated = 1;
      }
    }
    parse_call(node,st,function_name,is_anotated);
  }
  else if(strcmp(node->name,"If")==0){
    parse_if(node,st,function_name);
  }
  else if(strcmp(node->name,"While")==0){
    parse_while(node,st,function_name);
  }

  if(strcmp(node->name,"Program")==0 || strcmp(node->name,"Null")==0 || strcmp(node->name,"FuncDefinition")==0 || strcmp(node->name,"FuncBody")==0 || strcmp(node->name,"While")==0 ||
  strcmp(node->name,"Return")==0 || strcmp(node->name,"StatList")==0 || strcmp(node->name,"If")==0){
    return;
  }

  if(strcmp(node->an_type,"UNKNOWN")==0 && is_anotated){
    strcpy(node->an_type,"undef");
  }
}
