#include<bits/stdc++.h>
using namespace std;


int sumn(int n){

    if(n == 1){
        return 1;
    }

    return n + sumn(n - 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    return 0;
}