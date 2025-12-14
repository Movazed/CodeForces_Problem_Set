#include<bits/stdc++.h>
using namespace std;

const int N=2e5+7;
int fa[N<<1],siz[N<<1];

int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y) return;
	fa[x]=y,siz[y]+=siz[x],siz[x]=0;
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int T,n,m,i,x,y,ans;
	char s[10];
	
	for(cin>>T;T--;)
	{
		cin>>n>>m;
		for(i=1;i<=n<<1;++i) fa[i]=i,siz[i]=i<=n;
		
		while(m--)
		{
			cin>>x>>y>>s;
			if(s[0]=='c') merge(x,y),merge(x+n,y+n);
			else          merge(x+n,y),merge(x,y+n);
		}
		
		ans=0;
		for(i=1;i<=n;++i)
		{
			if((x=find(i))==(y=find(i+n))) goto GG;
			ans+=max(siz[x],siz[y]);
			siz[x]=siz[y]=0;
		}
		
		cout<<ans<<'\n';
		continue;
		
		GG:cout<<"-1\n";
	}
	
	return 0;
}