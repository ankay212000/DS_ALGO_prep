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

int max_s;
int min_s;
struct dsu{
    vector<int> par;
    vector<int> siz;
    void initialise(int n)
    {
        par.assign(n+1,-1);
        siz.assign(n+1,1);
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

        if(siz[a]>siz[b])
        swap(a,b);

        siz[b]+=siz[a];
        par[a]=b;
        max_s=max({max_s,siz[b],siz[a]});
        min_s=min({min_s,siz[b],siz[a]});
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
        dsu d1;
        int n,q;
        cin>>n>>q;
        
        d1.initialise(n);
        int a,b;
        set<int> check;
        max_s=1;
        min_s=1;
        for(int i=1;i<=q;i++)
        {
            cin>>a>>b;
            check.insert(a);
            check.insert(b);

            if(check.size()==n)
            cout<<0<<"\n";
            else if(d1.find(a)==d1.find(b))
            cout<<max_s-min_s<<"\n";
            else
            {
                d1.merge(a,b);
                cout<<max_s-min_s<<"\n";
            }
        }
    }   
}
