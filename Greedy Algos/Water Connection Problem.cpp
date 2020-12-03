#include<bits/stdc++.h>
#define ll long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#define N 20
#define limit 10000

vector<pair<int,int>> nodes[N+1];

void dfs(int i,int *ans,int *end)
{
    if(nodes[i].size()==0)
    {
        *end=i;
        return;
    }

    *ans=min(*ans,nodes[i][0].second);
    for(auto x: nodes[i])
        dfs(x.first,ans,end);
}


int main()
{
    io;
    ll test_case;
    cin>>test_case;
    while(test_case--)
    {
        int n,p;
        cin>>n>>p;
        int a,b,dia;
        bool start[n+1];
        memset(start,true,sizeof(start));

        for(int i=0;i<p;i++)
        {
            cin>>a>>b>>dia;
            nodes[a].push_back({b,dia});
            //nodes[b].push_back({a,dia});
            start[b]=false;
        }
        
        int ans=INT_MAX;
        int end=0;
        vector<pair<int,pair<int,int>>> res;
        for(int i=1;i<=n;i++)
        {
            if(start[i]==true)
            {
                ans=INT_MAX;
                end=0;
                dfs(i,&ans,&end);
                if(ans!=INT_MAX)
                res.push_back({i,{end,ans}});
            }
        }
        cout<<res.size()<<"\n";

        for(auto x: res)
            cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<"\n";

        for(int i=1;i<=N;i++) nodes[i].clear();    
    }
}
