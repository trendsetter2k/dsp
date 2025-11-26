#ifndef CLL_H
#define CLL_H

#include <iostream>
using namespace std;

template<typename t>
class Node{
    public:
    t data;
    Node<t>* next;
    Node(t val){
        data=val;
        next=nullptr;
    }
};

template<typename t>
class CLL{
    private:
    Node<t>* head;

    public:
    CLL(){
        head=nullptr;
    }

    void insert(t val){
        Node<t>* newnode = new Node<t>(val);

        if(head==nullptr){
            newnode->next=newnode;
            head=newnode;
            return;
        }

        Node<t>* temp=head;
        while(temp->next != head){
            temp=temp->next;
        }

        newnode->next=head;
        temp->next=newnode;
    }

    void removeElement(t val){
        if(head==nullptr){
            return;
        }

        Node<t>* curr = head;
        Node<t>* prev = nullptr;

        if(curr->data==val){
            if(curr->next==curr){
                delete curr;
                head=nullptr;
                return;
            }

            Node<t>* temp=curr;
            while(temp->next != head){
                temp=temp->next;
            }
            temp->next=curr->next;
            head=curr->next;
            delete curr;
            return;
        }

        prev=curr;
        curr=curr->next;

        while(curr!=head){
            if(curr->data==val){
                prev->next=curr->next;
                delete curr;
                return;
            }
            prev=curr;
            curr=curr->next;
        }
    }

    Node<t>* search(t val){
        if(head==nullptr) return nullptr;

        Node<t>* temp = head;
        do{
            if(temp->data == val)
                return temp;
            temp = temp->next;
        }while(temp != head);

        return nullptr;
    }

    void display(){
        if(head==nullptr){
            cout<<"List is empty"<<endl;
            return;
        }

        Node<t>* temp = head;
        do{
            cout << temp->data << " ";
            temp = temp->next;
        }while(temp != head);

        cout << endl;
    }
};


#endif