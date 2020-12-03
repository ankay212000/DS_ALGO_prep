void maxMeetings(int start[], int end[], int n) {
    vector<pair<int,pair<int,int> >> store(n);
    for(int i=0;i<n;i++)
        store[i]={end[i],{start[i],i+1}};
    
    sort(store.begin(),store.end());
    
    cout<<store[0].second.second<<" ";
    int i=0,j;
    for(int j=1;j<n;j++)
    {
        if(store[i].first<=store[j].second.first)
        {
            cout<<store[j].second.second<<" ";
            i=j;
        }
    }
    
}
