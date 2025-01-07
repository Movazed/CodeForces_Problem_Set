// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vpii vector<pair<int, int>>
#define vc vector<char>
#define vb vector<bool>
#define mii map<int,int>
#define f0r(i,n) for(int i=0;i<n;i++)
#define FOR(i,k,n) for(int i=k;i<n;i++)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define in(a) int a; cin>>a
#define in2(a,b) int a,b; cin>>a>>b
#define in3(a,b,c) int a,b,c; cin>>a>>b>>c
#define in4(a,b,c,d) int a,b,c,d; cin>>a>>b>>c>>d
#define vin(v,n); vi v(n); f0r(i,n){cin>>v[i];}
#define out(a) cout<<a<<'\n'
#define out2(a,b) cout<<a<<' '<<b<<'\n'
#define out3(a,b,c) cout<<a<<' '<<b<<' '<<c<<'\n'
#define out4(a,b,c,d) cout<<a<<' '<<b<<' '<<c<<' '<<d<<'\n'
#define vout(v) cout<<#v<<' '; for(auto u : v){cout<<u<<' ';} cout<<'\n'
#define dout(a) cout<<a<<' '<<#a<<'\n'
#define dout2(a,b) cout<<a<<' '<<#a<<' '<<b<<' '<<#b<<'\n'
#define yn(x); if(x){cout<<"YES"<<'\n';}else{cout<<"NO"<<'\n';}
const int leg = 1e9 + 7;
const int mod = 998244353;
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin(".in");
	//ofstream cout(".out");
	int t;
	cin>>t;
	while(t--){
		in2(n,q);
		vvi v(n,vi(n));
		f0r(i,n)f0r(j,n)cin>>v[i][j];
		
		vvi a(n+1, vi(n+1));
		FOR(i, 1, n+1){
			FOR(j, 1, n+1){
				a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + v[i-1][j-1];
			}
		}
		vvi b(n+1, vi(n+1));
		FOR(i, 1, n+1){
			FOR(j, 1, n+1){
				b[i][j] = b[i-1][j] + b[i][j-1] - b[i-1][j-1] + (v[i-1][j-1] * (j-1));
			}
		}
		vvi c(n+1, vi(n+1));
		FOR(i, 1, n+1){
			FOR(j, 1, n+1){
				c[i][j] = c[i-1][j] + c[i][j-1] - c[i-1][j-1] + (v[i-1][j-1] * (i-1));
			}
		}
		
		while(q--){
			in4(x1,y1,x2,y2);
			
			x1--;
			x2--;
			y1--;
			y2--;
			int bruh = b[x2 + 1][y2 + 1] - b[x1][y2+1] - b[x2 + 1][y1] + b[x1][y1];
			//out(bruh);
			bruh -= (y1 - 1) * (a[x2 + 1][y2 + 1] - a[x1][y2+1] - a[x2 + 1][y1] + a[x1][y1]);
			//out(bruh);
			bruh += (y2 - y1 + 1) * ((c[x2 + 1][y2 + 1] - c[x1][y2+1] - c[x2 + 1][y1] + c[x1][y1]) - x1 * (a[x2 + 1][y2 + 1] - a[x1][y2+1] - a[x2 + 1][y1] + a[x1][y1]));
			//out(bruh);
			cout<<bruh<<' ';
			
		}
		cout<<'\n';
		
	}
}