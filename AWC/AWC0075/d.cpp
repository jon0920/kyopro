#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k, m;
    cin >> n >> k >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());

    auto solve = [&](ll x){
        int cnt = 0, res = 0;
        ll mn = 1e9, mx = 0;
        rep(i,n){
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
            if(mx - mn <= x && cnt < m) cnt++;
            else {
                mn = a[i];
                mx = a[i];
                cnt = 1;
                res++;
            }
        }
        return res < k;
    };

    ll ng = -1, ok = 1e18;
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;
        if(solve(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
    
    return 0;
}