/*
#####################################
############# dkyu021 ###############
#####################################

 ------------------------------------
|  "I CREATE BUGS WHEN I'm BORED"    |
 ------------------------------------
|  "I SUCK AT CP,BUT I LIKE TO TRY"  |
 ------------------------------------

*/


#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pub push_back
#define pob pop_back
#define mod 1000000007
#define N 50

using namespace std;

/*bool notprime[N+1];
vector<ll> primes;

void sieve()
{
    for(int i=2;i*i<=N;i++)
    {
        if(!notprime[i])
        for(int j=2*i;j<=N;j+=i)
        notprime[j]=true;
    }

    for(int i=2;i<=N;i++)
    if(!notprime[i])
    primes.pub(i);
}

ll power(ll x, ll y,ll p)
{
    ll res = 1;
    x = x % p; 
    if (x == 0) return 0;
 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}*/

void solve()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;

    stack<int> bra;
    string p="";
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
        bra.push(s[i]);
        else
        {
            if(!bra.empty())
            bra.pop();
            else
            p+=")";
        }
    }
    cout<<p.size()<<"\n";
    return ;
}

int main()
{
    io;
    ll test_case;
    cin>>test_case;
    //sieve();
    //test_case=1;
    while(test_case--)
    {
        solve();
    }
}
