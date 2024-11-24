
#include "BST.c"
#include "ValuePair.h"
int main(){
    BST tree = {NULL};
    

    insert(&tree,5);
    inorder(&tree);
    insert(&tree,7);
    inorder(&tree);
    insert(&tree,1);
    inorder(&tree);
    insert(&tree,7);
    inorder(&tree);


}