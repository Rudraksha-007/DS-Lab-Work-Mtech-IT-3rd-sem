#include<bits/stdc++.h>
using namespace std;
//implementing deque using array
class dque{
    int *arr,size,f,r;
    public:
    dque(int x):size(x){
        f=r=-1;
    }
    void push_front(int);
    void push_back(int);
    int pop_front();
    int pop_back();
    void display();
};
void dque::push_front(int x){
    if(r==(size+(f-1))%size){
        cout<<"Deque is full\n";
    }
    else{
        if(r==-1){
            f=r=0;
            arr[f]=x;        
        }
        else{
            f=(size+(f-1))%size;
            arr[f]=x;
        }
    }
}
void dque::push_back(int x){
    if(f==(r+1)%size){
        cout<<"Deque is full\n";
    }else{
        if(r==-1){
            f=r=0;
            arr[r]=x;
        }else{
            r=(r+1)%size;
            arr[r]=x;
        }
    }
}
int dque::pop_back(){
    if(r==-1){
        cout<<"Deque is empty\n";
        return -1;
    }else{
        int data=arr[r];
        if(f==r){
            f=r=-1;
        }
        else{
            r=(size+(r-1))%size;
        }
        return data;
    }
}
int dque::pop_front(){
    if(r==-1){
        cout<<"Deque is empty\n";
        return -1;
    }else{
        int data=arr[f];
        if(f==r){
            f=r=-1;
        }else{
            f=(f+1)%size;
        }
        return data;
    }
}
int main(){
    return 0;
}