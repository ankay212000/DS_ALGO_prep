#include<bits/stdc++.h>
#define ll long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#define N 100000
#define limit 10000

int lcm(int a,int b)
{
    return a*b/__gcd(a,b);
}

void solve(int nr,int dr)
{
    if(nr==1)
    {
        cout<<"1/"<<dr;
        return;
    }

    int first=ceil((float)dr/(float)nr);
    cout<<"1/"<<first<<" + ";
    int l=lcm(first,dr);
    nr=nr*l/dr-l/first;
    dr=l;
    int div=__gcd(nr,dr);

    return solve(nr/div,dr/div); 
}

int main()
{
    io;
    ll test_case;
    //cin>>test_case;
    test_case=1;
    while(test_case--)
    {
        int nr,dr;
        cin>>nr>>dr;
        solve(nr,dr); 
    }
}
