
#ifndef Node_H
#define Node_H
#include "ValuePair.h"
typedef struct Node{
    struct Node* left;
    struct Node* right;
    struct ValuePair data;
} Node;

#endif