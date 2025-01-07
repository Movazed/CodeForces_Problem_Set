#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define vi vector<ll>
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define pii pair<ll,ll>
#define vii vector<pii>
#define calc_fact(n) tgamma(n+1)
#define inf LONG_LONG_MAX
#define MOD 1000000007
#define mod 998244353

signed main()
{
	FIO;
	
	ll n,q;
	cin>>n>>q;
	
	vi index(55,inf);
	
	for(ll i=0;i<n;i++)
	{
	    ll color;
	    cin>>color;
	    
	    // find the minimum index for each distinct color
	    index[color] = min(index[color],i+1);
	}
	
	while(q--)
	{
	    ll color;
	    cin>>color;
	    
	    cout<<index[color]<<" ";
	    
	    // for each color, if it's minimum index is less than current minimum index
	    // increase it's index by 1
	    
	    for(ll i=1;i<=50;i++)
	    {
	        if(index[i]<index[color])index[i]++;
	    }
	    
	    // current color is at top of stack
	    index[color] = 1;
	}
}