/*
#####################################
############# smurf_dkyu ###############
#####################################

 ------------------------------------
|  "I CREATE BUGS WHEN I'm BORED"    |
 ------------------------------------
|  "I SUCK AT CP,BUT I LIKE TO TRY"  |
 ------------------------------------

*/


#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pub push_back
#define pob pop_back
#define mod 1000000007
#define N 300000

using namespace std;

bool isVisited[N+1];
vector<ll> nodes[N+1];
ll num[N+1];
ll subtree[N+1],hei[N+1];

void initialise2(ll n)
{
    for(ll i=1;i<=N;i++)
    {
        isVisited[i]=false;
        num[i]=0;
        nodes[i].clear();
        subtree[i]=0;
    }
}

ll dfs(ll x,ll p)
{
    isVisited[x]=true;
    multiset<ll> s;
    for(auto i: nodes[x])
    {
        if(!isVisited[i])
            s.insert(dfs(i,x));
    }

    ll res=1,val=1;
    for(auto i= s.rbegin();i!=s.rend();i++)
    res+=(val++)*(*i);

    return res;
}


void solve()
{
    ll n,x;
    cin>>n>>x;
    initialise2(n);
    ll a,b;
    for(ll i=1;i<n;i++)
    {
        cin>>a>>b;
        nodes[a].pub(b);
        nodes[b].pub(a);
    }
    
    ll ans=dfs(1,-1);
    ans%=mod;
    cout<<(ans*x)%mod<<"\n";
    return ;
}

int main()
{
    io;
    ll test_case;
    cin>>test_case;
    while(test_case--)
    {
        solve();
    }
}
