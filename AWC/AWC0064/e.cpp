#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

//BIT

int main(){

    int n;
    ll k;
    cin >> n >> k;
    vector<int> p(n);
    rep(i,n) cin >> p[i];

    fenwick_tree<int> fw(n + 1);
    ll ans = 0;
    for(int i = n - 1; i >= 0; i--){
        ans += fw.sum(0, p[i]);
        fw.add(p[i], 1);
    }
    
    cout << max(0LL, ans - k) << endl;

    return 0;
}