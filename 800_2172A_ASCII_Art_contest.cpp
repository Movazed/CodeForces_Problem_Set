#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    vector<ll> v(3);
    for(int i = 0; i < 3; i++) cin >> v[i];

    sort(v.begin(), v.end());

    if(v[2] - v[0] >= 10) cout << "check again\n";
    else cout << "final " << v[1] << "\n";

    return 0;
}