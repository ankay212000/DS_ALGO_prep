#include<bits/stdc++.h>
#define int long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define N 1000000
using namespace std;

template <typename T>
void print(T x){cout<<x<<"\n";}
template <typename T1, typename T2>
void print2(T1 x,T2 y){cout<<x<<" "<<y<<"\n";}
template <typename T1, typename T2,typename T3>
void print3(T1 x, T2 y,T3 z){cout<<x<<" "<<y<<" "<<z<<"\n";}

void insert_at_bottom(stack<int> &s,int key)
{
    if(s.size()==0)
    {
        s.push(key);
        return;
    }    

    int a=s.top();
    s.pop();
    insert_at_bottom(s,a);
    return;
}

void reverse(stack<int> &s)
{
    if(s.size()==0)
    return;
    
    int a=s.top();
    s.pop();
    reverse(s);

    insert_at_bottom(s,a);
    return;
}

signed main()
{
    io;
    int test_case;
    //cin>>test_case;
    test_case=1;
    while(test_case--)
    {
        int n,temp;
        cin>>n;
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            s.push(temp);
        }
        
        reverse(s);
        while(s.size())
        {
            cout<<s.top()<<" ";
            s.pop();
        }
    }
}
