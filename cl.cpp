#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    int re = 0;
    int so;
    while(n != 0){
        so = n % 10;
        re = re * 10 + re;
        n = n / 10;
    }
    cout << re << "\n";


    return 0;
}