void insert(stack<int> &s,int key)
{
    if(s.size()==0||s.top()<=key)
    {
        s.push(key);
        return ;
    }
    
    int val=s.top();
    s.pop();
    insert(s,key);
    s.push(val);
    
    return ;
}

void sortit(stack<int> &s)
{
    if(s.size()==1)
    return ;
    
    int val=s.top();
    s.pop();
    sortit(s);
    insert(s,val);
    
    return ;
    
}

void SortedStack :: sort()
{
   sortit(s);
   while(s.size())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    
    return ;
}
