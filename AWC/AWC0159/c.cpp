#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> s(m);
    rep(i,m){
        int c;
        cin >> c;
        s[i].resize(c);
        rep(j,c){
            cin >> s[i][j];
            s[i][j]--;
        }
    }

    int ans = 100;
    for(int bit = 0; bit < (1 << m); bit++){
        int res = 0;
        int cnt = 0;
        rep(i,m){
            if((bit >> i) & 1){
                cnt++;
                for(int x : s[i]){
                    res ^= (1 << x);
                }
            }
        }
        if(__builtin_popcount(res) == k){
            ans = min(ans, cnt);
        }
    }

    cout << (ans == 100 ? -1 : ans) << endl;
    
    return 0;
}