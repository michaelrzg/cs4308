
#include "BST.c"
#include "ValuePair.h"
int main(){
    BST tree = {NULL};
    ValuePair pair;
    pair.count = 1;
    pair.data = 5;

    insert(&tree,pair);
}