#include<bits/stdc++.h>
#define ll long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#define N 100000
#define mod 1000000007
 
template <typename T>
void print(T x){cout<<x<<"\n";}
template <typename T1, typename T2>
void print2(T1 x,T2 y){cout<<x<<" "<<y<<"\n";}
template <typename T1, typename T2,typename T3>
void print3(T1 x, T2 y,T3 z){cout<<x<<" "<<y<<" "<<z<<"\n";}

int main()
{
    io;
    ll test_case;
    //cin>>test_case;
    test_case=1;
    while(test_case--)
    {
        ll n,m,k;
        cin>>n>>m>>k;
        ll a[n],a1[m];
        for(int i=0;i<n;i++) cin>>a[i];
        for(int j=0;j<m;j++) cin>>a1[j];
        vector<pair<ll,ll> >res;
        bool flag=true;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                res.push_back({a[i],a1[j]});
                if(res.size()==k)
                {
                    flag=false;
                    break;
                }
            }
            if(!flag)
            break;
        }

        for(int i=0;i<res.size();i++)
        cout<<"["<<res[i].first<<","<<res[i].second<<"] ";
        cout<<"\n";
    }
}
