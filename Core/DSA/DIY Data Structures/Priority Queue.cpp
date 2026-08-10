struct Node{
    Node* left;
    Node* right;
    Node* parent;
    int val;
    
    Node(int x,Node* par)
    {
        left=nullptr;
        right=nullptr;
        parent=par;
        val=x;
    }
};

struct Position{
    int depth;
    int num;
    
    Position()
    {
        depth=0;
        num=0;
    }   
    
    void next()
    {
        num++;
        if(num==(1<<depth))
        {
            depth++;
            num=0;
        }         
    }
    
    Position prev()
    {
        Position ans;
        if(num==0)
        {
            ans.depth=depth-1;
            ans.num=(1<<(depth-1))-1;
        }
        else
        {
            ans.depth=depth;
            ans.num=num-1;
        }
        return ans;
    }
    
    bool setBit(int i)
    {
        if((1<<i)&(num))
            return 1;
        else
            return 0;
    }
    
    
};

struct PriorityQueue{
    Node* root;
    int size;
    Position pos;
    
    PriorityQueue()
    {
        size=0;
        root=nullptr;
    }
    
    bool empty()
    {
        return (size==0);
    }
    
    void push(int x)
    {
        if(size==0)
        {
            root=new Node(x,nullptr);
            pos.next();
        }
        else
        {
            Node* tmp=root;
            for(int i=0;i<pos.depth-1;i++)
            {
                if(pos.setBit(i))
                    tmp=tmp->right;
                else
                    tmp=tmp->left;
            }
            if(pos.depth>0)
            {
                if(pos.setBit(pos.depth-1))
                {
                    tmp->right=new Node(x,tmp);
                    tmp=tmp->right;
                }
                else
                {
                    tmp->left=new Node(x,tmp);
                    tmp=tmp->left;
                }
            }
            while(tmp->parent)
            {
                if(tmp->val < tmp->parent->val)
                {
                    auto temp=tmp->parent;
                    swap(tmp->val,tmp->parent->val);
                    tmp=temp;
                }
                else
                    break;
            }
            pos.next();
        }
        size++;
    }
    
    int pop()
    {
        int ans=root->val;
        Position last=pos.prev();
        Node* tmp=root;
        
        for(int i=0;i<last.depth;i++)
        {
            if(last.setBit(i))
                tmp=tmp->right;
            else
                tmp=tmp->left;
        }

        if(size==1)
        {
            delete root;
            root=nullptr;
            size=0;
            pos.depth=0;
            pos.num=0;
            return ans;
        }

        root->val=tmp->val;
        Node* par=tmp->parent;

        if(par->left==tmp)
            par->left=nullptr;
        else
            par->right=nullptr;

        delete tmp;

        size--;
        pos=last;
        tmp=root;

        while(1)
        {
            Node* smallest=tmp;
            if(tmp->left && tmp->left->val<smallest->val)
                smallest=tmp->left;
            if(tmp->right && tmp->right->val<smallest->val)
                smallest=tmp->right;
            if(smallest==tmp)
                break;
            swap(tmp->val,smallest->val);
            tmp=smallest;
        }
        return ans;
    }
};

int main()
{
    PriorityQueue pq;
    int n=10;
    mt19937 rng(69);
    
    while(n--)
        pq.push(rng());
    
    while(!pq.empty())
        cout<<(pq.pop())<<endl;
}