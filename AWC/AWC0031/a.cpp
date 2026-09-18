#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int,int>> v(n);
    vector<vector<int>> t(n);
    rep(i,n){
        cin >> v[i].first;
        v[i].second = i;
        int c;
        cin >> c;
        rep(j,c){
            int T;
            cin >> T;
            t[i].push_back(T);
        }
    }
    sort(v.begin(), v.end(), [](const auto &a, const auto &b){
        if(a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    });

    map<int,int> mp;
    rep(i,k){
        int id = v[i].second;
        for(auto x : t[id]) mp[x]++;
    }

    int ans = 0;
    for(auto [key, val] : mp) if(val == k) ans++;
    cout << ans << endl;

    return 0;
}