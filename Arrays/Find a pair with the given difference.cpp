#include<bits/stdc++.h>
#define ll long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#define N 100000
#define limit 10000
 
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
        int n,d,temp;
        cin>>n>>d;
        unordered_map<int,int> pairs;
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            if(pairs.find(temp+d)!=pairs.end())
            {
                cout<<"Pair Found: ("<<temp<<","<<temp+d<<")";
                flag=true;
            }
            else if(pairs.find(abs(temp-d))!=pairs.end())
            {
                cout<<"Pair Found: ("<<temp-d<<","<<temp<<")";
                flag=true;
            }
            else
            pairs[temp]=1;
        }
        if(!flag)
        print("No pair found"); 
    }
}
