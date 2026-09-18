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
    rep(ti,t){
        ll n, m;
        cin >> n >> m;

        mint ans = 0;
        ll L = 1;
        ll mod_m10 = 10 % m;
        while(L <= n){
            ll R = n;
            if(L <= n / 10) R = L * 10 - 1;

            ll y_num = R - L + 1;
            
            ll v = (mod_m10 - 1 + m) % m;
            ll g = gcd(v, m);
            ll x_num = n / (m / g);

            ans += (mint)x_num * y_num;

            if(L > n / 10) break;
            L *= 10;
            mod_m10 = (mod_m10 * 10) % m;
        }
        cout << ans.val() << endl;
    }
    
    return 0;
}