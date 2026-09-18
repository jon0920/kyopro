#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    ll n;
    cin >> n;
    vector<vector<ll>> cloud(2001, vector<ll>(2001, 0));
    vector<vector<ll>> sumid(2001, vector<ll>(2001, 0));
    for(int i = 1; i <= n; i++){
        int u, d, l, r;
        cin >> u >> d >> l >> r;
        u--, l--;
        cloud[u][l]++;
        cloud[u][r]--;
        cloud[d][l]--;
        cloud[d][r]++;
        sumid[u][l] += i;
        sumid[u][r] -= i;
        sumid[d][l] -= i;
        sumid[d][r] += i;
    }

    rep(i,2000) for(int j = 1; j < 2000; j++){
        cloud[i][j] += cloud[i][j - 1];
        sumid[i][j] += sumid[i][j - 1];
    }
    for(int i = 1; i < 2000; i++) rep(j,2000){
        cloud[i][j] += cloud[i - 1][j];
        sumid[i][j] += sumid[i - 1][j];
    }

    ll total_zero = 0;
    vector<ll> ans(n);
    rep(i,2000) rep(j,2000){
        if(cloud[i][j] == 0) total_zero++;
        else if(cloud[i][j] == 1) ans[sumid[i][j] - 1]++; 
    }

    for(auto x : ans) cout << total_zero + x << endl;
    
    return 0;
}