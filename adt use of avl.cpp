#include <iostream>
#include "avl.h"
using namespace std;

int main() {
    AVLTree<int> tree;

    // Insert values
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(10);
    tree.insert(25);
    tree.insert(35);
    tree.insert(50);

    // Display inorder (should be sorted)
    cout << "Tree contents (inorder): ";
    tree.display();

    // Search tests
    cout << "\nSearching 25: ";
    if (tree.search(25))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    cout << "Searching 99: ";
    if (tree.search(99))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    return 0;
}
