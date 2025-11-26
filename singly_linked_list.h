#ifndef SL_H
#define SL_H
#include <iostream>
using namespace std;

template<typename t>
class Node{
    public:
    t data;
    Node<t> * next;
    public:
    Node (t el){
        data = el;
        next = nullptr;
    }
};

template<typename t>
class SLL{
    Node<t> * head;
    Node<t> * tail;

    public:
    SLL(){
        head=nullptr;
        tail=nullptr;
    }

    bool isempty(){
        return head==nullptr;
    }

    void push_front(t value){    
        Node<t> * newnode = new Node<t>(value);
        if(isempty()){
            tail=newnode;
            head=newnode;
        }

        else{
            newnode->next=head;
            head=newnode;
        }
    }

    void push_back(t value){
        Node<t>* newnode = new Node<t>(value);
        if(isempty()){
            tail=newnode;
            head=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }

    void insert(t value, int position){

        if(position<0){
            cout<<"underflow";
        }
        if(position==0){
            push_front(value);
            return;
        }

        Node<t> * newnode = new Node<t>(value);
        Node<t> * temp = head;

        for(int i=0;i<position-1;i++){
            if(temp==nullptr){
                cout << "Position out of bounds" << endl;
                delete newnode;
                return;
            }
            temp=temp->next;
        }

        if(temp==tail){
            push_back(value);
            return;
        }

        newnode->next=temp->next;
        temp->next=newnode;
    }

    void pop_front(){
        if (isempty())
        {
            cout << "List is empty" << endl;
            return;
        }
        Node<t> *temp = head;
        head=head->next;
        if (head == nullptr) tail = nullptr; 
        delete temp;
    }

    void removeAt(int position){
        if(isempty()){
            cout<<"list is empty";
            return;
        }
        if(position<0){
            cout<<"position value is out of boss";
            return;
        }
        if(position==0){
            pop_front();
            return;
        }

        Node<t> *temp = head;
        for (int i = 0; i < position-1; i++){
            if(temp==nullptr || temp->next==nullptr){
                cout << "Position out of bounds" << endl;
                return;
            }
            temp=temp->next;
        }

        Node<t>* deletenode = temp->next;
        if (deletenode == nullptr)
        {
            cout << "Position out of bounds" << endl;
            return;
        }

        temp->next=deletenode->next;
        if(deletenode==tail) tail=temp;
        delete deletenode;
    }

    void search(t value){
        if(isempty()){
            cout << "List is empty" << endl;
            return;
        }

        Node<t>* temp=head;
        int position = 0;
        while(temp!=nullptr){
            if(temp->data==value){
                cout<<"value found at position: "<< position <<endl;
                return;
            }
            temp=temp->next;
            position++;
        }
        cout << "Value not found" << endl;
    }

    void display(){
        if(isempty()){
            cout << "List is empty" << endl;
            return;
        }

        Node<t>* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

};

#endif 
