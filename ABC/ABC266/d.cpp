#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

int main(){

    int n;
    cin >> n;
    vector<int> t(n), x(n);
    vector<ll> a(n);
    rep(i,n) cin >> t[i] >> x[i] >> a[i];
    
    ll fin = t[n - 1];
    vector<vector<ll>> dp(fin + 1, vector<ll>(5, -INF));
    dp[0][0] = 0;

    int now = 0;
    for(int time = 1; time <= fin; time++){
        if(t[now] == time){
            rep(i,5){
                for(int j = -1; j <= 1; j++){
                    int pos = i + j;
                    if(pos < 0 || pos >= 5) continue;
                    if(pos == x[now]) chmax(dp[time][pos], dp[time - 1][i] + a[now]);
                    else chmax(dp[time][pos], dp[time - 1][i]);
                }
            }
            now++;
        }
        else{
            rep(i,5){
                for(int j = -1; j <= 1; j++){
                    int pos = i + j;
                    if(pos < 0 || pos >= 5) continue;
                    chmax(dp[time][pos], dp[time - 1][i]);
                }
            }
        }
    }

    ll ans = 0;
    for(auto x : dp[fin]) ans = max(ans, x);
    cout << ans << endl;

    return 0;
}