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
    cin>>test_case;
    //test_case=1;
    while(test_case--)
    {
        int n;
        cin>>n;
        int price[n];
        
        for(int i=0;i<n;i++) cin>>price[i];
        vector<pair<int,int> > res;
        int i = 0; 
        while (i < n - 1) { 
            while ((i < n - 1) && (price[i + 1] <= price[i])) 
                i++; 
  
            if (i == n - 1) 
                break;  
            int buy = i++;  
            while ((i < n) && (price[i] >= price[i - 1])) 
                i++;  
            int sell = i - 1; 
  
            res.push_back({buy,sell}); 
        }
        if(res.size()==0)
        {
            print("No Profit");
            continue;
        } 

        for(int i=0;i<res.size();i++)
        cout<<"("<<res[i].first<<" "<<res[i].second<<") ";

        cout<<"\n";
    }
}
