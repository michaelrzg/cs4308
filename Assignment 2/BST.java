
// Term: Fall 2024
// Instructor: Gayler
// Assignment 2
// File: BST
// 9/4/24
// this file contains the bst (mine not generic)
class BST<E extends Comparable<E>> {

    // node object that will hold 3 pointers:
    // left, right, and parent
    // also holds data (String) and count (occurences of that string)
    class Node {

        E data;
        Node left;
        Node right;
        Node parentNode;
        int count;

        Node(E data) {
            this.data = data;
            left = null;
            right = null;
            parentNode = null;
            count = 1;
        }
    }

    Node root;

    public boolean insert(E data) {
        // fastest case: if root is null (tree is empty), create tree with Node (data) as root
        if (root == null) {
            root = new Node(data);
            System.out.println("Node \'" + data + "\' inserted into the tree as ROOT. Count: 1");
            return true;
        }
        // pointer to iterate through the tree
        Node current = root;
        // pointer to remember parent
        Node parent = null;

        boolean duplicate = false;
        //keep track of curernt nodes count value for printng later
        int localCount = 0;
        //use pointer to move through the tree
        while (current != null) {
            // if data is less than current pouinter, we move left and store parent
            if (current.data.compareTo(data) > 0) {
                parent = current;
                current = current.left;

            } //else we move right, store parent
            else if (current.data.compareTo(data) < 0) {
                parent = current;
                current = current.right;
            } else {
                //if it is neighter lower nor higher, it is equal, so we increase the counter
                localCount = ++current.count;
                System.err.println("Key \'" + data + "\' already inserted into tree. Count increased from " + (localCount - 1) + " to " + localCount);
                return true;

            }

        }

        // if we make it here, we have a novel element and need to insert it as leaf
        if (data.compareTo(parent.data) < 0) {
            parent.left = new Node(data);
            parent.left.parentNode =parent;
            localCount = 1;
        } else if (data.compareTo(parent.data) > 0) {
            parent.right = new Node(data);
            parent.right.parentNode =parent;
            localCount = 1;
        }
        System.out.println("Node \'" + data + "\' inserted into the tree. Parent node: \'" + parent.data + "\' Count: " + localCount);
        return true;

    }

    //print tree in order
    public String LVR_Inorder() {
        // Place to Store output
        StringBuilder output = new StringBuilder();
        //call helper function 
        output.append("$ > ");
        LVR(root, output);
        output.append("$");
        return output.toString();
    }

    

    // recursive helper method to traverse tree
    private void LVR(Node n, StringBuilder output) {
        //base case
        if (n == null) {
            return;
        }
        // recurse left (L)
        LVR(n.left, output);
        // process this node (V)
        output.append(n.data);
        output.append("(" + n.count + ")  > ");
        // recurse right (R)
        LVR(n.right, output);

    }

}
