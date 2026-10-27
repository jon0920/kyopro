#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<ll> l(n);
    rep(i,n) cin >> l[i];

    auto solve = [&](ll x){
        ll row = 1;
        ll cnt = 0;
        rep(i,n){
            if(x < l[i]) return false;

            ll nxt = (cnt == 0 ? l[i] : cnt + 1 + l[i]);
            if(nxt > x){
                row++;
                cnt = l[i];
            } else {
                cnt = nxt;
            }
        }
        return row <= m;
    };

    ll ok = 1e18, ng = 0;
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;
        if(solve(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
    
    return 0;
}