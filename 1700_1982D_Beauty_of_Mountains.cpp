#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, a[1000][1000], m, k, T, sum, g, s[1000][1000];
bool b[1000][1000];
char ch;

int32_t main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cin>>T;
	while(T--){
		cin>>n>>m>>k,g=sum=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>ch,sum+=(ch=='1'?a[i][j]:-a[i][j]),s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+(ch=='1'?1:-1);
		for(int i=1;i<=n-k+1;i++)
			for(int j=1;j<=m-k+1;j++)
				g=__gcd(g,abs(s[i+k-1][j+k-1]-s[i-1][j+k-1]-s[i+k-1][j-1]+s[i-1][j-1]));
		cout<<(((g&&!(sum%g))||!sum)?"YES\n":"NO\n");
	}
	return 0;
}