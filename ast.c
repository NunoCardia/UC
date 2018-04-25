#include <stdlib.h>
#include "ast.h"

tree_node* create_simple_node(char* name,int line,int col) {

    tree_node* new_node = (tree_node*) malloc( sizeof(tree_node) );

    if (new_node != NULL) {
        strcpy(new_node->name, name);
        new_node->next_brother = NULL;
        new_node->son = NULL;
        new_node->father = NULL;
        new_node->line = line;
        new_node->col = col;
        new_node->an_params = NULL;
        new_node->an_n_params = 0;
        strcpy(new_node->an_type,"");
    } else {
        printf("ERROR SIMPLE NODE\n");
    }

    return new_node;
}

tree_node* create_value_node(char* name, char* value,int line,int col) {
    tree_node* new_node = (tree_node*)malloc(sizeof(tree_node));

    if(new_node != NULL) {
        strcpy(new_node->name, name);
        new_node->next_brother = NULL;
        new_node->son = NULL;
        new_node->father = NULL;
        new_node->line = line;
        new_node->col = col;
        new_node->an_params = NULL;
        new_node->an_n_params = 0;
        strcpy(new_node->an_type,"");
        strcpy(new_node->value, value);
    } else {
        printf("ERROR STR NODE\n");
    }

    return new_node;
}

void add_child(tree_node * father , tree_node * son){
    if(father->son != NULL) {
        son->next_brother = father->son;
        son->father = father;
        father->son = son;
    } else {
        son->father = father;
        father->son = son;
    }
}

void add_brother(tree_node* brother, tree_node* new_son) {
    tree_node* aux = brother;
    if(aux!= NULL && new_son != NULL) {
        while(aux->next_brother != NULL) {
            aux = aux->next_brother;
        }
        aux->next_brother = new_son;
        new_son->father = brother->father;
    }
}

/* PRINTING */
void print_terminal(tree_node* node){
    printf("%s(%s)\tline: %d\tcol: %d\n", node->name, node->value,node->line,node->col);
    //printf("%s(%s)\n", node->name, node->value);
}

void print_points(int n){
    while(n > 0){
        printf("..");
        n--;
    }
}

void print_node(tree_node *node){
  if(strcmp(node->name, "Id") == 0 || strcmp(node->name, "ChrLit") == 0 || strcmp(node->name, "RealLit") == 0 || strcmp(node->name, "IntLit") == 0){
      print_terminal(node);
  } else {
      //printf("%s\tline: %d\tcol: %d\n", node->name,node->line,node->col);
      printf("%s\n", node->name);
  }
}

void print_tree(tree_node* node, int level){
    if(node != NULL) {
        print_points(level);
        print_node(node);
        tree_node* child = node->son;

        if(child != NULL){
            print_tree(child, level + 1);

            while(child->next_brother != NULL){
                child = child->next_brother;
                print_tree(child, level + 1);
            }

        }
    }
}
