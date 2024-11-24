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
bool insert(BST* tree, int data){
    // check if tree is null
    if(tree == NULL){
        return false;
    }
    // check if tree is empty
    if(tree->head == NULL){
        printf("UPDATE: Tree is empty! Creating new head..");
        // create new head
        tree->head = (Node*)malloc(sizeof(Node));
        // check if malloc worked to avoid bus error
        if (tree->head == NULL){
            printf("memory allocation failed");
            return false;
        }
        // create new valuepair to go into tree.
        ValuePair pair;
        pair.count = 1;
        pair.value = data;
        // assign new value to head
        tree->head->data = pair;
        tree->head->left = NULL;
        tree->head->right = NULL;
        // print update
        printf("\nUPDATE: New head created. Value: %d, Count: %d",tree->head->data.value,tree->head->data.count);
        // end
        return true;
    }
    // else tree is not empty, find place for new value
    else{
        Node* current = tree->head;
        Node* prev = current;
        while(current != NULL){
            if(current->data.value > data){
                prev=current;
                current = current->left;
            }
            else if (current->data.value < data){
                prev=current;
                current = current->right;
            }
            else if (current->data.value == data){
                current->data.count++;
                printf("\nUPDATE: %d already exists in tree, new count: %d",current->data.value,current->data.count);
                return false;
            }
        }
        // create new valuepair to go into tree.
        ValuePair pair;
        pair.count = 1;
        pair.value = data;
        if(prev->data.value < data){
            // insert right
            prev->right = (Node*)malloc(sizeof(Node));
            prev->right->data = pair;
            prev->right->left = NULL;
            prev->right->right=NULL;
        }
        else{
            //insert left
            prev->left = (Node*)malloc(sizeof(Node));
            prev->left->data = pair;
            prev->left->left = NULL;
            prev->left->right=NULL;  
        }
            //update
            printf("\nUPDATE: Node inserted. Value: %d",data);
             //end
            return true;
    }

}

void inorder(BST* tree){
    
}

