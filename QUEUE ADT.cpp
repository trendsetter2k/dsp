#include <iostream>
using namespace std;

class Queue {
private:
    int arr[100];
    int front, rear;
    int size;

public:
    Queue(int s = 100) {
        size = s;
        front = 0;
        rear = -1;
    }

    // Insert element (enqueue)
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        arr[++rear] = x;
    }

    // Remove element (dequeue)
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front++];
    }

    // Get front element
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    // Check if empty
    bool isEmpty() {
        return front > rear;
    }

    // Check if full
    bool isFull() {
        return rear == size - 1;
    }

    // Display queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    cout << "Dequeued: " << q.dequeue() << endl;
    q.display();

    cout << "Front element: " << q.getFront() << endl;

    return 0;
}
