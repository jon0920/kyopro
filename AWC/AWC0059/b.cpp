#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> t(m);
    rep(i,m) cin >> t[i];
    vector<pair<int,int>> pass;
    rep(i,n){
        bool ok = true;
        int sum = 0;
        rep(j,m){
            int s;
            cin >> s;
            sum += s;
            if(s < t[j]) ok = false;
        }
        if(ok) pass.push_back({sum, i});
    }
    
    if(pass.size() <= k){
        sort(pass.begin(), pass.end(), [](const auto &a, const auto &b){
            return a.second < b.second;
        });
        for(auto [_, i] : pass) cout << i + 1 << endl;
        return 0;
    }
    
    sort(pass.rbegin(), pass.rend());
    int b = pass[k - 1].first;
    set<int> st;
    for(auto [p, i] : pass) if(p >= b) st.insert(i + 1);

    for(auto i : st) cout << i << endl;

    return 0;
}