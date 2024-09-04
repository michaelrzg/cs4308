// Name: Michael Rizig
// Class: CS 4308/W01
// Term: Fall 2024
// Instructor: Gayler
// Assignment 2
// File: driver

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

class driver {

    // function to test features of BST
    public static void testBST(BST<String> tree) {
        tree.insert("h");
        tree.insert("b");
        tree.insert("z");
        tree.insert("z");
        tree.insert("b");
        System.out.println(tree.LVR_Inorder());

    }

    // parse input file and return array of all strings.
    public static String[] parseFile(Scanner sc) {
        // making all lines into one long string
        // this is so we can later use .split() on entire string and get perfect sized array.
        StringBuilder sb = new StringBuilder();
        // while there are new lines in the file
        while (sc.hasNextLine()) {
            // grab line, remove punctuation
            String line = sc.nextLine();
            //format
            line = line.toUpperCase();
            line = line.replace(".", "");
            // add line to our long string
            sb.append(line);
        }
        // finally convert to array for easy parsing and return
        String[] output = sb.toString().split(" ");
        return output;
    }

    public static void main(String[] args) {
        // get file path passed in via args
        String path = "";
        File file;
        Scanner sc;
        String[] words = {};
        try {
            path = args[0];
            file = new File(path);
            sc = new Scanner(file);
            words = parseFile(sc);
        } catch (FileNotFoundException e) {
            System.err.println("\nERROR: Unable to find file at : \'" + path + "\'. Please double check path.\n");
        } catch (IndexOutOfBoundsException e) {
            System.err.println("\nERROR: Invalid usage. Usage: java driver.java <input_file>\n");
        } catch (Exception e) {
            System.err.println("\nERROR: An error occured, please try again later.\n");
        }
        //create Tree Object 
        BST<String> tree = new BST<>();
        // insert words into three one by one
        for (String s : words) {
            tree.insert(s);
        }
        // print results
        System.err.println("TREE: \n"+tree.LVR_Inorder());
    }
}
