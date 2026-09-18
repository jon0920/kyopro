#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<vector<ll>> edges(n);
    vector<ll> t(n), k(n);
    rep(i,n){
        cin >> t[i] >> k[i];
        rep(j,k[i]){
            int x;
            cin >> x;
            x--;
            edges[i].push_back(x);
        }
    }

    vector<bool> used(n);
    used[n - 1] = true;
    ll ans = 0;
    for(int i = n - 1; i >= 0; i--){
        if(used[i]){
            ans += t[i];
            rep(j,k[i]){
                used[edges[i][j]] = true; 
            }
        }
    }
    cout << ans << endl;

    return 0;
}