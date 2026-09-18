#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<int> x(m);
    rep(i,m){
        cin >> x[i];
        x[i]--;
    }
    
    vector<ll> imos(n + 1);
    
    ll base = 0;
    auto add = [&](int l, int r, int val){
        if(l > r) return;
        imos[l] += val;
        imos[r] -= val;
    };

    rep(i,m-1){
        int u = x[i];
        int v = x[i + 1];
        int dist_cw = (v > u) ? (v - u) : (n - u + v);
        int dist_ccw = n - dist_cw;
        base += min(dist_ccw, dist_cw);

        ll diff = abs(dist_ccw - dist_cw);
        if(dist_cw < dist_ccw){
            if(u < v){
                add(u, v, diff);
            } else {
                add(u, n, diff);
                add(0, v, diff);
            }
        } else {
            if(u > v){
                add(v, u, diff);
            } else {
                add(v, n, diff);
                add(0, u, diff);
            }
        }
    }

    rep(i,n) imos[i + 1] += imos[i];

    ll min_diff = 1e18;
    rep(i,n) min_diff = min(min_diff, imos[i]);
    cout << base + min_diff << endl;
    
    return 0;
}