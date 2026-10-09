#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    auto solve = [&](ll x){
        int cnt = 1;
        ll sum = 0;
        rep(i,n){
            if(a[i] > x) return false;

            if(sum + a[i] > x){
                cnt++;
                sum = a[i];
            } else sum += a[i];
        }
        return cnt <= k;
    };

    ll ng = 1, ok = 1e18;
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;
        if(solve(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
    
    return 0;
}