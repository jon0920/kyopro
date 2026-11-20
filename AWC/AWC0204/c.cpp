#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int mx = 100010;

int main(){
    
    int n;
    cin >> n;
    vector<ll> cnt(mx);
    ll ans = 0;
    rep(i,n){
        int a;
        cin >> a;
        ans += a;
        cnt[a]++;
    }

    int q;
    cin >> q;
    rep(i,q){
        int b, c;
        cin >> b >> c;
        ans -= cnt[b] * b;
        ans += cnt[b] * c;

        cnt[c] += cnt[b];
        cnt[b] = 0;

        cout << ans << endl;
    }

    return 0;
}