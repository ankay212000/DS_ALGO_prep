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

void rearrange(int arr[], int n) {
	vector<int> pos,neg;
	for(int i=0;i<n;i++)
	{
	    if(arr[i]>=0)
	    pos.push_back(arr[i]);
	    else
	    neg.push_back(arr[i]);
	}
	if(pos.size()>neg.size())
	{
	    int i=0,j=0,k=0,turn=0;
 
	    if(arr[0]>=0)
	    i++,k++,turn=0;
	    else
	    j++,k++,turn=1;
 
	    while(i<pos.size()&&j<neg.size())
	    {
	        if(turn==0)
	        arr[k]=neg[j],j++,turn=1;
	        else
	        arr[k]=pos[i],i++,turn=0;
	        k++;
	    }
        while(j<neg.size())
        {
            arr[k]=neg[j];
            k++;
            j++;
        }
	    while(i<pos.size())
	    {
	        arr[k]=pos[i];
	        k++;
	        i++;
	    }     
	}
	else
	{
	    int i=0,j=0,k=0,turn=0;
 
	    if(arr[0]>=0)
	    i++,k++,turn=1;
	    else
	    j++,k++,turn=0;

	    while(i<pos.size()&&j<neg.size())
	    {
	        if(turn==0)
	        arr[k]=pos[i],i++,turn=1;
	        else
	        arr[k]=neg[j],j++,turn=0;
	        k++;
	    }
        while(i<pos.size())
        {
            arr[k]=pos[i];
            k++;
            i++;
        }
 
	    while(j<neg.size())
	    {
	        arr[k]=neg[j];
	        k++;
	        j++;
	    }
	}
}

int main()
{
    io;
    ll test_case;
    //cin>>test_case;
    test_case=1;
    while(test_case--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        rearrange(arr,n);
        for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
        cout<<"\n";
    }
}
