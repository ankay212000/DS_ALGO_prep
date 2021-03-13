#include<bits/stdc++.h>
#define int long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#define N 10000000
#define limit 10000

template <typename T>
void print(T x){cout<<x<<"\n";}
template <typename T1, typename T2>
void print2(T1 x,T2 y){cout<<x<<" "<<y<<"\n";}
template <typename T1, typename T2,typename T3>
void print3(T1 x, T2 y,T3 z){cout<<x<<" "<<y<<" "<<z<<"\n";}

signed main()
{
    io;
    int test_case;
    cin>>test_case;
    //test_case=1;
    while (test_case--)
    {
       int n;
       cin>>n;
       vector<int> arr(n);
       for(int i=0;i<n;i++) cin>>arr[i];

       stack<int> s;
       vector<int>left(n);
       vector<int>right(n);

       for(int i=0;i<n;i++)
       {
           while(s.size()>0 && s.top()<arr[i])
           s.pop();

           if(s.size()>0)
           left[i]=s.top();
           else
           left[i]=-1;

           s.push(arr[i]);
       }

       while (s.size()>0)
       s.pop();

       for(int i=n-1;i>=0;i--)
       {
           while(s.size()>0 && s.top()<arr[i])
           s.pop();

           if(s.size()>0)
           right[i]=s.top();
           else
           right[i]=-1;

           s.push(arr[i]);
       }

       set<int> ans;
       for(int i=0;i<n;i++)
       {
           if(left[i]!=-1)
           ans.insert(left[i]-arr[i]);
           if(right[i]!=-1)
           ans.insert(right[i]-arr[i]);
       }

       print(ans.size());
    }

}
