#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left, *right;
    node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};
void preorder(node *);  // NLR
void postorder(node *); // LRN
void inorder(node *);   // LNR
class BST
{
    node *root;

public:
    void insert(int);
    node *del(node *, int);
};
void preorder(node *root)
{
    if (root != nullptr)
    {
        // NLR
        cout << root->data << "\t";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node *root)
{
    if (root != nullptr)
    {
        // LRN
        postorder(root->left);
        postorder(root->right);
        cout << root->data << "\t";
    }
}
void inorder(node *root)
{
    if (root != nullptr)
    {
        // LNR
        inorder(root->left);
        cout << root->data << "\t";
        inorder(root->right);
    }
}
void BST::insert(int data)
{
    node *t = new node(data);
    if (root == nullptr)
    {
        root = t;
    }
    else
    {
        node *it = root, *prev = nullptr;
        while (it != nullptr)
        {
            prev = it;
            if (it->data > data)
            {
                it = it->left;
            }
            else
            {
                it = it->right;
            }
        }
        if (prev->data > data)
        {
            prev->left = t;
        }
        else
        {
            prev->right = t;
        }
    }
}
node *BST::del(node *root, int v)
{
    if (root == nullptr)
    {
        return root;
    }
    else if (root->data > v)
    {
        root->left = del(root->left, v);
    }
    else if (root->data < v)
    {
        root->right = del(root->right, v);
    }
    else
    {
        if (root->left == nullptr)
        {
            node *t = root->right;
            delete root;
            return t;
        }
        else if (root->right == nullptr)
        {
            node *t = root->left;
            delete root;
            return t;
        }
        else
        {
            node *t = root->right;
            while (t->left != nullptr)
            {
                t = t->left;
            }
            root->data = t->data;
            root->right = del(root->right, root->data);
        }
    }
    return root;
}
int main()
{
    return 0;
}