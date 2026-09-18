#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<pair<int,int>> log;
    rep(i,n){
        int s, e;
        cin >> s >> e;
        log.push_back({s, 1});
        log.push_back({e, -1});
    }
    sort(log.begin(), log.end());

    int ans = 0, cur = 0;
    for(auto [x, y] : log){
        cur += y;
        ans = max(ans, cur);
    }
    cout << ans << endl;

    return 0;
}