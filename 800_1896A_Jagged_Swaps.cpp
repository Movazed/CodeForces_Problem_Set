#include<bits/stdc++.h>
#include <vector>
#include <stack>
#define nl std::endl
typedef long double ld;
typedef long long ll;

#define pair <int int> pii
#define LOOP(i, n) for (long long i = 0; i < (n); i++)
#define print std::cout
using namespace std;

void jagged_swaps(){
    ll testcases;
    cin >> testcases;

    while(testcases--){
        ll n;
        cin >> n;

        vector <int> array(n);

        LOOP(i,n){
            cin >> array[i];
        }

            if(array[0] != 1){
                print << "NO"<< endl;
            } 
            else 
            {
                print << "YES"<< endl;
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    jagged_swaps();
    return 0;
}