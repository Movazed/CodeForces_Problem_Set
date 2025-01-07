#include<bits/stdc++.h>
#include <vector>
#include <stack>
#define nl std::endl
typedef long double ld;
typedef long long ll;
#define vi vector <int>
#define pair <int int> pii
#define LOOP(i, n) for (long long i = 0; i < (n); i++)
#define PRINT std::cout
using namespace std;

void daytona() {
    ll testcases;
    cin >> testcases;

    while (testcases--)
    {   
        ll elements;
        ll occurances;
        cin >> elements >> occurances;

        vi a(elements);
        for(ll i = 0; i < elements ; i++){
            cin >> a[i];
        }

        //occurances 

        ll count = 0;
        for(ll num : a){
            if(num == occurances){
                count++;
            }
        }

        if(count >= 1) {
            PRINT << "YES" << nl;
        } else {
            PRINT << "NO" << nl;
        }
    }
    
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    daytona();
    return 0;
}
