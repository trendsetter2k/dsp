#include <iostream>
#include "CLL.h"
using namespace std;

int main() {
    CLL<int> list;

    cout << "Inserting values: 10, 20, 30, 40\n";
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    cout << "List after insertion: ";
    list.display();

    cout << "Removing element 20\n";
    list.removeElement(20);
    cout << "List now: ";
    list.display();

    cout << "Searching for 30...\n";
    Node<int>* result = list.search(30);

    if(result != nullptr)
        cout << "Found: " << result->data << endl;
    else
        cout << "Value not found\n";

    cout << "Removing head (10)\n";
    list.removeElement(10);
    list.display();

    cout << "Removing element 40\n";
    list.removeElement(40);
    list.display();

    cout << "Removing last element 30\n";
    list.removeElement(30);
    list.display();

    return 0;
}
