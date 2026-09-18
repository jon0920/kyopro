#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int M = 1000100;

int main(){
    
    int n, d;
    cin >> n >> d;
    vector<ll> cnt(M + 1);
    int mx = 0;
    rep(i,n){
        int s, t;
        cin >> s >> t;
        mx = max(mx, t);
        if(t - s < d) continue;
        cnt[s]++;
        cnt[t - d + 1]--;
    }

    rep(i,M) cnt[i + 1] += cnt[i];

    ll ans = 0;
    rep(i,mx + 1){
        ans += cnt[i] * (cnt[i] - 1) / 2;
    }

    cout << ans << endl;

    return 0;
}