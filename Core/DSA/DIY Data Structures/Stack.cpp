#include <bits/stdc++.h>
using namespace std;

struct Block{
    int arr[512];
    Block* prev;
    int occupied;
    
    Block()
    {
        occupied=0;
        prev=nullptr;
    }
    
    bool push(int x)
    {
        if(occupied==512)
            return 0;
        
        arr[occupied]=x;
        occupied++;
        return 1;
    }
    
    bool pop(int &x)
    {
        if(occupied==0)
            return 0;
        occupied--;
        x=arr[occupied];
        return 1;
    }
    
    int top()
    {
        return arr[occupied-1];
    }
    
    bool empty()
    {
        return (occupied==0);
    }

};

struct Stack{
    Block *head;
    int size;
    Block* extra;
    
    Stack()
    {
        head=new Block();
        size=0;
        extra=nullptr;
    }
    
    ~Stack()
    {
        if(extra)
            delete extra;
        while(head)
        {
            Block* tmp=head->prev;
            delete head;
            head=tmp;
        }
    }
    
    void push(int x)
    {
        if(!head->push(x))
        {
            Block* tmp;
            
            if(extra)
                tmp=extra,extra=nullptr;
            else
                tmp=new Block();

            tmp->prev=head;
            head=tmp;
            head->push(x);
        }
        size++;
    }
    
    bool pop(int &x)
    {
        if(size==0)
            return 0;
        if(!head->pop(x))
        {
            if(extra)
                delete extra;
            extra=head;
            head=head->prev;
            head->pop(x);
        }
        size--;
        return 1;
    }
    
    bool empty()
    {
        return (size==0);
    }
    
};

int main()
{
    Stack s;
    int n=512;
    while(n--)
        s.push(n);
    
    for(int i=0;i<10000;i++)
    {
        s.push(i);
        
        int x;
        s.pop(x);
        cout<<x<<endl;
    }
}