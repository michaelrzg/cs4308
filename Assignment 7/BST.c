// source file for BST
// Michael Rizig
// CS4308 Gayler
// Assignment 7

// include the header file for this src
#include "BST.h"
#include "Node.h"
// include boolean header to use bools
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// insert a node into the tree
bool insert(BST* tree, ValuePair data){
    // check if tree is null
    if(tree == NULL){
        return false;
    }
    // check if tree is empty
    if(tree->head == NULL){
        printf("Tree is empty! Creating new Head..");
        // create new head
        tree->head = (Node*)malloc(sizeof(Node));
        // check if malloc worked to avoid bus error
        if (tree->head == NULL){
            printf("memory allocation failed");
            return false;
        }
        // assign new value to head
        tree->head->data = data;
        tree->head->left = NULL;
        tree->head->right = NULL;
        // end
        return true;
    }

}
