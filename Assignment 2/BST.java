
// Term: Fall 2024
// Instructor: Gayler
// Assignment 2
// File: BST
// 9/4/24
// this file contains the bst (mine not generic)
class BST<E extends Comparable<E>> {

    class Node {

        E data;
        Node left;
        Node right;
        Node parentNode;

        Node(E data) {
            this.data = data;
            left = null;
            right = null;
            parentNode = null;
        }
    }

    Node root;

    public boolean insert(E data) {
        // fastest case: if root is null (tree is empty), create tree with Node (data) as root
        if (root == null) {
            root = new Node(data);
            return true;
        }
        // pointer to iterate through the tree
        Node current = root;
        // pointer to remember parent
        Node parent = null;

        // keep track if value is already in tree to alert 
        boolean alreadyExists = false;
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
                break; //if it is neighter lower nor higher, it is equal, and tree does not accept duplicates
            }

        }

        // once we exit loop we have either:
        //1: found a leaf (current != null)
        //2: our data matched with a value so loop ended (alreadyExists = true )
        if (data.compareTo(parent.data) < 0) {
            parent.left = new Node(data);
        } else if (data.compareTo(parent.data) > 0) {
            parent.right = new Node(data);
        } else {
            System.err.println("Key \'" + data + "\' already inserted into tree. Ignoring.");
            return false;
        }
        System.out.println("Node \'" + data + "\' inserted into the tree. Parent node: \'" + parent.data + "\'");
        return true;

    }

    //print tree in order
    public String LVR_Inorder() {
        // Place to Store output
        StringBuilder output = new StringBuilder();
        //call helper function 
        output.append("$");
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
        output.append(" > ");
        // recurse right (R)
        LVR(n.right, output);

    }

}
