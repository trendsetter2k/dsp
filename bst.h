#ifndef BST_H
#define BST_H
#include <iostream>
using namespace std;

template<typename t>
class Node{
    public:
    t data;
    Node* left;
    Node* right;
    public:
    Node(t value){
        data=value;
        left=nullptr;
        right=nullptr;
    }
};

template<typename t>
class BST{
    private:
    Node<t>* root;

    Node<t>* insert(Node<t>* node,t val){
        if(node==nullptr){
            return new Node<t>(val);
        }
        if(val<node->data){
            node->left=insert(node->left,val);
        }
        else if(val>node->data){
            node->right=insert(node->right,val);
        }
        return node;
    }

    bool search(Node<t>* node,t val){
        if(node==nullptr){
            return false;
        }
        if(node->data==val){
            return true;
        }    
        else if(val<node->data){
            return search(node->left,val);
        }
        else{
            return search(node->right,val);
        }
    }

    Node<t>* findMin(Node<t>* node) {
        while(node && node->left!=nullptr){
            node=node->left;
        }
        return node;
    }

    Node<t>* deleteNode(Node<t>* node, t val){
        if(node==nullptr){
            return node;
        }
        if(val<node->data){
            node->left=deleteNode(node->left,val);
        }
        else if(val>node->data){
            node->right=deleteNode(node->right,val);
        }
        else{
            if (node->left==nullptr){
                Node<t>* temp=node->right;
                delete node;
                return temp;
            }
            else if(node->right==nullptr){
                Node<t>* temp= node->left;
                delete node;
                return temp;
            }
            Node<t>* temp=findMin(node->right);
            node->data=temp->data;
            node->right=deleteNode(node->right,temp->data);
        }
        return node;
    }

    void inorder(Node<t>* node){
        if(node==nullptr){
            return;
        }
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }

    void preorder(Node<t>* node){
        if(node==nullptr){
            return;
        }
        cout<<node->data<<" ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node<t>* node){
        if(node==nullptr){
            return;
        }
        postorder(node->left);
        postorder(node->right);
        cout<<node->data<<" ";
    }
    public:
    
    BST() :root(nullptr){};

    void insert(t val){
        root=insert(root,val);
    }

    void deleteValue(t value){
        root=deleteNode(root,value);
    }

    bool search(t value){
        return search(root,value);
    }

    void display(){
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << "\nPreorder Traversal: ";
        preorder(root);
        cout << "\nPostorder Traversal: ";
        postorder(root);
        cout << endl;        
    }

};


#endif