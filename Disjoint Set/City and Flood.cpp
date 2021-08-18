#include<bits/stdc++.h>
#define int long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define N 100000
using namespace std;

template <typename T>
void print(T x){cout<<x<<"\n";}
template <typename T1, typename T2>
void print2(T1 x,T2 y){cout<<x<<" "<<y<<"\n";}
template <typename T1, typename T2,typename T3>
void print3(T1 x, T2 y,T3 z){cout<<x<<" "<<y<<" "<<z<<"\n";}

struct dsu{
    vector<int> par;
    vector<int> si;
    void init(int n)
    {
        par.assign(n+1,-1);
        si.assign(n+1,1);
    }

    int find(int a)
    {
        if(par[a]==-1)
        return a;
        return par[a]=find(par[a]);
    }

    void merge(int a,int b)
    {
        a=find(a);
        b=find(b);

        if(si[a]>si[b])
        swap(a,b);

        si[b]+=si[a];
        par[a]=b;
    }
};

signed main()
{
    io;
    int test_case;
    //cin>>test_case;
    test_case=1;
    while(test_case--)
    {
        int n,m;
        cin>>n>>m;

        dsu d1;
        d1.init(n);
        int a,b;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            d1.merge(a,b);
        }

        int cnt=0;
        for(int i=1;i<=n;i++)
        cnt+=(d1.par[i]<0);

        cout<<cnt<<"\n";
    }   
}
