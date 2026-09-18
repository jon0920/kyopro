#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<ll> l(n);
    ll sum = 0, mx = 0;
    rep(i,n){
        cin >> l[i];
        mx = max(mx, l[i]);
        sum += l[i];
    }

    auto solve = [&](ll x){
        int line = 1;
        ll cnt = 0;
        rep(i,n){
            ll need = (cnt == 0 ? l[i] : l[i] + 1);
            if(cnt + need > x){
                line++;
                cnt = l[i];
            } else {
                cnt += need;
            }
        }
        return line <= m;
    };

    ll ng = mx - 1, ok = sum + n;
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;
        if(solve(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
    
    return 0;
}