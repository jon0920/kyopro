#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

//転倒数

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    fenwick_tree<int> fw(n + 1);
    ll ans = 0;
    for(int i = n - 1; i >= 0; i--){
        ans += fw.sum(0, a[i]);
        fw.add(a[i], 1);
    }

    cout << ans << endl;
    
    return 0;
}