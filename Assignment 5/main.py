# Name: Michael Rizig
# Class: CS 4308/W01
# Term: Fall 2024
# Instructor: Gayler
# Assignment 5
# File: driver

# import sys to read cli arguments
import sys
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

# if we made it here, file is valid
# create list to store words 
words = []
# parse through file, adding each word to the list
for line in file:
    lineword= line.split(' ')
    for word in lineword:
        if len(word)>1:
            words.append(word.lower())
# simple loop to remove all \n new line characters
while True:
    # .remove returns None or raises Value Error (value paramater not found in list)
    # when we get value error, we have removed all \n from list
    try:
        words.remove("\n")
    except ValueError:
        break
        
# create binary tree
tree = BST.BST()
# insert words
for word in words:
    tree.insert(word)

# print tree and store its LVR traversal
output = tree.inorder()
