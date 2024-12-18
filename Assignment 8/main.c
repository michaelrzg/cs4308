// Michael Rizig
// Term: Fall 2024
// Instructor: Gayler
// Assignment 8
// File: main.c
// 11/24/24
//  this file contains the driver for assignment 8

#include "BST.c"

#include <stdio.h>

int main(int argc, char *argv[]){
    FILE* file;
    // check if argument was passed
    if(argc==1){
        printf("Please give name of text file in as argument.\nEXAMPLE: wordcount example.txt");
        return 1;
    }
    // check if file is readable
    else{
        printf("\nOpening File %s",argv[1]);
        file = fopen(argv[1],"r");
        if(file == NULL){
            printf("ERROR: Could not find file or file is not readable.");
            return 1;
        }
    }
    // create tree
    BST tree = {NULL};
    
    // parse each word in the file into the tree
    char word[256];
     while (fscanf(file, "%255s", word) == 1) {
        insert(&tree,word); 
   }
    // print tree
    inorder(&tree);

    return 0;
    
    

}