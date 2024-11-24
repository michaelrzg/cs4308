// header file for BST
// Michael Rizig
// CS4308 Gayler
// Assignment 7

#ifndef BST_H 
#define BST_H

#include "Node.h"
#include "ValuePair.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct BST{
    Node* head;
} BST;
bool insert(BST* tree, char* data);
void inorder(BST* tree);
void inorder_helper(Node* n);
#endif