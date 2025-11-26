#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Singly Linked List Class
class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = NULL;
    }

    // i. Insert at beginning
    void insertAtBeginning(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = head;
        head = newNode;
    }

    // ii. Insert at ith position
    void insertAtPosition(int x, int pos) {
        if (pos < 1) {
            cout << "Invalid position\n";
            return;
        }

        Node* newNode = new Node();
        newNode->data = x;

        // If inserting at beginning
        if (pos == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Position out of range\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // iii. Remove from beginning
    void removeFromBeginning() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // iv. Remove from ith position
    void removeFromPosition(int pos) {
        if (head == NULL || pos < 1) {
            cout << "Invalid position or empty list\n";
            return;
        }

        // If removing first node
        if (pos == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Position out of range\n";
            return;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }

    // v. Search and return pointer to node
    Node* search(int x) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == x)
                return temp;
            temp = temp->next;
        }
        return NULL;
    }

    // Display list
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// Main function for testing
int main() {
    SinglyLinkedList list;

    list.insertAtBeginning(30);
    list.insertAtBeginning(20);
    list.insertAtBeginning(10);

    cout << "List after insertions: ";
    list.display();

    list.insertAtPosition(25, 3);
    cout << "After inserting 25 at position 3: ";
    list.display();

    list.removeFromBeginning();
    cout << "After removing from beginning: ";
    list.display();

    list.removeFromPosition(2);
    cout << "After removing from position 2: ";
    list.display();

    Node* result = list.search(25);
    if (result)
        cout << "Element 25 found at node: " << result << endl;
    else
        cout << "Element 25 not found\n";

    return 0;
}
