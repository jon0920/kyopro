#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll x;
    cin >> x;

    ll y = 4 * x - 1;
    ll a = abs(y);

    set<ll> ans;

    auto check = [&](ll u, ll v){
        if(u + v < 0) return;
        if((u + v) % 4 != 0) return;
        if((u - v - 2) % 4 != 0) return;

        ans.insert((u - v - 2) / 4);
    };

    for(ll d = 1; d * d <= a; d++){
        if(a % d != 0) continue;

        ll u = d, v = y / u;
        ll ru = -d, rv = y / ru;

        check(u, v); check(v, u);
        check(ru, rv); check(rv, ru);
    }

    cout << ans.size() << endl;
    for(auto a : ans) cout << a << " ";
    cout << endl;
    
    return 0;
}