#include <iostream>
#include <cstring>
using namespace std;

// ----------------------
// STACK ADT
// ----------------------
class Stack {
private:
    int arr[100];
    int top;

public:
    Stack() { top = -1; }

    void push(int x) {
        arr[++top] = x;
    }

    int pop() {
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

// ----------------------
// Function to check if a char is operator
// ----------------------
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// ----------------------
// POSTFIX Evaluation
// Example: "23*54*+"
// ----------------------
int evaluatePostfix(string exp) {
    Stack s;

    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        // If operand → push to stack
        if (isdigit(c)) {
            s.push(c - '0');  // convert char to int
        }
        // If operator → pop 2 values, apply, push result
        else if (isOperator(c)) {
            int b = s.pop();
            int a = s.pop();

            switch (c) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
            }
        }
    }
    return s.pop();
}

// ----------------------
// PREFIX Evaluation
// Example: "+*23*54"
// ----------------------
int evaluatePrefix(string exp) {
    Stack s;

    // Traverse from RIGHT to LEFT
    for (int i = exp.length() - 1; i >= 0; i--) {
        char c = exp[i];

        if (isdigit(c)) {
            s.push(c - '0');
        }
        else if (isOperator(c)) {
            int a = s.pop();
            int b = s.pop();

            switch (c) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
            }
        }
    }
    return s.pop();
}

// ----------------------
// MAIN
// ----------------------
int main() {
    string postfix, prefix;

    cout << "Enter postfix expression: ";
    cin >> postfix;
    cout << "Postfix Evaluation Result = " << evaluatePostfix(postfix) << endl;

    cout << "\nEnter prefix expression: ";
    cin >> prefix;
    cout << "Prefix Evaluation Result = " << evaluatePrefix(prefix) << endl;

    return 0;
}
