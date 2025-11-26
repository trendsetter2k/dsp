#include "queue.h" // Include your header file

int main() {
    // Create a queue of integers with a maximum size of 5
    queue<int> myQueue(5); 

    cout << "--- Initial State ---" << endl;
    myQueue.display(); // Should show [Empty]

    // 1. Enqueue 3 elements
    cout << "\n--- Enqueue Operations ---" << endl;
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);
    myQueue.display(); // Expected: 10 20 30 

    // 2. Dequeue 1 element
    cout << "\n--- Dequeue Operation 1 ---" << endl;
    myQueue.dequeue();
    myQueue.display(); // Expected: 20 30 (10 is logically removed, front is now 1)

    // 3. Enqueue up to full capacity (Max size is 5)
    myQueue.enqueue(40);
    myQueue.enqueue(50);
    myQueue.enqueue(60); // Queue is now full (rear is at index 4)
    myQueue.display(); // Expected: 20 30 40 50 60 

    // 4. Test isfull() and overflow
    cout << "\n--- Test Full Queue ---" << endl;
    if (myQueue.isfull()) {
        cout << "Queue reports: FULL." << endl;
    }
    myQueue.enqueue(70); // Should print "Queue is Full!"
    myQueue.display(); // Expected: 20 30 40 50 60 (no change)

    // 5. Dequeue all elements until empty
    cout << "\n--- Dequeue All ---" << endl;
    myQueue.dequeue(); // Removes 20
    myQueue.dequeue(); // Removes 30
    myQueue.dequeue(); // Removes 40
    myQueue.dequeue(); // Removes 50
    myQueue.dequeue(); // Removes 60 -> Resets front and rear to -1
    myQueue.display(); // Should show [Empty]
    
    // 6. Test isempty() and underflow
    cout << "\n--- Test Empty Queue ---" << endl;
    if (myQueue.isempty()) {
        cout << "Queue reports: EMPTY." << endl;
    }
    myQueue.dequeue(); // Should print "Queue is Empty!"

    return 0;
}