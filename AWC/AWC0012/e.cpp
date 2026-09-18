#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

ll op(ll a, ll b){ return max(a, b); }
ll e(){ return -INF; }

int main(){

    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    segtree<ll, op, e> seg(n);
    vector<ll> dp(n);
    dp[0] = a[0];
    seg.set(0,dp[0]);
    for(int i = 1; i < n; i++){
        dp[i] = a[i] + seg.prod(max(0, i - k), i);
        seg.set(i, dp[i]);
    }

    cout << dp[n - 1] << endl;

    return 0;
}