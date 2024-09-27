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
    # constructor for BST
    def __init__(self) -> None:
        self.root=None
    
    # insert into BST
    def insert(self, data) -> bool:
        # if root = Null, create root with data
        if self.root==None:
            self.root = self.Node(data)
            return True
        else:
            # else create pointer to root and traverse
            current = self.root
            while current!=None:
                if data == current.data:
                    print("Data already inserted into tree!")
                    return False
                #traverse right if new data > current nodes data
                if data > current.data:
                    # if right node does not exist, create it with data and escape
                    if current.right == None:
                        current.right = self.Node(data)
                        return True
                    else:
                    # else move right and continue loop
                        current=current.right
                
                #traverse left if new data > current nodes data                   
                elif data< current.data:
                    # if left does not exist, create
                    if current.left == None:
                        current.left = self.Node(data)
                        return True
                    else:
                        current = current.left
            current = self.Node(data)
            return True
        

    def LVR(self) -> None:
        output = []
        self.LVR_Traverse(self.root, output)
        print(output)
    
    def LVR_Traverse(self,currentNode,output):
        if currentNode == None:
            return
        self.LVR_Traverse(currentNode.left,output)
        output.append(currentNode.data)
        self.LVR_Traverse(currentNode.right,output)
        




