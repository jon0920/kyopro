#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, a, b;
    cin >> n >> a >> b;
    ll d = a - b;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];

    auto solve = [&](ll x){
        ll dmg = b * x;
        ll cnt = 0;
        for(ll y : h){
            if(y - dmg > 0){
                cnt += (y - dmg + d - 1) / d;
            }
        }
        return cnt <= x;
    };

    ll ok = 1e9 + 10, ng = 0;
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;
        if(solve(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
    
    return 0;
}