#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    vector<vector<int>> a(h, vector<int>(w));
    rep(i,h) rep(j,w){
        a[i][j] = (s[i][j] == '1');
    }

    vector<vector<int>> sum(h + 1, vector<int>(w + 1));
    rep(i,h){
        rep(j,w){
            sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + a[i][j];
        }
    }

    ll ans = 0;
    for(int r1 = 0; r1 < h; r1++){
        for(int r2 = r1 + 1; r2 <= h; r2++){
            vector<int> cnt(h * w + 1, 0);
            cnt[0] = 1;
            for(int c = 1; c <= w; c++){
                int crr = sum[r2][c] - sum[r1][c];

                if(crr >= k) ans += cnt[crr - k];

                cnt[crr]++;
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}