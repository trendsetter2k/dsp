#include "circular_queue.h"
using namespace std;

int main() {
    // Create a circular queue of integers with size 5
    // Note: Due to the isfull() check (front == (rear+1)%size),
    // the effective capacity is size - 1 (i.e., 4 elements).
    const int CAPACITY = 5;
    Circularqueue<int> cq(CAPACITY);

    cout << "--- Circular Queue Operations (Capacity: " << CAPACITY - 1 << " elements) ---" << endl;
    cq.display(); 
    
    // --- 1. Enqueue 4 elements (Fill the Queue) ---
    cout << "\n--- Enqueue: 10, 20, 30, 40 ---" << endl;
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.display(); // Expected: 10 20 30 40 

    // --- 2. Test Full State ---
    cout << "\n--- Test Full Queue ---" << endl;
    cq.enqueue(50); // This should trigger the Overflow Error (Capacity is 4)

    // --- 3. Dequeue 2 elements ---
    cout << "\n--- Dequeue: 10 and 20 ---" << endl;
    cout << "Dequeued: " << cq.dequeue() << endl; // Removes 10 (front moves to 1)
    cout << "Dequeued: " << cq.dequeue() << endl; // Removes 20 (front moves to 2)
    cq.display(); // Expected: 30 40 

    // --- 4. Enqueue 2 new elements (Circular behavior) ---
    // rear will wrap around to 0, then 1
    cout << "\n--- Enqueue: 60 and 70 (Wrap Around) ---" << endl;
    cq.enqueue(60); 
    cq.enqueue(70); 
    cq.display(); // Expected (due to wrap): 30 40 60 70 

    // --- 5. Dequeue All to Test Empty Reset ---
    cout << "\n--- Dequeue All ---" << endl;
    cout << "Dequeued: " << cq.dequeue() << endl; // 30
    cout << "Dequeued: " << cq.dequeue() << endl; // 40
    cout << "Dequeued: " << cq.dequeue() << endl; // 60
    cout << "Dequeued: " << cq.dequeue() << endl; // 70 -> Resets front/rear to -1

    cout << "\n--- Final State ---" << endl;
    cq.display(); // Should display [Empty]

    // --- 6. Test Underflow ---
    cout << "\n--- Test Underflow ---" << endl;
    // This will call the underflow logic, which should return a default value (0 for int)
    cout << "Attempted Dequeue (Underflow): " << cq.dequeue() << endl; 

    return 0;
}