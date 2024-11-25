#include<bits/stdc++.h>
// #include<Endsemfile\DS\struct.h>
using namespace std;
//implementing a stack using array
class stack_Arr{
    int *arr;
    int top,size;
    public:
    stack_Arr(int x){
        arr=new int[x];
        top=-1;
        size=x;
    }
    void push(int);
    void display();
    int pop();
};
struct node
{
    int data;
    node*next;
    node(int x){
        next=nullptr;
        data=x;
    }
};
void stack_Arr::push(int data){
    if(top==size-1){
        cout<<"Stack Overflow\n";
    }
    else{
        top++;
        arr[top]=data;
    }
}
int stack_Arr::pop(){
    if(top==-1){
        cout<<"Stack Underflow\n";
        return -1;
    }else{
        int data=arr[top];
        top--;
        return data;
    }
}
void stack_Arr::display(){
    if(top==-1){
        cout<<"stack is empty\n";
    }
    for(int i=0;i<=top;i++){
        cout<<arr[i]<<"\t";
    }
}
//implementing a stack using linkedlist
class stack_Linkedlist{
    node*top;
    int size;
    public:
    stack_Linkedlist(){top=nullptr;}
    void push(int);
    void display();
    int pop();
};
void stack_Linkedlist::push(int data){
    node*t=new node(data);
    if(top==nullptr){
        top=t;
    }
    else{
        t->next=top;
        top=t;
    }
}
int stack_Linkedlist::pop(){
    if(top==nullptr){
        cout<<"Stack is empty\n";
        return -1;
    }
    else{
        int data=top->data;
        node*getrid=top;
        top=top->next;
        delete getrid;
        return data;
    }
}

int main(){
    stack_Arr s(10);
    char c;
    // do{
    //     cout<<"enter choise p-> push and P-> pop";
    //     cin>>c;
    //     if(c=='p'){
    //         int data;
    //         cout<<"Enter data to push\n";
    //         cin>>data;
    //         s.push(data);
    //     }else if(c=='P'){
    //         int data=s.pop();
    //         cout<<"Popped data : "<<data<<endl;
    //     }
    //     else{
    //         cout<<"fuck you!\n";
    //     }
    // }while(c=='p' or c=='P');

    stack_Linkedlist sl();
    do{
        cout<<"enter choise p-> push and P-> pop\n";
        cin>>c;
        if(c=='p'){
            int data;
            cout<<"Enter data to push\n";
            cin>>data;
            s.push(data);
        }else if(c=='P'){
            int data=s.pop();
            cout<<"Popped data : "<<data<<endl;
        }
        else{
            cout<<"fuck you!\n";
        }
    }while(c=='p' or c=='P');

    return 0;
}