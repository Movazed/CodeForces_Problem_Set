#include<bits/stdc++.h>
#define ll long long
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
ll T,n,a[200005],ans;
signed main(){
	cin>>T;
	while(T--){
		cin>>n;a[n+1]=ans=0;
		for(ll i=1;i<=n;i++)cin>>a[i];
		for(ll i=2;i<=n;i+=2){
			if(a[i]<a[i-1]+a[i+1]){
				ans+=a[i+1]+a[i-1]-a[i];
				a[i+1]=max(a[i]-a[i-1],0ll);
			}
		}cout<<ans<<"\n";
	}
}