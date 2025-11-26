#include "singly_linked_list.h" // Include your corrected header file
#include <iostream>

using namespace std;

// Note: To compile this, you'll need to move the fixed Node constructor 
// to the public section of the Node class/struct.

int main() {
    // Create an SLL instance to hold integers
    SLL<int> list;

    cout << "--- Initial List State ---" << endl;
    list.display();

    // 1. PUSH OPERATIONS (Front and Back)
    cout << "\n--- 1. Pushing Elements ---" << endl;
    list.push_front(10); // List: [10]
    list.push_back(30);  // List: [10 30]
    list.push_front(5);  // List: [5 10 30]
    list.push_back(40);  // List: [5 10 30 40]
    list.display();      // Expected: 5 10 30 40

    // 2. INSERT OPERATION
    cout << "\n--- 2. Insertion (Value: 20 at Pos: 2) ---" << endl;
    list.insert(20, 2);  // List: [5 10 20 30 40] (Positions start at 0)
    list.display();      // Expected: 5 10 20 30 40

    // 3. SEARCH OPERATION
    cout << "\n--- 3. Search ---" << endl;
    list.search(30);     // Expected: found at position: 3
    list.search(99);     // Expected: Value not found

    // 4. POP/REMOVE OPERATIONS
    cout << "\n--- 4. Removal Operations ---" << endl;
    
    // Remove from front (pop_front)
    list.pop_front();    // Removes 5. List: [10 20 30 40]
    cout << "After pop_front(): ";
    list.display();

    // Remove at specific position (removeAt)
    // Remove 40 (tail) at position 3
    list.removeAt(3);    // Removes 40. List: [10 20 30]
    cout << "After removeAt(3): ";
    list.display();
    
    // Remove 20 at position 1
    list.removeAt(1);    // Removes 20. List: [10 30]
    cout << "After removeAt(1): ";
    list.display();

    // 5. Boundary Check: Remove last two elements
    cout << "\n--- 5. Final Removal ---" << endl;
    list.pop_front(); // Removes 10. List: [30]
    list.pop_front(); // Removes 30. List: []
    list.display();   // Expected: List is empty

    // 6. Underflow check
    list.pop_front(); // Expected: List is empty message

    return 0;
}