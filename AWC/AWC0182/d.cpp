#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

struct S{
    ll l, r, c, w;
};
const ll INF = 1e18;

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    vector<S> cand(m);
    rep(i,m){
        ll l, r, c, w;
        cin >> l >> r >> c >> w;
        l--;
        cand[i] = {l, r, c, w};
    }

    ll ans = INF;
    for(int bit = 0; bit < (1 << m); bit++){
        vector<ll> imos(n + 1, 0);
        ll sum = 0;
        rep(i,m){
            if((bit >> i) & 1){
                imos[cand[i].l] += cand[i].c;
                imos[cand[i].r] -= cand[i].c;
                sum += cand[i].w;
            }
        }
        rep(i,n) imos[i + 1] += imos[i];
        bool ok = true;
        rep(i,n) if(imos[i] < a[i]) ok = false;
        if(ok) ans = min(ans, sum);
    }

    cout << (ans >= INF ? -1 : ans) << endl;
    
    return 0;
}