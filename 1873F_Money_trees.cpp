#include<bits/stdc++.h>
using namespace std;
int t,n,k,a[200005],h[200005],s[200005];
int main(){
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			s[i]=s[i-1]+a[i];
		}
		for(int i=1;i<=n;i++)cin>>h[i];
		int ma=0,l,r;
		l=r=1;
		while(r<=n){
			if(h[r-1]%h[r])l=r;
			while(s[r]-s[l-1]>k)l++;
			ma=max(ma,r-l+1);
			r++;
		}
		cout<<ma<<'\n';
	}
}