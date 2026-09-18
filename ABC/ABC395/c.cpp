#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> group(1000001);
    rep(i,n){
        cin >> a[i];
        group[a[i]].push_back(i);
    }

    int ans = 1e9;
    rep(i,1000001){
        if(group[i].size() <= 1) continue;
        else{
            int n = group[i].size();
            rep(j,n-1){
                ans = min(ans, group[i][j+1] - group[i][j]);
            }
        }
    }

    if(ans == 1e9) cout << -1 << endl;
    else cout << ans + 1 << endl;

    return 0;
}