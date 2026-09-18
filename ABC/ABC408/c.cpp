#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m;
    cin >> n >> m;
    vector<int> imos(n + 1);

    rep(i,m){
        int l, r;
        cin >> l >> r;
        l--;
        imos[l]++;
        imos[r]--;
    }

    for(int i = 1; i <= n; i++){
        imos[i] += imos[i - 1];
    }

    int ans = INT_MAX;
    rep(i,n){
        ans = min(ans,imos[i]);
    }
    cout << ans << endl;
    
    return 0;
}