#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int INF = 1e9;

int main(){
    
    int t;
    cin >> t;
    while(t--){
        int h, w;
        cin >> h >> w;
        vector<string> s(h);
        rep(i,h) cin >> s[i];

        vector<int> orig(h);
        rep(i,h){
            rep(j,w){
                if(s[i][j] == '#') orig[i] |= (1 << j);
            }
        }

        vector<int> dp(1 << w, INF);
        dp[0] = 0;
        
        rep(i,h){
            vector<int> ndp(1 << w, INF);
            for(int nxt = 0; nxt < (1 << w); nxt++){
                if((nxt & orig[i]) != nxt) continue;

                int cost = __builtin_popcount(orig[i]) - __builtin_popcount(nxt);

                for(int cur = 0; cur < (1 << w); cur++){
                    int common = cur & nxt;
                    if(common & (common >> 1)) continue;

                    ndp[nxt] = min(ndp[nxt], dp[cur] + cost);
                }
            }
            dp = move(ndp);
        }

        cout << *min_element(dp.begin(), dp.end()) << endl;

    }
    
    return 0;
}