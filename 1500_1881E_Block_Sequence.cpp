#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,i,a[200005],dp[200005]={0};
		cin>>n;
		dp[n-1]=1;
		for(i=0;i<n;i++) cin>>a[i];
		for(i=n-2;i>=0;i--){
			if(i+1+a[i]<=n)dp[i]=min(dp[i+1]+1,dp[i+1+a[i]]);
			else dp[i]=dp[i+1]+1;
		}
		cout<<dp[0]<<endl;
	}
 }