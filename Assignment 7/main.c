
#include "BST.c"
#include "ValuePair.h"
int main(){
    BST tree = {NULL};
    

    insert(&tree,"GELL");
    inorder(&tree);
    insert(&tree,"GELL");
    inorder(&tree);
    insert(&tree,"HELL");
    inorder(&tree);
    

}