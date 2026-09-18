#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 4e18;

int main(){

    ll n, m;
    cin >> n >> m;
    ll s, t;
    cin >> s >> t;
    vector<ll> p(m);
    rep(i,m) cin >> p[i];

    auto conv = [&](ll x){
        ll r = (x - 1) / n;
        ll c = (x - 1) % n;
        return make_pair(r, c);
    };

    vector<pair<ll,ll>> pts;
    pts.push_back(conv(s));
    rep(i,m) pts.push_back(conv(p[i]));
    pts.push_back(conv(t));

    int v = m + 2;
    vector<vector<ll>> dist(v, vector<ll>(v));
    rep(i,v){
        rep(j,v){
            dist[i][j] = llabs(pts[i].first - pts[j].first) + llabs(pts[i].second - pts[j].second);
        }
    }

    vector<vector<ll>> dp(1 << m, vector<ll>(m, INF));
    rep(i,m) dp[1 << i][i] = dist[0][i + 1];

    for(int S = 0; S < (1 << m); S++){
        rep(i,m){
            if(!(S & (1 << i))) continue;
            if(dp[S][i] == INF) continue;

            rep(j,m){
                if(S & (1 << j)) continue;
                int T = S | (1 << j);
                dp[T][j] = min(dp[T][j], dp[S][i] + dist[i + 1][j + 1]);
            }
        }
    }

    ll ans = INF;
    if(m == 0) ans = dist[0][1];
    else rep(i,m) ans = min(ans, dp[(1 << m) - 1][i] + dist[i + 1][m + 1]);

    cout << ans << endl;

    return 0;
}