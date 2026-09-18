#include <bits/stdc++.h>
#include "atcoder/modint"
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;
using mint = atcoder::modint998244353;


int main() {
    
    int n;
    cin >> n;
    vector<ll> a(n);
    mint ans = 0;
    rep(i,n){
        cin >> a[i];
        ans += mint(a[i]) * i;
    }
    
    vector<int> cnt(11, 0);
    vector<int> dig(n);
    rep(i,n){
        int x = to_string(a[i]).size();
        cnt[x]++;
        dig[i] = x;
    }

    vector<mint> ref(11, 1);
    for(int i = 1; i <= 10; i++) ref[i] = ref[i - 1] * 10;
    rep(i,n){
        cnt[dig[i]]--;
        rep(j,11){
            ans += ref[j] * cnt[j] * a[i];
        }
    }
    cout << ans.val() << endl;
    
    return 0;
}