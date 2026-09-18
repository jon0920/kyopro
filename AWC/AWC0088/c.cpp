#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> imos(n + 1);
    rep(i,m){
        int l, r;
        cin >> l >> r;
        l--;
        imos[l]++;
        imos[r]--;
    }
    rep(i,n) imos[i + 1] += imos[i];

    ll ans = 0;
    rep(i,n) if(imos[i] > 0) ans += a[i];
    cout << ans << endl;
    
    return 0;
}