#include "bst.h"
#include <iostream>
using namespace std;


int main() {
    // Create an Integer Binary Search Tree
    BST<int> tree;
    
    // Values to insert: 50, 30, 70, 20, 40, 60, 80
    
    cout << "--- 1. Insertion ---" << endl;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    cout << "Inserted 7 nodes: 50, 30, 70, 20, 40, 60, 80" << endl;
    
    // Display traversals 
    cout << "\n--- 2. Traversal Display ---" << endl;
    tree.display();
    // Expected display: 20 30 40 50 60 70 80 (Sorted order)
    
    // 3. Search Operations
    cout << "\n--- 3. Search Operations ---" << endl;
    int searchVal1 = 40;
    int searchVal2 = 99;
    
    cout << "Searching for " << searchVal1 << ": " 
         << (tree.search(searchVal1) ? "Found" : "Not Found") << endl;
         
    cout << "Searching for " << searchVal2 << ": " 
         << (tree.search(searchVal2) ? "Found" : "Not Found") << endl;

    // 4. Deletion Operations
    cout << "\n--- 4. Deletion Operations ---" << endl;
    
    // Case 1: Delete a leaf node (e.g., 20)
    cout << "Deleting 20 (Leaf)..." << endl;
    tree.deleteValue(20);
    cout << "After deleting 20, display: ";
    tree.display(); // Calling display() would run all 3, but using the public wrapper for display here
    cout << "\n";

    // Case 2: Delete a node with one child (e.g., 70, now 70 has only right child 80)
    // Wait, let's delete 40 (only 50 is left) to simplify
    cout << "Deleting 40 (Leaf)..." << endl;
    tree.deleteValue(40);
    cout << "After deleting 40, display: ";
    tree.display(); 
    cout << "\n";
    
    // Case 3: Delete a node with two children (e.g., 50 - the root)
    cout << "Deleting 50 (Root/Two Children)..." << endl;
    tree.deleteValue(50); // The new root should be 60 (the display successor)
    
    cout << "--- 5. Final State Traversal ---" << endl;
    tree.display();
    // Expected display: 30 60 70 80

    return 0;
}