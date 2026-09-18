#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using mint = modint998244353;

int main(){
    
    ll n, m;
    cin >> n >> m;
    mint ans = 0;
    for(int i = 0; i < 60; i++){
        if((m >> i) & 1){
            ll T = 1LL << (i + 1);
            ans += ((n + 1) / T) * (T / 2);
            ll rem = (n + 1) % T;
            ans += max(0LL, rem - T / 2);
        }
    }
    cout << ans.val() << endl;
    
    return 0;
}