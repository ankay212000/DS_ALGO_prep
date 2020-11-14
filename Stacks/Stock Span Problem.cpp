#include<bits/stdc++.h>
#define ll long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#define N 100000000
#define limit 10000

int main()
{
    io;
    ll test_case;
    cin>>test_case;
    while(test_case--)
    {
        int n;
        cin>>n;
        vector<int> stock(n);
        
        for(int i=0;i<n;i++) cin>>stock[i];
        vector<int> ans(n);
        
        stack<int> st;
        st.push(0);
        
        ans[0]=1;
        
        for(int i=1;i<n;i++)
        {
            while(st.empty()==false&&stock[st.top()]<=stock[i])
            st.pop();
            
            ans[i]=st.empty()?(i+1):(i-st.top());
            st.push(i);
        }
        
        for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
        cout<<"\n";
    }
}
