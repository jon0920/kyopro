#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    string s;
    cin >> n >> s;

    vector<int> d(n + 1);
    d[0] = n;
    rep(i,n){
        d[i + 1] = d[i];
        if(s[i] == 'A') d[i + 1]++;
        if(s[i] == 'B') d[i + 1]--;
    }

    fenwick_tree<int> t(n * 2 + 1);
    ll ans = 0;
    rep(i, n + 1){
        ans += t.sum(0,d[i]);
        t.add(d[i], 1);
    }
    cout << ans << endl;

    return 0;
}