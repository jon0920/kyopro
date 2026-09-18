#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using mint = modint998244353;

int main(){

    int n, d;
    cin >> n >> d;
    vector<int> p(n), w(d);
    mint s = 0, w_sum = 0;
    rep(i,n) cin >> p[i], s += p[i];
    rep(i,d) cin >> w[i], w_sum += w[i];

    mint s_inv = 1 / s;

    mint r = 1;
    rep(i,n){
        mint t = p[i] * s_inv * w_sum;
        r *= t;
    }

    cout << r.val() << endl;

    return 0;
}