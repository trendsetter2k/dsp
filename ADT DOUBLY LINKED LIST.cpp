#include <iostream>
using namespace std;

// Node structure for doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    // i. Insert an element at the beginning
    void insertAtBeginning(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->prev = NULL;
        newNode->next = head;

        if (head != NULL)
            head->prev = newNode;
        else
            tail = newNode; // list was empty

        head = newNode;
    }

    // ii. Insert an element at the end
    void insertAtEnd(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = NULL;
        newNode->prev = tail;

        if (tail != NULL)
            tail->next = newNode;
        else
            head = newNode; // list was empty

        tail = newNode;
    }

    // iii. Remove element from the beginning
    void removeFromBeginning() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL; // list is now empty

        delete temp;
    }

    // iv. Remove element from the end
    void removeFromEnd() {
        if (tail == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = tail;
        tail = tail->prev;

        if (tail != NULL)
            tail->next = NULL;
        else
            head = NULL; // list is now empty

        delete temp;
    }

    // Display list (for checking)
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};


// main() to test the ADT
int main() {
    DoublyLinkedList list;

    list.insertAtBeginning(30);
    list.insertAtBeginning(20);
    list.insertAtBeginning(10);

    cout << "After inserting at beginning: ";
    list.display();

    list.insertAtEnd(40);
    list.insertAtEnd(50);

    cout << "After inserting at end: ";
    list.display();

    list.removeFromBeginning();
    cout << "After removing from beginning: ";
    list.display();

    list.removeFromEnd();
    cout << "After removing from end: ";
    list.display();

    return 0;
}
