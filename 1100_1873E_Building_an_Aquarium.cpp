#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
bool check(int h, vector<int> &v1,int x){
    int ans = 0;
    int z=0;
    for(int i=0;i<v1.size();i++){
        ans+=(max(z,h-v1[i]));
    }
    return ans>x;


}
void solve()
{
    int n,x;
    cin>>n>>x;
    vector<int> v1(n);
    for(int i=0;i<n;i++){
        cin>>v1[i];
    }
    int ans = 0;
    int l = 1;
    int r = INT_MAX;
    while(l<=r){
        int mid = (l+r)/2;
        if(check(mid,v1,x)){
            // cout<<"mid "<<mid<<"\n ";
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    // cout<<'\n';
    cout<<ans-1<<'\n';

    
    
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long t;
    cin >> t;
    for (long long i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}