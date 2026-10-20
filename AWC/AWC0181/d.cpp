#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<ll> imos(n + 1);
    vector<int> imos2(n + 1);
    for(int i = 1; i <= m; i++){
        int l, r;
        cin >> l >> r;
        l--;
        imos[l] += i;
        imos[r] -= i;
        imos2[l]++;
        imos2[r]--;
    }
    rep(i,n) imos[i + 1] += imos[i]; 
    rep(i,n) imos2[i + 1] += imos2[i];

    vector<int> cnt(m + 1);
    rep(i,n){
        if(imos[i] > 0 && imos[i] <= n && imos2[i] == 1) cnt[imos[i]]++;
    }

    int ans = 0;
    rep(i,n) if(imos[i] > 0) ans++;
    int mn = 1e9;
    for(int i = 1; i <= m; i++) mn = min(mn, cnt[i]);

    cout << ans - mn << endl;
    
    return 0;
}