#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<vector<int>> a(n * 2 - 1, vector<int>(n * 2, -1));
    rep(i,n * 2 - 1){
        for(int j = i + 1; j < n * 2; j++) cin >> a[i][j];
    }
    
    int ans = 0;
    vector<bool> used(n * 2);

    auto dfs = [&](auto dfs, vector<bool> &used, int crr) -> void {
        int cand1 = -1;
        rep(i,n * 2){
            if(!used[i]){
                cand1 = i;
                break;
            }
        }

        if(cand1 == -1){
            ans = max(ans, crr);
            return;
        }

        used[cand1] = true;
        for(int cand2 = cand1 + 1; cand2 < n * 2; cand2++){
            if(!used[cand2]){
                used[cand2] = true;
                dfs(dfs, used, crr ^ a[cand1][cand2]);
                used[cand2] = false;
            }
        }
        used[cand1] = false;
    };

    dfs(dfs, used, 0);

    cout << ans << endl;
    
    return 0;
}