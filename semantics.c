#include "semantics.h"

void parse_return_node(sym_table *st,tree_node *node, char function_name[MAX_STR]){
  char type[MAX_STR];
  sym_table *return_st = st;
  while (return_st != NULL) {
    if(strcmp(return_st->id,function_name)==0){
      strcpy(type,return_st->type);
      break;
    }
    return_st = return_st->next;
  }
  //check if the child is a function and if there is an override of which->node->value inside function called "function_name"
}

void semantics(tree_node *node, sym_table *st, char function_name[MAX_STR], int is_anotated,int error){
  int i=0,childs = 0;
  if(strcmp(node->name,"FuncDeclaration")==0 || strcmp(node->name,"Declaration")==0){
    is_anotated = 0;
  }
  if(strcmp(node->name,"FuncDefinition")==0){
    //check if function definition has errors
    error = parse_func_definition(st,node);
    tree_node *t1 = return_tree_node(node,1);
    strcpy(function_name,t1->name);
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
    if(error == 0){
      parse_declaration(st,node,function_name);
    }
  }
  else if(strcmp(node->name,"FuncDeclaration")==0){
    parse_func_declaration(st,node,function_name);
  }
  else if(strcmp(node->name,"IntLit")==0 || strcmp(node->name,"ChrLit")==0){
    if(is_anotated == 1){
      strcpy(node->an_type,"int");
    }
  }
  else if(strcmp(node->name,"RealLit")==0){
    if(is_anotated == 1){
      strcpy(node->an_type,"double"); //????? ask prof se aparecer um RealLit como é que fica na an_tree
    }
  }
  else if(strcmp(node->name,"Id")==0){
    parse_id(node,st,function_name,is_anotated);
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
  else if(strcmp(node->name,"Mul")==0 || strcmp(node->name,"Div")==0 || strcmp(node->name,"Mod")==0){
    parse_mul_div_mod(node,st,function_name);
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
  else if(strcmp(node->name,"BitWiseAnd")==0){
    parse_bitwise_and(node,st,function_name);
  }
  else if(strcmp(node->name,"BitWiseOr")==0){
    parse_bitwise_or(node,st,function_name);
  }
  else if(strcmp(node->name,"BitWiseXor")==0){
    parse_bitwise_xor(node,st,function_name);
  }
  else if(strcmp(node->name,"Store")==0){
    parse_store(node,st,function_name);
  }
  else if(strcmp(node->name,"Call")==0){
    parse_call(node,st,function_name);
  }
  else if(strcmp(node->name,"If")==0){
    parse_if(node,st,function_name);
  }
  else if(strcmp(node->name,"While")==0){
    parse_while(node,st,function_name);
  }

  if(strcmp(node->name,"Program")==0 || strcmp(node->name,"Null")==0){
    return;
  }
}
