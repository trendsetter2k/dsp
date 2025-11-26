#include "stack.h"
using namespace std;

int main(){
    Stack<int> s(5);
    cout << "✅ Stack of size 5 created." << endl;
    cout << "Is stack empty? " << (s.isempty() ? "Yes" : "No") << endl;

    cout << "\n--- Push Operations ---" << endl;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50); // Stack is now full
    
    // Display the array contents after pushing 5 elements
    cout << "Elements pushed: 10, 20, 30, 40, 50." << endl;
    cout << "Stack Array Content: ";
    s.display();
    cout << endl;

    cout << "\n--- Status Checks ---" << endl;
    cout << "Is stack empty? " << (s.isempty() ? "Yes" : "No") << endl;
    cout << "Is stack full? " << (s.isfull() ? "Yes" : "No") << endl;

    cout << "\n--- Overflow Check ---" << endl;
    // 3. Attempt to push an extra element (should cause overflow)
    s.push(60); 
    cout << " (Attempted to push 60)" << endl; 

    cout << "\n--- Peek Operation ---" << endl;
    // 4. Peek at the top element
    cout << "Top element (Peek): " << s.peek() << endl;

    cout << "\n--- Pop Operations ---" << endl;
    // 5. Pop elements from the stack
    cout << "Popped: " << s.pop() << endl; // Pops 50
    cout << "Popped: " << s.pop() << endl; // Pops 40
    
    // Peek again after popping
    cout << "Top element after 2 pops: " << s.peek() << endl; 
    
    cout << "Stack Array Content (Note: Only 'pop' removes element logic, array still holds old values): ";
    s.display();
    cout << endl;
    
    // 6. Empty the stack
    s.pop(); // Pops 30
    s.pop(); // Pops 20
    s.pop(); // Pops 10

    cout << "\n--- Underflow Check ---" << endl;
    cout << "Is stack empty? " << (s.isempty() ? "Yes" : "No") << endl;
    // 7. Attempt to pop from an empty stack (should cause underflow)
    s.pop();
    cout << " (Attempted to pop from empty stack)" << endl; 

    return 0;
}