#include<bits/stdc++.h>

using namespace std;
//#define int long long
typedef long long LL;
#define ii __int128

//const int M=4010;
#define mp make_pair
#define endl '\n'
#define PI 3.14159265358979323846
std::mt19937 rd(std::chrono::steady_clock::now().time_since_epoch().count());
typedef unsigned long long ull;

//const int mod=1e9+7;
const int mod=998244353;

struct DSU
{
    vector<int> f, siz;
    DSU(int n){init(n);}
    void init(int n) 
    {
        f.resize(n+1);
        iota(f.begin(), f.end(), 0);
        siz.assign(n+1,1);
    }
    int find(int x)
    {
        while(x!=f[x])
        {
            x=f[x]=f[f[x]];
        }
        return x;
    }
    bool same(int x,int y)
    {
        return find(x)==find(y);
    }
    bool merge(int x,int y)
    {
        x=find(x);
        y=find(y);
        if (x==y) {
            return false;
        }
        siz[x]+=siz[y];
        f[y]=x;
        return true;
    }
    int size(int x)
    {
        return siz[find(x)];
    }
};

inline int Mod(int a)
{
    return a>=mod?a-mod:a;
}

int pw(int a,int k)
{
    int now=1;
    for(;k;k>>=1)
    {
        if(k&1) now=1ll*now*a%mod;
        a=1ll*a*a%mod;
    }
    return now;
}

struct CCC
{
    int n;
    vector<int> jc,inv;
    CCC(int nn):n(nn),jc(nn+1),inv(nn+1){init();};
    void init()
    {
        jc[0]=jc[1]=1;
        for(int i=2;i<=n;i++) jc[i]=1ll*jc[i-1]*i%mod;
        inv[0]=1;
        inv[n]=pw(jc[n],mod-2);
        for(int i=n-1;i>=1;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
    }
    int pw(int a,int k)
    {
        int ans=1;
        for(;k;k>>=1)
        {
            if(k&1) ans=1ll*ans*a%mod;
            a=1ll*a*a%mod;
        }
        return ans;
    }
    int C(int n,int m)
    {
        return 1ll*jc[n]*inv[m]%mod*inv[n-m]%mod;
    }
    int A(int n,int m)
    {
        return 1ll*jc[n]*inv[n-m]%mod;
    }
};

void add(int &a,int b)
{
    a=Mod(a+b);
}

void sub(int &a,int b)
{
    a=(a>=b?a-b:a-b+mod);
}

void maxx(int &a,int b)
{
	a=max(a,b);
}

void minn(int &a,int b)
{
	a=min(a,b);
}

struct seg
{
	vector<int> tl,tr,tmid,la,t;
	seg(int n):tl(n<<3),tr(n<<3),tmid(n<<3),la(n<<3),t(n<<3){build(1,1,n);}
	void rep(int a)
	{
		t[a]=t[a<<1]+t[a<<1|1];
	}
	void build(int a,int l,int r)
	{
		tl[a]=l,tr[a]=r,tmid[a]=(l+r)>>1;
		if(l==r)
		{
			return ;
		}
		build(a<<1,l,tmid[a]),build(a<<1|1,tmid[a]+1,r);
		rep(a);
	}
	void push(int a,int d)
	{
		t[a]+=d;
	}
	void pd(int a)
	{
		if(la[a]) set(a<<1),set(a<<1|1),la[a]=0;
	}
	void add(int a,int l,int r,int d)
	{
		if(tl[a]>=l&&tr[a]<=r)
		{
			return push(a,d);
		}
		pd(a);
		if(tmid[a]>=l) add(a<<1,l,r,d);
		if(tmid[a]<r) add(a<<1|1,l,r,d);
		rep(a);
	}
	int find(int a,int l,int r)
	{
		if(tl[a]>=l&&tr[a]<=r) return t[a];
		pd(a);
		if(tmid[a]>=r) return find(a<<1,l,r);
		if(tmid[a]<l) return find(a<<1|1,l,r);
		return find(a<<1,l,r)+find(a<<1|1,l,r);
	}
	void set(int a)
	{
		t[a]=0,la[a]=1;
	}
	void erase(int a,int l,int r)
	{
		if(tl[a]>=l&&tr[a]<=r)
		{
			return set(a);
		}
		pd(a);
		if(tmid[a]>=l) erase(a<<1,l,r);
		if(tmid[a]<r) erase(a<<1|1,l,r);
		rep(a);
	}
};

void solve()
{
    int n,k;
	cin>>n>>k;
	vector<int> t(n+1);
	for(int i=1;i<=n;i++) cin>>t[i];
	vector<int> num(n+2);
	for(int i=1;i<=n;i++) ++num[t[i]];
	if(k==1)
	{
		int j=-1;
		while(num[++j]);
		LL ans=0;int tmp=0;
		for(int i=0;i<j;i++)
		{
			if(num[i]==1) ans+=i,++tmp;
		}
		ans+=1ll*(n-tmp)*(j);
		cout<<ans<<endl;
		return ;
	}
	int j=-1;
	while(num[++j]==1);
	LL ans=0;int tmp=0;
	for(int i=0;i<j;i++)
	{
		if(num[i]==1) ans+=i,++tmp;
	}
	if(!num[j]) ++k;
	if((k&1)&&(n-tmp!=1)) ans+=1ll*(n-tmp)*(j+1);
	else ans+=1ll*(n-tmp)*(j);
	cout<<ans<<endl;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T=1;
	cin>>T;
    while(T--) solve();
}
