#ifndef CQ_H
#define CQ_H

#include <iostream>
using namespace std;

template<typename t>
class Circularqueue{
    private:
    int front,rear;
    int size;
    t * arr;

    public:
    Circularqueue(int);
    void enqueue(t);
    t dequeue();
    bool isfull();
    bool isempty();
    void display();
};

template<typename t>
Circularqueue<t> :: Circularqueue(int n){
    size=n;
    arr= new t[size];
    front=-1;
    rear=-1;
}

template<typename t>
void Circularqueue<t> :: enqueue(t el){
    if(!isfull()){
        rear=(rear+1)%size;
        arr[rear]=el;
        if(front==-1){
            front++;
        }
    }
    else{
        cout<<"overflow error";
    }
}

template<typename t>
t Circularqueue<t> :: dequeue(){
    if(!isempty()){
        t x = arr[front];
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            front=(front+1)%size;
        }
        return x;
    }
    else{
        cout<<"underflow error";
    }
}

template<typename t>
bool Circularqueue<t> :: isempty(){
    return front==-1 ;
}

template<typename t>
bool Circularqueue<t> :: isfull(){
    return front==(rear+1)%size;
}

template<typename t>
void Circularqueue<t> :: display(){
    if(!isempty()){
        int i = front;
        while(i!=rear){
            cout<<arr[i]<<" ";
            i=(i+1)%size;
        }
        cout << arr[rear] << " ";
    }
    else{
        cout<<"underflow error";
    }
}


#endif
