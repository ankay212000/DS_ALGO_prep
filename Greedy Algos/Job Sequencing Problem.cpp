bool compare(Job a,Job b)
{
    if(a.profit>=b.profit)
    return true;
    
    return false;    
}

pair<int,int> JobScheduling(Job arr[], int n) 
{ 
    bool store[n+1]={false};
    int res=0,ans=0;
    
    sort(arr,arr+n,compare);
    
    for(int i=0;i<n;i++)
    {
        for(int j=min(n,arr[i].dead)-1;j>=0;j--)
        {
            if(!store[j])
            {
                store[j]=true;
                ans+=arr[i].profit;
                res++;
                break;
            }
        }
    }
    pair<int,int> out={res,ans};
    return out;
} 
