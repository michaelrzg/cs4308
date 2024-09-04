// Name: Michael Rizig
// Class: CS 4308/W01
// Term: Fall 2024
// Instructor: Gayler
// Assignment 2
// File: driver

class driver {

    public static void main(String[] args) {
        BST<String> tree = new BST<>();
        tree.insert("h");
        tree.insert("b");
        tree.insert("z");
        //tree.insert("hi");
        System.out.println(tree.LVR_Inorder());

    }
}
