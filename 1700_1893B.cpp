#include <bits/stdc++.h>
using namespace std;
int a[200005],b[200005],c[400005];
int main()
{
	int t,n,m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=0;i<n;++i)
			cin>>a[i];
		for(int i=0;i<m;++i)
			cin>>b[i];
		sort(b,b+m,greater<int>() );
		merge(a,a+n,b,b+m,c,greater<int>()); 
		for(int i=0;i<n+m;++i)
			cout<<c[i]<<' ';
		cout<<endl;
	}
	
}