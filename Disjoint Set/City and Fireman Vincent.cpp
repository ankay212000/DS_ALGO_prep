#include<bits/stdc++.h>
#define int long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define N 1000
#define mod 1000000007
using namespace std;

template <typename T>
void print(T x){cout<<x<<"\n";}
template <typename T1, typename T2>
void print2(T1 x,T2 y){cout<<x<<" "<<y<<"\n";}
template <typename T1, typename T2,typename T3>
void print3(T1 x, T2 y,T3 z){cout<<x<<" "<<y<<" "<<z<<"\n";}

vector<int> nodes[N+1];
bool isVisited[N+1];
vector<int> freq(N+1,0);

int dfs(int x,vector<int> E)
{
    isVisited[x]=true;
    int min_risk=E[x];
    freq[E[x]]++;
    for(auto i:nodes[x])
    {
        if(!isVisited[i])
        min_risk=min(min_risk,dfs(i,E));
    }

    return min_risk;    
}

signed main()
{
    io;
    int test_case;
    //cin>>test_case;
    test_case=1;
    while(test_case--)
    {
        int n;
        cin>>n;
        vector<int> E(n+1);
        for(int i=1;i<=n;i++) cin>>E[i];
        int q;
        cin>>q;

        int a,b;
        for(int i=0;i<q;i++)
        {
            cin>>a>>b;
            nodes[a].push_back(b);
            nodes[b].push_back(a);
        }

        int ans=1;
        for(int i=1;i<=n;i++)
        {
            if(!isVisited[i])
            {
                for(int j=0;j<=1000;j++)
                freq[j]=0;
                int min_risk=dfs(i,E);
                //cout<<min_risk<<"\n";
                ans=(ans*freq[min_risk])%mod;
            }
        }

        cout<<ans<<"\n";
    }   
}
