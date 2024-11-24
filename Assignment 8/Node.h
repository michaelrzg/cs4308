// Michael Rizig
// Term: Fall 2024
// Instructor: Gayler
// Assignment 8
// File: Node.h
// 11/24/24
//  this file contains the tree Node header

#ifndef Node_H
#define Node_H
#include "ValuePair.h"
typedef struct Node{
    struct Node* left;
    struct Node* right;
    struct ValuePair data;
} Node;

#endif