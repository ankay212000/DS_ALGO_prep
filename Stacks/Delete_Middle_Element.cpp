void deleteMiddle(stack<int> &s,int mid)
    {
        if(s.size()==mid)
        {
            s.pop();
            return;
        }

        int a=s.top();
        s.pop();
        deleteMiddle(s,mid);

        s.push(a);
        return;    
    }
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        deleteMiddle(s,(sizeOfStack-sizeOfStack/2));
        //reverse(s);
        while(s.size())
        {
            cout<<s.top()<<" ";
            s.pop();
        }
    }
