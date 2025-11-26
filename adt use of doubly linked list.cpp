#include "doubly_linked_list.h"
#include <iostream>
using namespace std;

int main() {
    // Create a Doubly Linked List instance to hold integers
    DLL<int> myList;

    cout << "--- Initial State ---" << endl;
    myList.display();

    // 1. INSERT AT BEGINNING
    cout << "\n--- 1. Insert At Beginning (10, 5, 1) ---" << endl;
    myList.insertatbeginning(10); // List: 10
    myList.insertatbeginning(5);  // List: 5 <-> 10
    myList.insertatbeginning(1);  // List: 1 <-> 5 <-> 10
    myList.display();             // Expected: 1 <-> 5 <-> 10 <-> Null

    // 2. INSERT AT END
    cout << "\n--- 2. Insert At End (20, 30) ---" << endl;
    myList.insertatend(20);       // List: 1 <-> 5 <-> 10 <-> 20
    myList.insertatend(30);       // List: 1 <-> 5 <-> 10 <-> 20 <-> 30
    myList.display();             // Expected: 1 <-> 5 <-> 10 <-> 20 <-> 30 <-> Null

    // 3. REMOVE FROM BEGINNING
    cout << "\n--- 3. Remove From Beginning ---" << endl;
    myList.removefrombeginning(); // Removes 1
    cout << "After removal: ";
    myList.display();             // Expected: 5 <-> 10 <-> 20 <-> 30 <-> Null
    
    // 4. REMOVE FROM END
    cout << "\n--- 4. Remove From End ---" << endl;
    myList.removefromend();       // Removes 30
    cout << "After removal: ";
    myList.display();             // Expected: 5 <-> 10 <-> 20 <-> Null

    // 5. REMOVE ALL ELEMENTS and test boundary conditions
    cout << "\n--- 5. Remove Remaining Elements ---" << endl;
    myList.removefrombeginning(); // Removes 5
    myList.removefromend();       // Removes 20
    cout << "After 2 removals: ";
    myList.display();             // Expected: 10 <-> Null (Single node remains)

    myList.removefrombeginning(); // Removes the last node (10)
    cout << "After final removal: ";
    myList.display();             // Expected: list is empty

    // 6. Test underflow (empty list removals)
    cout << "\n--- 6. Test Underflow ---" << endl;
    myList.removefrombeginning(); // Expected: "no value at the head"
    myList.removefromend();       // Expected: "no value at the tail"
    cout << endl;

    return 0;
}