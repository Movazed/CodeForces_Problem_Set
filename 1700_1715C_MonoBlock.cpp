#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100010];
int ans=0;
signed main() {
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++)
		ans+=(a[i]!=a[i+1])*i*(n-i);
	while(m--) {
		int i,x;
		cin>>i>>x;
		ans-=(a[i]!=a[i-1])*(i-1)*(n-i+1);
		ans+=(x!=a[i-1])*(i-1)*(n-i+1);
		ans-=(a[i]!=a[i+1])*i*(n-i);
		ans+=(x!=a[i+1])*i*(n-i);
		a[i]=x;
		cout<<ans+n*(n-1)/2+n<<endl;
	}
	return 0;
}

