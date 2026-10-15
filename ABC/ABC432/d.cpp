#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace atcoder;
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

struct S{
    ll xl, xr, yl, yr;
};

int main() {
    
    ll n, x, y;
    cin >> n >> x >> y;
    vector<S> black;
    black.push_back({0, x - 1, 0, y - 1});

    rep(i,n){
        char c;
        ll a, b;
        cin >> c >> a >> b;
        vector<S> next_black;
        if(c == 'X'){
            for(auto [xl, xr, yl, yr] : black){
                ll nyl, nyr;
                ll nyl2, nyr2;
                if(xl >= a){
                    nyl = yl + b;
                    nyr = yr + b;
                    next_black.push_back({xl, xr, nyl, nyr});
                } else if(xr < a){
                    nyl = yl - b;
                    nyr = yr - b;
                    next_black.push_back({xl, xr, nyl, nyr});
                } else {
                    nyl = yl + b;
                    nyr = yr + b;
                    nyl2 = yl - b;
                    nyr2 = yr - b;
                    next_black.push_back({xl, a - 1, nyl2, nyr2});
                    next_black.push_back({a, xr, nyl, nyr});
                }
            }
        } else {
            for(auto [xl, xr, yl, yr] : black){
                ll nxl, nxr;
                ll nxl2, nxr2;
                if(yl >= a){
                    nxl = xl + b;
                    nxr = xr + b;
                    next_black.push_back({nxl, nxr, yl, yr});
                } else if(yr < a){
                    nxl = xl - b;
                    nxr = xr - b;
                    next_black.push_back({nxl, nxr, yl, yr});
                } else {
                    nxl = xl + b;
                    nxr = xr + b;
                    nxl2 = xl - b;
                    nxr2 = xr - b;
                    next_black.push_back({nxl2, nxr2, yl, a - 1});
                    next_black.push_back({nxl, nxr, a, yr});
                }
            }
        }
        black = move(next_black);
    }

    int sz = black.size();
    vector<ll> cnt(sz);
    rep(i,sz){
        auto [xl, xr, yl, yr] = black[i];
        cnt[i] = (xr - xl + 1) * (yr - yl + 1);
    }

    auto check = [&](const S &a, const S &b){
        if(a.xr + 1 == b.xl || b.xr + 1 == a.xl){
            if(max(a.yl, b.yl) <= min(a.yr, b.yr)) return true;
        }
        if(a.yr + 1 == b.yl || b.yr + 1 == a.yl){
            if(max(a.xl, b.xl) <= min(a.xr, b.xr)) return true;
        }
        return false;
    };

    dsu uf(sz);
    rep(i,sz){
        for(int j = i + 1; j < sz; j++){
            if(check(black[i], black[j])){
                int u = uf.leader(i);
                int v = uf.leader(j);
                if(u == v) continue;
                
                uf.merge(i, j);
                int w = uf.leader(i);
                cnt[w] = cnt[u] + cnt[v];
            }
        }
    }

    vector<ll> ans;
    rep(i,sz){
        if(uf.leader(i) == i) ans.push_back(cnt[i]);
    }
    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for(ll x : ans){
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}