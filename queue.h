#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

template<typename t>
class queue{
    private:
    int front,rear;
    int size;
    t * arr;

    public:
    queue(int);
    void enqueue(t);
    void dequeue();
    bool isfull();
    bool isempty();
    void display();
};

template<typename t>
queue<t> :: queue(int n){
    size=n;
    arr=new t[size];
    front=-1;
    rear=-1;
}

template<typename t>
void queue<t> :: enqueue(t el){
    if(isfull()){
        return;
    }
    if(front==-1){
        front = 0;
    }
    arr[++rear]=el;
}

template<typename t>
void queue<t> :: dequeue(){
    if(isempty()){
        return;
    }
    front++;
    
    if(front > rear){
        front = -1;
        rear = -1;
    }
}

template<typename t>
bool queue<t> :: isempty(){
    return front == rear == -1;
}

template<typename t>
bool queue<t> :: isfull(){
    return rear == size-1;
}

template<typename t>
void queue<t> :: display(){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}



#endif