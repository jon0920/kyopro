#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

int main(){
    
    string x, y;
    cin >> x >> y;

    int len_x = x.size(), len_y = y.size();
    vector<vector<ll>> presum_x(len_x + 1, vector<ll>(26));
    vector<vector<ll>> presum_y(len_y + 1, vector<ll>(26));

    rep(i,len_x){
        rep(c,26){
            presum_x[i + 1][c] = presum_x[i][c] + (x[i] - 'a' == c);
        }
    }
    rep(i,len_y){
        rep(c,26){
            presum_y[i + 1][c] = presum_y[i][c] + (y[i] - 'a' == c);
        }
    }

    vector<vector<ll>> cnt;
    cnt.push_back(presum_x.back());
    cnt.push_back(presum_y.back());

    vector<ll> len = {len_x, len_y};
    while(len.back() < INF){
        int sz = len.size();
        len.push_back(min(INF, len[sz - 1] + len[sz - 2]));

        vector<ll> nxt(26);
        rep(c,26){
            nxt[c] = min(INF, cnt[sz - 1][c] + cnt[sz - 2][c]);
        }
        cnt.push_back(nxt);
    }

    int top = len.size() - 1;

    auto dfs = [&](auto dfs, int k, ll cur, int c) -> ll {
        if(cur == 0) return 0;
        if(k == 0) return presum_x[cur][c];
        if(k == 1) return presum_y[cur][c];

        if(cur <= len[k - 1]){
            return dfs(dfs, k - 1, cur, c);
        }

        return cnt[k - 1][c] + dfs(dfs, k - 2, cur - len[k - 1], c);
    };

    int q;
    cin >> q;
    while(q--){
        ll l, r;
        char c;
        cin >> l >> r >> c;
        cout << dfs(dfs, top, r, c - 'a') - dfs(dfs, top, l - 1, c - 'a') << endl;
    }
    
    return 0;
}