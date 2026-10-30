#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    fenwick_tree<ll> fw(m);
    ll base = 0;
    rep(i,n){
        base += fw.sum(a[i] + 1, m);
        fw.add(a[i], 1);
    }
    
    vector<ll> d(m);
    vector<ll> cnt_l(m), cnt_r(m);
    rep(i,n) cnt_r[a[i]]++;
    rep(i,n){
        int diff = 0;
        diff += i - cnt_l[a[i]];
        cnt_l[a[i]]++;
        cnt_r[a[i]]--;
        diff -= n - (i + 1) - cnt_r[a[i]];
        d[(m - a[i]) % m] += diff;
    }

    cout << base << endl;
    for(int i = 1; i < m; i++){
        cout << base + d[i] << endl;
        base += d[i];
    }

    return 0;
}