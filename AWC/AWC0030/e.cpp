#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int M = 1000001;

int main(){

    int n;
    cin >> n;
    vector<ll> cnt(M);

    rep(i,n){
        int a;
        cin >> a;
        cnt[a]++;
    }

    ll ans = 0;
    for(ll x = 1; x <= M; x++){
        ll k = 0;
        for(int y = 1; x * y <= M; y++){
            k += cnt[x * y];
        }
        ans = max(ans, x * k);
    }
    cout << ans << endl;

    return 0;
}