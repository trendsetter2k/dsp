#ifndef AVL_H
#define AVL_H

#include <iostream>
#include <algorithm>
using namespace std;

template<typename t>
class Node{
    public:
    t data;
    Node* left;
    Node* right;
    int ht;
    public:
    Node(t value){
        data=value;
        ht=1;
        left=nullptr;
        right=nullptr;
    }
};

template<typename t>
class AVLTree{
    private:
    Node<t>* root;

    protected:
    int height(Node<t>* node){
        return(node==nullptr ? 0 : node->ht);
    }

    int setheight(Node<t>* node){
        if(node!=nullptr){
            int hl=height(node->left);
            int hr=height(node->right);
            node->ht = 1 + std::max(hl,hr);
        }
        return 0;
    }

    bool isbalanced(Node<t>* node){
        if(node==nullptr){
            return true;
        }
        int bal=height(node->left) - height(node->right);
        return (bal >= -1 && bal <= 1);
    }

    Node<t>* tallchild(Node<t>* node){
        Node<t>* zl = node->left;
        Node<t>* zr = node->right;
        if(height(zl)>=height(zr)){
            return zl;
        }
        else{
            return zr;
        }
    }

    Node<t>* tallgrandchild(Node<t>* node){
        Node<t>* y = tallchild(node);
        return tallchild(y);
    }

    Node<t>* restructure(Node<t>*x, Node<t>*y, Node<t>*z){
        if(z->left==y && y->left==x){
            z->left=y->right;
            y->right=z;
            setheight(z);
            setheight(y);
            return y;
        }
        if(z->right==y && y->right==x){
            z->right=y->left;
            y->left=z;
            setheight(z);
            setheight(y);
            return y;
        }
        if(z->left == y && y->right == x){
            y->right = x->left;
            z->left = x->right;
            x->left = y;
            x->right = z;
            setheight(y);
            setheight(z);
            setheight(x);
            return x;
        }
        if(z->right == y && y->left == x){
            y->left = x->right;
            z->right = x->left;
            x->right = y;
            x->left = z;
            setheight(y);
            setheight(z);
            setheight(x);
            return x;
        }
        return z;
    }
    
    void rebalance(Node<t>* z){
        while(z!=nullptr){
            setheight(z);
            if(!isbalanced(z)){
                Node<t>* y = tallchild(z);
                Node<t>* x = tallchild(y);
                z = restructure(x,y,z);
            } 
            else{
                root = z;
                break;
            }
        }
    }

    Node<t>* insert(Node<t>* node, t val){
        if(node==nullptr){
            return new Node<t>(val);
        }
        
        if(val<node->data){
            node->left = insert(node->left,val);
        }
        else if(val>node->data){
            node->right = insert(node->right,val);
        }
        else{
            return node;
        }

        setheight(node);
        if(!isbalanced(node)){
            Node<t>* y = tallchild(node);
            Node<t>* x = tallchild(y);
            node = restructure(x,y,node);
        }
        return node;
    }

    bool search(Node<t>* node, t val) const{
        if(node==nullptr){
            return false;
        }
        if(node->data==val){
            return true;
        }
        else if (val<node->data){
            return search(node->left,val);
        }
        else{
            return search(node->right,val);
        }
    }

    void inorder(Node<t>* node) const{
        if(node==nullptr){
            return;
        }
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }

    public:
    AVLTree() : root(nullptr) {}

    void insert(t k) {
        root = insert(root, k);
    }

    bool search(t k) const {
        return search(root, k);
    }

    void display() const {
        inorder(root);
        cout << endl;
    }

};

#endif
