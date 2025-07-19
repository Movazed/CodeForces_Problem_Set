#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast,unroll-loops") 
//#pragma GCC target("avx,avx2,avx512,fma") 

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
#define nl std::endl
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define ar array
#define ll long long
#define ld long double
#define vpll vector<pair<ll, ll>>
#define vll vector<ll>
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define PRINT std::cout 
#define PI 3.1415926535897932384626433832795l 
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
const int MAX_FACT = 1e5 + 5;  // Maximum size for factorials
int fact[MAX_FACT], ifact[MAX_FACT];



int c[2],i,x,t,n,p,j;
pair<int,int> a[2][1<<17];
#define F(i,n) for(i=0;i<n;++i)

void solve() {
    scanf("%d%d",&n,&p);
    F(i,n){
    scanf("%d%d",&t,&j);
    a[t&1][++c[t&1]]=make_pair(-j,i+1);
    }
    F(i,2)sort(a[i]+1,a[i]+c[i]+1);
    F(i,2)F(j,c[i])a[i][j+1].first+=a[i][j].first;
    n=min(p,c[1]);
    for(i=0;~n;--n)
    if((t=a[1][n].first+a[0][min(*c,(p-n)/2)].first)<x)i=n,x=t;
    printf("%d\n",-x);
    F(t,i)printf("%d ",a[1][t+1].second);
    t=min(*c,(p-i)/2);
    F(i,t)printf("%d ",a[0][i+1].second);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


        solve();

}
