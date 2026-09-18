#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> imos(n + 1);
    rep(i,m){
        int l, r;
        cin >> l >> r;
        l--;
        imos[l]++;
        imos[r]--;
    }
    rep(i,n) imos[i + 1] += imos[i];

    int ans = 0;
    rep(i,n) if(imos[i] >= k) ans++;
    cout << ans << endl;

    return 0;
}