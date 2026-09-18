#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m, q, k;
    cin >> n >> m >> q >> k;
    vector<pair<int,int>> ds(m);
    rep(i,m){
        int s, d;
        cin >> s >> d;
        s--;
        ds[i] = {d, s};
    }
    sort(ds.rbegin(), ds.rend());
    vector<tuple<int,int,int,int>> Q(q);
    rep(i,q){
        int l, r, t;
        cin >> l >> r >> t;
        l--;
        Q[i] = {l, r, t, i};
    }
    sort(Q.begin(), Q.end(), [](const auto &a, const auto &b){
        auto [al, ar, at, ai] = a;
        auto [bl, br, bt, bi] = b;
        return at > bt;
    });

    fenwick_tree<int> fw(n);
    vector<int> res(q);
    int crr = 0;
    for(auto [l, r, t, i] : Q){
        while(crr < m && ds[crr].first >= t){
            fw.add(ds[crr].second, 1);
            crr++;
        }
        res[i] = max(fw.sum(l,r) - k, 0);
    }

    for(auto x : res) cout << x << endl;

    return 0;
}