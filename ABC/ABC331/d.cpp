#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<string> s(n);
    rep(i,n) cin >> s[i];

    vector<vector<int>> sum(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            sum[i][j] += s[i - 1][j - 1] == 'B';
            sum[i][j] += sum[i - 1][j];
            sum[i][j] += sum[i][j - 1];
            sum[i][j] -= sum[i - 1][j - 1];
        }
    }

    auto solve2 = [&](auto solve2, ll x, ll y) -> ll {
        if(x == 0 && y == 0) return 0;
        ll res = 0;
        ll cnt_x = x / n, rem_x = x % n;
        ll cnt_y = y / n, rem_y = y % n;
        res += sum[n][n] * cnt_x * cnt_y;
        res += sum[rem_x][n] * cnt_y;
        res += sum[n][rem_y] * cnt_x;
        res += sum[rem_x][rem_y];
        return res;
    };
    
    auto solve1 = [&](ll a, ll b, ll c, ll d) -> ll {
        return solve2(solve2, c, d) - solve2(solve2, a, d) - solve2(solve2, c, b) + solve2(solve2, a, b);
    };

    while(q--){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << solve1(a, b, c + 1, d + 1) << "\n";
    }
    
    return 0;
}