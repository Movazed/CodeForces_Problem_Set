#include<iostream>
#include<map>
#define int long long
using namespace std;
const int N=1e5+5,K=20;
int n,m,a[N],ans[N],x[N],y[N];
struct yuno
{
	map<int,int>mp;
	void init(){mp.clear();}
	void ins(int x){++mp[x];}
	void del(int x){if(!--mp[x])mp.erase(x);}
}res;
struct dat
{
	int k,siz;map<int,int>mp;
	void init(int x){k=x,siz=0,mp.clear();}
	void ins(int x,int c=1){res.del(get()),mp[x]+=c,siz+=c,res.ins(get());}
	void del(int x){res.del(get());if(!--mp[x])mp.erase(x);--siz;res.ins(get());}
	int get(){return mp.size()==k?siz:0;}
};
struct bocchi
{
	int fa[N],k;dat d[N];
	void init(int x){k=1<<x;for(int i=1;i<=n;++i)fa[i]=i,d[i].init(k);}
	int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
	void uni(int u,int v)
	{
		u=find(u),v=find(v);
		if(u==v)return;
		if(d[u].mp.size()<d[v].mp.size())swap(u,v);
		res.del(d[v].get());fa[v]=u;
		for(auto [x,c]:d[v].mp)d[u].ins(x,c);
	}
	void add(int x,int y,int z)
	{
		x=find(x);
		if(y<k)d[x].del(y);
		if(z<k)d[x].ins(z);
	}
	void chk(int x)
	{
		if(a[x]<k&&a[x-1]<k)uni(x,x-1);
		if(a[x]<k&&a[x+1]<k)uni(x,x+1);
	}
}b[K];
void ATRI()
{
	cin>>n>>m;
	res.init();a[0]=a[n+1]=1e18;
	for(int k=0;k<K;++k)b[k].init(k);
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=m;++i)cin>>x[i]>>y[i],a[x[i]]+=y[i];
	for(int i=1;i<=n;++i)for(int k=0;k<K;++k)res.ins(0);
	for(int i=1;i<=n;++i)for(int k=0;k<K;++k)b[k].add(i,1e18,a[i]);
	for(int i=1;i<=n;++i)for(int k=0;k<K;++k)b[k].chk(i);
	for(int i=m;i>=1;--i)
	{
		ans[i]=prev(res.mp.end())->first;
		for(int k=0;k<K;++k)b[k].add(x[i],a[x[i]],a[x[i]]-y[i]);
		a[x[i]]-=y[i];
		for(int k=0;k<K;++k)b[k].chk(x[i]);
	}
	for(int i=1;i<=m;++i)cout<<ans[i]<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;while(t--)ATRI();
	return 0;
}
