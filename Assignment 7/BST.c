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

/**
 * @brief Inserts node into tree
 *
 * This function inserts node new or updates existing node.
 *
 * @param tree address of tree that the value is being inserted to
 * @param b string (char list) to be inserted
 * @return TRUE if inserted/updated, FALSE if error occurs.
 */
bool insert(BST* tree, char* data){
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
        pair.value = strdup(data);
        // assign new value to head
        tree->head->data = pair;
        tree->head->left = NULL;
        tree->head->right = NULL;
        // print update
        printf("\nUPDATE: New head created. Value: \'%s\', Count: %d",tree->head->data.value,tree->head->data.count);
        // end
        return true;
    }
    // else tree is not empty, find place for new value
    else{
        Node* current = tree->head;
        Node* prev = current;
        while(current != NULL){
            if(strcasecmp(current->data.value,data) <0){
                prev=current;
                current = current->left;
            }
            else if (strcasecmp(current->data.value,data) >0){
                prev=current;
                current = current->right;
            }
            else if (strcasecmp(current->data.value,data) ==0){
                current->data.count++;
                printf("\nUPDATE: \'%s\' already exists in tree, new count: %d",current->data.value,current->data.count);
                return false;
            }
        }
        // create new valuepair to go into tree.
        ValuePair pair;
        pair.count = 1;
        pair.value = strdup(data);
        if(strcasecmp(prev->data.value,data) >0){
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
            printf("\nUPDATE: Node inserted. Value: \'%s\'",data);
             //end
            return true;
    }

}
/**
 * @brief Prints inorder traversal of tree (LVR)
 *
 * @param tree Tree to be printed
 */
void inorder(BST* tree){
    printf("\n TREE:(word,count) \n");
    inorder_helper(tree->head);
    printf("\n");
}
/**
 * @brief Helper recursive function for inorder()
 *
 * @param tree current node
 */
void inorder_helper(Node* n){
    //base case
    if(n==NULL){
        return;
    }
    //recursive case
    else{
        inorder_helper(n->left);
        printf("(\'%s\',%d), ",n->data.value,n->data.count);
        inorder_helper(n->right);

    }
}

