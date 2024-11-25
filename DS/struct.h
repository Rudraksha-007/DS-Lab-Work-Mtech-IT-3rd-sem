#ifndef MYSTRUCT_H
#define MYSTRUCT_H

struct node
{
    int data;
    node*next;
    node(int x){
        next=nullptr;
        data=x;
    }
};

#endif // MYSTRUCT_H