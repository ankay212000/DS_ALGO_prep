#include<bits/stdc++.h>
#define ll long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#define limit 10000


int main()
{
    io;
    ll test_case;
    cin>>test_case;
    while(test_case--)
    {
        int N;
        cin>>N;
        int arr[N][N];
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            cin>>arr[i][j];
        }
        
        int temp;
        for(int i=0;i<N/2;i++)
        {
            for(int j=i;j<N-i-1;j++)
            {
                temp=arr[i][j];
                arr[i][j]=arr[j][N-i-1];
                arr[j][N-i-1]=arr[N-i-1][N-j-1];
                arr[N-i-1][N-j-1]=arr[N-j-1][i];
                arr[N-j-1][i]=temp;
            }
        }
        
        for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        cout<<arr[i][j]<<" ";
        cout<<"\n";
    }
}
