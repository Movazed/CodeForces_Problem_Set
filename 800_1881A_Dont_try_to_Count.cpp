#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <stack>

#define nl std::endl

#define vector <int, int> vi

typedef long long ll;

using namespace std;

void dont_count() {

    ll testcases;
    cin >> testcases;

    while (testcases--)
    {
        ll new_num;
        ll new1_num;
        cin>>new_num>>new1_num;

        string str1;
        string str2;

        cin >> str1;
        cin >> str2;

        int count = 0;
        while (count < 8)
        {   
            if(str1.find(str2) != string::npos){
                break;
            }

            str1 += str1;
            ++count;
        }

        if(count == 8){
            count = -1;
        }

        cout << count << nl;
        
    }
}

int32_t main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    dont_count();
    return 0;
}