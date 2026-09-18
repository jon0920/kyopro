#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll MOD = 998244353;

int main(){

    ll n;
    cin >> n;
    vector<vector<ll>> ab(n, vector<ll>(2));
    rep(i,n){
        ll a, b;
        cin >> a >> b;
        ab[i] = {a, b};
    }

    vector<vector<ll>> sum(n, vector<ll>(2, 0));
    sum[0] = {1,1};
    for(int i = 1; i < n; i++){
        rep(j,2){
            rep(k,2){
                if(ab[i - 1][j] != ab[i][k]){
                    sum[i][k] += sum[i - 1][j];
                }
                sum[i][k] %= MOD;
            }
        }
    }

    ll ans = sum[n - 1][0] + sum[n - 1][1];
    ans %= MOD;
    cout << ans << endl;

    return 0;
}