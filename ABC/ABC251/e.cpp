#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

int main(){
    
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    vector<vector<ll>> dp0(n, vector<ll>(2, INF));
    vector<vector<ll>> dp1(n, vector<ll>(2, INF));
    dp0[0][0] = 0;
    dp1[0][1] = a[0];

    for(int i = 1; i < n; i++){
        dp0[i][0] = dp0[i - 1][1];
        dp0[i][1] = min(dp0[i - 1][0], dp0[i - 1][1]) + a[i];
        dp1[i][0] = dp1[i - 1][1];
        dp1[i][1] = min(dp1[i - 1][0], dp1[i - 1][1]) + a[i];
    }

    cout << min({dp0[n - 1][1], dp1[n - 1][0], dp1[n - 1][1]}) << endl;
    
    return 0;
}