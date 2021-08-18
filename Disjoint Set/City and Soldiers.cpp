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

int parent[N+1];

int find(int a)
{
    if(parent[a]==-1)
    return a;

    return parent[a]=find(parent[a]);
}

void merge(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a==b)
    return;
    parent[a]=b;
}

signed main()
{
    io;
    int test_case;
    //cin>>test_case;
    test_case=1;
    while(test_case--)
    {
        int n,q;
        cin>>n>>q;

        for(int i=0;i<=100000;i++)
        parent[i]=-1;
        
        int a,b,c;
        for(int i=0;i<q;i++)
        {
            cin>>a;
            if(a==1)
            {
                cin>>b>>c;
                merge(b,c);
            }
            else if(a==2)
            {
                cin>>b;
                int k=find(b);
                parent[k]=b;
                parent[b]=-1;
            }
            else
            {
                cin>>b;
                cout<<find(b)<<"\n";
            }
        }
    }   
}
