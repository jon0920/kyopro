#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<pair<int,int>> log;
    rep(i,n){
        int a, b;
        cin >> a >> b;
        log.push_back({a, 1});
        log.push_back({a + b, -1});
    }
    sort(log.begin(), log.end());

    vector<int> ans(n + 1);
    int cnt = 0;
    rep(i, 2 * n - 1){
        cnt += log[i].second;
        ans[cnt] += log[i + 1].first - log[i].first;
    }

    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}