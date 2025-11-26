#include "stack.h"
#include <iostream>
#include <cmath>
using namespace std;

bool isDigit(char c){
    return c>='0' && c<='9';
}

bool isOperator(char c){  
    return c == '+' || c == '-' || c =='/' || c=='^' || c=='*';
}

double evaluate_postfix(const char* expression) {
    Stack<double> stack(100);

    cout << "Expression: " << expression << endl;
    cout << "Tokens to process: " << expression << endl;
    cout << "------------------------------" << endl;

    for(int i=0; expression[i]!='\0'; i++){
        if(expression[i]==' '){
            continue;
        }
        if(isDigit(expression[i])){
            double value = expression[i] - '0';
            stack.push(value);
            cout << "Pushed operand: " << value << " | Stack: ";
            stack.display();
            cout << endl;
        }
        else if (isOperator(expression[i])){
            if (stack.sizet() < 2) {
                throw "Invalid expression: Insufficient operands";
            }
            double operand2 = stack.pop();
            double operand1 = stack.pop();
            double result;

            char op = expression[i];
            switch (op)
            {
            case ('+'):
                result = operand1+operand2;
                break;
            case ('-'):
                result=operand1-operand2;
                break;
            
            case ('/'):
                result=operand1/operand2;
                break;
            case ('*'):
                result=operand1*operand2;
                break;
            case ('^'):
                result = pow(operand1, operand2);
                break;
            default:
                break;
            }

            stack.push(result);
            cout << "Calculated: " << operand1 << " " << op << " " << operand2 << " = " << result << " | Stack: ";
            stack.display();
            cout << endl;
        }
        else{
            throw "Invalid token encountered";
        }
    }
    cout << "------------------------------" << endl;
    if (stack.sizet() == 1) {
        double final_result = stack.peek();
        if (final_result == static_cast<int>(final_result)) {
            return static_cast<int>(final_result);
        }
        return final_result;
    } 
    else {
        throw "Invalid expression: Too many operands or insufficient operators";
    }
}

int main() {
    const char* expressions[] = {
        "1 5 +",
        "2 3 1 * + 9 -",
        "5 1 2 +"
    };
    
    for (int i = 0; i < 3; i++) {
        try {
            double result = evaluate_postfix(expressions[i]);
            cout << "Result: " << result << "\n" << endl;
        } catch (const char* msg) {
            cout << "Error: " << msg << "\n" << endl;
        }
    }
    
    return 0;
}