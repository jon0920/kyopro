#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using mint = atcoder::modint998244353;

int main(){
    
    ll n;
    cin >> n;
    mint ans = 0;
    ll p10 = 10;
    for(int i = 1; i <= 18; i++){
        ll d = min(p10 - 1, n) - (p10 / 10) + 1;
        if(d <= 0) break;
        ans += (mint) d * (d + 1) / 2;
        p10 *= 10;
    }

    cout << ans.val() << endl;
    
    return 0;
}