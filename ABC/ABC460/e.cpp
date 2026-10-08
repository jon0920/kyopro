#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using mint = modint998244353;

int main(){
    
    int t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        string s = to_string(n);
        int sz = s.size();
        ll cur = 1;
        mint ans = 0;
        __int128_t y = 1;
        for(int d = 1; d <= sz; d++){
            cur *= 10;
            cur %= m;
            y *= 10;
            ll x = (cur - 1 + m) % m;

            ll g = gcd(x, m);

            __int128_t cnt_x = n / (m / g);
            __int128_t cnt_y = max((__int128_t)0, min((__int128_t)n, y - 1) - (y / 10) + 1);

            ans += (mint)cnt_x * cnt_y;
        }
        cout << ans.val() << endl;
    }
    
    return 0;
}