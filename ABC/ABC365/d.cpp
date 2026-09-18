#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

int main() {
    
    int n;
    string s;
    cin >> n >> s;
    map<char,int> win, lose;
    win['S'] = 0, win['R'] = 1, win['P'] = 2;
    lose['S'] = 1, lose['R'] = 2, lose['P'] = 0; 

    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    rep(i,n){
        int x = win[s[i]];
        int y = lose[s[i]];
        rep(j,3){
            rep(k,3){
                if(j == k) continue;
                if(k == y) continue;
                chmax(dp[i + 1][k], dp[i][j] + (x == k));
            }
        }
    }
    
    int ans = 0;
    rep(i,3){
        chmax(ans, dp[n][i]);
    }
    cout << ans << endl;

    return 0;
}