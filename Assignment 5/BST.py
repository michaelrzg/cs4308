# Michael Rizig
# Term: Fall 2024
# Instructor: Gayler
# Assignment 5
# File: BST
# 9/27/24
# this file contains the Binary Search Tree in Python 
class BST:
    class Node:
        # Constructor for Node
        def __init__(self,data) -> None:
            self.data = data
            self.left=None
            self.right=None
            self.count=1
    # constructor for BST
    def __init__(self) -> None:
        self.root=None
    
    # insert into BST
    def insert(self, data):
        """
        Inserts a node into the binary tree. If node is already inserted, incriments count.

        :Param data -> Any
        """
        # if root = Null, create root with data
        if self.root==None:
            self.root = self.Node(data)
            return
        else:
            # else create pointer to root and traverse
            current = self.root
            while current!=None:
                if data == current.data:
                    current.count+=1
                    return
                #traverse right if new data > current nodes data
                if data > current.data:
                    # if right node does not exist, create it with data and escape
                    if current.right == None:
                        current.right = self.Node(data)
                        return
                    else:
                    # else move right and continue loop
                        current=current.right
                
                #traverse left if new data > current nodes data                   
                elif data< current.data:
                    # if left does not exist, create
                    if current.left == None:
                        current.left = self.Node(data)
                        return
                    else:
                        current = current.left
            current = self.Node(data)
            return
        
    
    def inorder(self):
        """ 
        In-Order Traversal of BST 

        Returns all nodes of BST in LVR Ordering as List

        List format: [ (word1,count1) , (word2,count2) ...] """
        output = []
        # pass root and output list to recursive LVR helper function
        self.LVR(self.root, output)
        # return tree traversal output as list of tuples (word, count) 
        return output
    
    # LVR recursive helper function 
    def LVR(self,currentNode,output):
        """
        Recursive Helper Function for self.inorder()
        """
        # base case
        if currentNode == None:
            return
        else:
            # recursive case
            # recurse left
            self.LVR(currentNode.left,output)
            # process
            output.append((currentNode.data, currentNode.count))
            # recurse right
            self.LVR(currentNode.right,output)
        




