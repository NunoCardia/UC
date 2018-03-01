#include <stdlib.h>
#include "ast.h"

tree_node* create_simple_node(char* name) {
    tree_node* new_node = (tree_node*) malloc( sizeof(tree_node) );

    if (new_node != NULL) {
        strcpy(new_node->name, name);
        new_node->next_brother = NULL;
        new_node->son = NULL;
        new_node->father = NULL;
    } else {
        printf("ERROR SIMPLE NODE\n");
    }

    return new_node;
}

tree_node* create_value_node(char* name, char* value) {
    tree_node* new_node = (tree_node*)malloc(sizeof(tree_node));

    if(new_node != NULL) {
        strcpy(new_node->name, name);
        new_node->next_brother = NULL;
        new_node->son = NULL;
        new_node->father = NULL;

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

void add_brother_end(tree_node* brother, tree_node* new_son) {
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
    printf("%s(%s)\n", node->name, node->value);
}

void print_points(int n){
    while(n > 0){
        printf("..");
        n--;
    }
}

void print_tree(tree_node* node, int level){
    if(node != NULL) {
        print_points(level);

        if(strcmp(node->name, "Id") == 0 || strcmp(node->name, "Chrlit") == 0 || strcmp(node->name, "Reallit") == 0 || strcmp(node->name, "Intlit") == 0){
            print_terminal(node);
        } else {
            printf("%s\n", node->name);
        }

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
