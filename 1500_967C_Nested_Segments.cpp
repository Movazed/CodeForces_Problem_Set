#include<bits/stdc++.h>

using namespace std;

struct node{
    int l, r, i;
}a[300010];
bool cmp(node x, node y){
    if(x.l != y.l) return x.l < y.l;
    return x.r > y.r;
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i].l >> a[i].r;
        a[i].i = i + 1;
    }

    sort(a, a + n, cmp);

    for(int i = 1; i < n; i++){
        if(a[i - 1].r >= a[i].r){
            cout << a[i].i << ' ' << a[i - 1].i;
            return 0;
        }
    }
    cout << "-1 -1";
    return 0;
}