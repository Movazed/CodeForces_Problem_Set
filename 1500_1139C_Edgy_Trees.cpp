#include<iostream>
using namespace std;
int64_t n,f,k,i,j,y,u,v,a,b,c,Z=1e9+7,l[222000],h[222000];
int L(int x){return l[x]==x?x:l[x]=L(l[x]);}
int main(){
cin>>n>>k;
for(i=1;i<=n;i++)l[i]=i;
for(i=1;i<n;i++){
cin>>u>>v>>y;
if(!y)l[L(u)]=L(v);
}
for(i=1;i<=n;i++)h[L(i)]++;
for(i=1;i<=n;i++){
if(h[i]==1)b++;
else{
for(c=1,j=0;j<k;j++)c*=h[i],c%=Z;
a+=c;a%=Z;
}
}
for(f=1,j=0;j<k;j++)f*=n,f%=Z;
cout<<(f-a-b+Z+Z)%Z;
}