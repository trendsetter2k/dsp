#ifndef DLL_H
#define DLL_H
#include <iostream>
using namespace std;

template <typename T>
class Node{
    public:
    T data;
    Node<T> *next;
    Node<T> *prev;
    public:
    Node(T value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

template <typename t>
class DLL{
    private:
    Node<t>* head;
    Node<t>* tail;
    public:
    DLL(){
        head=nullptr;
        tail=nullptr;
    }
    void insertatbeginning(t value){
        Node<t>* newnode = new Node<t>(value);
        if(head==nullptr){
            head=tail=newnode;
        }
        else{
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
        }
    }

    void insertatend(t value){
        Node<t>* newnode = new Node<t>(value);
        if(head==nullptr){
            head=tail=newnode;
        } 
        else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;            
        }       
    }

    void removefrombeginning(){
        Node<t>* temp = head;
        if(temp==nullptr){
            cout<<"no value at the head"<<endl;
            return;
        }
        if(head==tail){
            head=tail=nullptr;
        }
        else{
            head=head->next;
            head->prev=nullptr;
        }
        delete temp;
    }

    void removefromend(){
        Node<t>* temp = tail;
        if(temp==nullptr){
            cout<<"no value at the tail"<<endl;
            return;
        }
        if(tail==head){
            head=tail=nullptr;
        }
        else{
            tail=tail->prev;
            tail->next=nullptr;
        }
        delete temp;
    }

    void display(){
        Node<t>* temp = head;
        if(!temp){
            cout<<"list is empty";
            return;
        }
        cout<<"list: "<<endl;
        while(temp){
            cout<<temp->data<<"<->";
            temp=temp->next;
        }
        cout<<"Null\n";
    }

};

#endif