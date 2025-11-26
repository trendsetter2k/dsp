#ifndef STACK_ON_TOP_H
#define STACK_ON_TOP_H

#include <iostream>
using namespace std;

template <typename t>
class Stack{
    private:
    t * arr;
    int top;
    int size;
    public:
    Stack(int);
    void push(t);
    t pop();
    t peek();
    bool isempty();
    bool isfull();
    void display();
    int sizet();
};

template<typename t>
Stack<t> :: Stack(int n){
    size = n;
    arr = new t[size];
    top=-1;
}

template<typename t>
void Stack<t> :: push(t el){
    if(isfull()){
        cout<<"stack over flow";
        return;
    }
    arr[++top]=el;
}

template<typename t>
t Stack<t>:: pop(){
    if(isempty()){
        cout<<"stack underflow";
    }
    return arr[top--];
}

template<typename t>
t Stack<t> :: peek(){
    if(isempty()){
        cout<<"stack underflow";
    }
    return arr[top];
}

template<typename t>
bool Stack<t> :: isempty(){
    return top==-1;
}

template<typename t>
bool Stack<t> :: isfull(){
    return top==size-1;
}

template<typename t>
void Stack<t> :: display(){
    for(int i=0;i<=top;i++){
        cout<<arr[i]<<" ";
    }
}

template<typename t>
int Stack<t> :: sizet() {
        return top + 1;
}


#endif