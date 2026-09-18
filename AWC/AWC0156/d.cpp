#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int M = 200010;

int main(){
    
    int n;
    cin >> n;
    bitset<M> dp;
    dp[0] = 1;
    int sum = 0;
    rep(i,n){
        int a;
        cin >> a;
        sum += a;
        dp |= (dp << a);
    }

    for(int i = sum / 2; i >= 0; i--){
        if(dp[i]){
            cout << i << endl;
            return 0;
        }
    }
    
    return 0;
}