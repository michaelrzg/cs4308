# Name: Michael Rizig
# Class: CS 4308/W01
# Term: Fall 2024
# Instructor: Gayler
# Assignment 5
# File: driver

# import sys to read cli arguments
import sys
# import our BST class
import BST
# check if arguments were passed to interpreter
if (len(sys.argv) == 1):
    print("USAGE: python3 main.py [filepath]")
elif len(sys.argv)==2:
    # if we have args, try to open file in argv[1] 
    # (argv[0] = main.py)
    try:
        file = open(sys.argv[1],'r')
    except FileNotFoundError:
        # print error (in red) and end if correct path is not passed
        print("\033[31m", "ERROR: Unable to find file at path: " , sys.argv[1], "\n Please double check path and try again")
        sys.exit()

# if we made it here, path leads to valid file

# create binary tree
tree = BST.BST()

# parse through file, adding each word to the list
for line in file:
    # split line into array of the words seperated by spaces
    lineword= line.split(' ')
    for word in lineword:
        # remove any unwanted elements (empty strings, \n) and insert into tree 
        if len(word)>1 and word != "\n":
            word.replace("\n","")
            tree.insert(word.lower())
        
# run inorder traversal and store its LVR traversal
output = tree.inorder()
print("TREE: (word , count) \n$ ->  ", end= "")
for node in output:
    print(node[0], "\b," ,node[1], end=" ->  ")
print("$")
