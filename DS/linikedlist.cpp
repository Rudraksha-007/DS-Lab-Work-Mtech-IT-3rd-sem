#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
    node(int x)
    {
        next = nullptr;
        data = x;
    }
};

class List
{
    node *head;

public:
    List()
    {
        head = nullptr;
    }
    void prepend(int);
    void append(int);
    void insert(int, int);
    void del(int);
    void display();
    int count();
};
void List::display()
{
    for (node *it = head; it != nullptr; it = it->next)
    {
        cout << it->data << "\t";
    }
    cout << endl;
}
void List::prepend(int data)
{
    node *t = new node(data);
    if (head == nullptr)
    {
        head = t;
    }
    else
    {
        t->next = head;
        head = t;
    }
}
void List::append(int data)
{
    node *t = new node(data);
    if (head == nullptr)
    {
        head = t;
    }
    else
    {
        node *it = head;
        while (it->next != nullptr)
        {
            it = it->next;
        }
        it->next = t;
    }
}
int List::count()
{
    int c = 0;
    for (node *it = head; it != nullptr; it = it->next)
    {
        c++;
    }
    return c;
}
void List::insert(int pos, int data)
{ // 1 based indexing no '0's allowed
    node *t = new node(data);
    pos %= count();
    if (pos == 0)
    {
        return;
    }
    if (head == nullptr)
    {
        head = t;
    }
    else if (pos == 1)
    {
        t->next = head;
        head = t;
    }
    else
    {
        int c = 1;
        node *it = head;
        for (int i = 1; i < pos - 1 and it != nullptr; i++)
        {
            it = it->next;
        }
        if (it != nullptr)
        {
            node *n = it->next;
            it->next = t;
            t->next = n;
        }
    }
}
void List::del(int pos){
    if(head==nullptr){
        cout<<"List is empty\n";
        return;
    }
    else if(pos==1){
        node*getrid=head;
        head=getrid->next;
        delete getrid;
    }
    else {
        node*it=head;
        int i=1;
        while(i<pos-1){
            if(it==nullptr){
                cout<<"invalid position\n";
                return;
            }
            it=it->next;
            i++;
        }
        node*getrid=it->next;
        it->next=getrid->next;
        delete getrid;
    }
}
int main()
{
    List head;
    char c;
    do{
        cout<<"enter choise p->prepend a->append\ni->insert d->delete\nD->display\n";
        cin>>c;
        if(c=='a'){
            int data;
            cout<<"Enter data\n";
            cin>>data;
            head.append(data);
        }
        else if(c=='i'){
            int pos,data;
            cout<<"Enter pos\n";
            cin>>pos;
            cout<<"Enter data\n";
            cin>>data;
            head.insert(pos,data);
        }
        else if(c=='p'){
            int data;
            cout<<"Enter data\n";
            cin>>data;
            head.prepend(data);
        }
        else if(c=='d'){
            int pos;
            cout<<"Enter pos\n";
            cin>>pos;
            head.del(pos);
        }   
        else if(c=='D'){
            head.display();
        }
        else{
            cout<<"fuck you!\n";
            return 0;
        }
    }while(c);
    return 0;
}