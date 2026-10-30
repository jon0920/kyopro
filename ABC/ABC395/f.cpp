#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, x;
    cin >> n >> x;
    vector<ll> u(n), d(n);
    ll sum = 0;
    rep(i,n){
        cin >> u[i] >> d[i];
        sum += u[i] + d[i];
    }

    auto check = [&](ll h){
        if(u[0] + d[0] < h) return false;
        pair<ll,ll> cur = {max(0LL, h - d[0]), min(u[0], h)};

        for(int i = 1; i < n; i++){
            if(u[i] + d[i] < h) return false;
            pair<ll,ll> nxt = {max(0LL, h - d[i]), min(u[i], h)};
            ll nl = max(nxt.first, cur.first - x);
            ll nr = min(nxt.second, cur.second + x);
            if(nl > nr) return false;
            cur = {nl, nr};
        }

        return true;
    };

    ll ok = 0, ng = 2e9 + 10;
    while(ng - ok > 1){
        ll mid = (ok + ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }

    cout << sum - n * ok << endl;
    
    return 0;
}