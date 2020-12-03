#include<bits/stdc++.h>
#define ll long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#define N 100000
#define limit 10000

int main()
{
    io;
    ll test_case;
    //cin>>test_case;
    test_case=1;
    while(test_case--)
    {
        int n,k;
        cin>>n;
        char temp;
        vector<int> police;
        vector<int> thieves;
        for(int i=0;i<n;i++){
            cin>>temp;
            if(temp=='T')
            thieves.push_back(i);
            else
            police.push_back(i);
        } 
        cin>>k;
        int l=0,r=0,res=0;
        while(l<police.size()&&r<thieves.size())
        {
            if(abs(police[l]-thieves[r])<=k)
            {
                res++;
                l++;
                r++;
            }
            else if(thieves[r]>police[l])
            l++;
            else
            r++;
        }

        cout<<res<<"\n";   
    }
}
