#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];

    auto solve = [&](ll x){
        int a_cnt = 0, b_cnt = 0;
        rep(i,n) if(x >= a[i]) a_cnt++;
        rep(i,m) if(x <= b[i]) b_cnt++;
        return a_cnt >= b_cnt;
    };

    ll ng = 0, ok = 1e10;
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;
        if(solve(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
    
    return 0;
}