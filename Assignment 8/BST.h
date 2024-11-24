// Michael Rizig
// Term: Fall 2024
// Instructor: Gayler
// Assignment 8
// File: BST.h
// 11/24/24
//  this file contains the Binary Search Tree header

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