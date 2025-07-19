#include <bits/stdc++.h>
using namespace std;

int main(){
int t; cin>>t;
while (t--){
int n,k; cin>>n>>k;
string s; cin>>s;
vector<vector<int>> count(k,vector<int>(26));
for (int i=0;i<n;i++){
count[i%k][s[i]-'a']++;
count[i%k][s[n-i-1]-'a']++;
}
int ans=0;
for (int i=0;i<k;i++){
ans+=2*n/k-*max_element(count[i].begin(),count[i].end());
}
cout<<ans/2<<endl;
}
}