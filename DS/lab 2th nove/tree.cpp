#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node*left,*right;
    node(){
        left=right=nullptr;
    } 
    node(int n) {
        data=n;
        left=right=nullptr;
    }
};
class BST{
    node*root;
    public:
    BST(){
        root=nullptr;
    }
    BST(int x){
        root->data=x;
    }
    void insert(int x);
    void del(int x);
    void inorder();
    void preorder(); 
    void postorder();
};
void BST::insert(int x){
    node*t=new node(x);
    if(root==nullptr){
        root=t;
    }
    else{
        node*it=root,*p=nullptr;
        while(!it){
            p=it;
            if(it->data>x){
                it=it->left;
            }else{
                it=it->right;
            }
        }
        if(p->data>x){
            p->left=t;
        }else{
            p->right=t;
        }
    }
}
node*dell(node*root,int x){
    if(root==nullptr){
        return root;
    }
    if(root->data>x){
        root->left=dell(root->left,x);
    }else if(root->data<x){
        root->right=dell(root->right,x);
    }else{
        if(root->left==nullptr){
            node*t=root->right;
            delete root;
            return t;
        }
        else if(root->right==nullptr){
            node*t=root->left;
            delete root;
            return t;
        }
        else{
            node*it=root->right;
            while(it->left!=nullptr){
                it=it->left;
            }
            root->data=it->data;
            root->right=dell(root->right,it->data);
        }
    }
}
void BST::del(int x){
    root=dell(root,x);
}
void BST::inorder(){
    //LNR
    if(root!=nullptr){
        root=root->left;
        inorder();
        cout<<root->data;
        root=root->right;
        inorder();
    }
}
void BST::postorder(){
    //LRN
    if(root!=nullptr){
        root=root->left;
        postorder();
        root=root->right;
        postorder();
        cout<<root->data;
    }
}
void BST::preorder(){
    //NLR
    if(root!=nullptr){
        cout<<root->data;
        root=root->left;
        inorder();
        root=root->right;
        inorder();
    }
}
main(){
    
}