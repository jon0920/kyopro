#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

//二次元累積和

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<vector<ll>> a(n, vector<ll>(n));
    rep(i,n) rep(j,n) cin >> a[i][j];

    //[x1, y1), [x2, y2), 0-indexed
    auto rect = [&](int x1, int y1, int x2, int y2, vector<vector<int>> &s){
        return s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1];
    };

    auto check = [&](ll x){
        vector<vector<int>> sum(n + 1, vector<int>(n + 1));
        rep(i,n) rep(j,n) sum[i + 1][j + 1] = (a[i][j] > x);

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++) sum[i][j] += sum[i][j - 1];
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++) sum[i][j] += sum[i - 1][j];
        }

        for(int i = 0; i <= n - k; i++){
            for(int j = 0; j <= n - k; j++){
                if(rect(i, j, i + k, j + k, sum) <= (k * k / 2)) return true;
            }
        }

        return false;
    };
    
    ll ok = 1e9 + 10, ng = -1;
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
    
    return 0;
}