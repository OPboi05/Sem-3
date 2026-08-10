#include <bits/stdc++.h>
using namespace std;

struct Block{
    int arr[512];
    Block* next;
    int first;
    int last;
    
    Block()
    {
        next=nullptr;
        first=0;
        last=0;
    }
    
    bool push(int x)
    {
        if(last==512)
            return 0;
        arr[last]=x;
        last++;
        return 1;
    }
    
    bool pop(int &x)
    {
        if(first==last)
            return 0;
        x=arr[first++];
        return 1;
    }
    
    int front()
    {
        return arr[first];
    }
    
    bool empty()
    {
        return (first==last);
    }
};



struct Queue{
    Block* head;
    Block* tail;
    int size;
    
    Queue()
    {
        size=0;
        head=tail=new Block();
    }
    
    void push(int x)
    {
        if(!tail->push(x))
        {
            tail->next=new Block();
            tail=tail->next;
            tail->push(x);
        }
        size++;
    }
    
    int pop()
    {
        int tmp;
        if(!head->pop(tmp))
        {
            Block* nxt=head->next;
            delete head;
            head=nxt;
            head->pop(tmp);
        }
        size--;
        return tmp;
    }
    
    int front()
    {
        if(head->empty())
            return head->next->front();
        return head->front();
    }
    
    bool empty()
    {
        return (size==0);
    }
};



int main()
{
    Queue q;
    int n=2000;
    while(n--)
        q.push(n);
    
    while(!q.empty())
    {
        cout<<q.size<<" ";
        cout<<q.front()<<" ";
        cout<<q.pop()<<endl;
    }
}