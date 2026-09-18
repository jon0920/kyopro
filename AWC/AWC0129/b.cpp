#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, t;
    cin >> n >> t;
    vector<pair<int,int>> se(n);
    rep(i,n) cin >> se[i].first >> se[i].second;
    sort(se.begin(), se.end());

    int ans = max(se[0].first, t - se[n - 1].second);
    rep(i,n - 1){
        ans = max(ans, se[i + 1].first - se[i].second);
    }

    cout << ans << endl;
    
    return 0;
}