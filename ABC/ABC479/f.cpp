#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<ll> s(n), t(n);
    rep(i,n) cin >> s[i];
    rep(i,n) cin >> t[i];

    vector<pair<ll,int>> ps(n), pt(n);
    rep(i,n){
        ps[i] = {s[i], i};
        pt[i] = {t[i], i};
    }
    sort(ps.begin(), ps.end());
    sort(pt.begin(), pt.end());
    
    vector<int> ss(n), tt(n);
    rep(i,n){
        ss[ps[i].second] = i;
        tt[pt[i].second] = i;
    }

    ll ans = 0;
    rep(i,n){
        ans += abs((t[i] - tt[i]) - (s[i] - ss[i]));
    }

    fenwick_tree<ll> fw(n);
    for(auto [_, i] : ps){
        ans += fw.sum(tt[i] + 1, n);
        fw.add(tt[i], 1);
    }
    
    cout << ans << endl;
    
    return 0;
}