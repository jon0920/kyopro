#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<pair<int,ll>> p(n);
    rep(i,n){
        ll a, b;
        cin >> a >> b;
        p[i] = {i + 1, a + b};
    }
    sort(p.begin(), p.end(), [](const auto &a, const auto &b){
        if(a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    });

    set<int> st;
    rep(i,k) st.insert(p[i].first);
    
    for(auto x : st) cout << x << endl;
    
    return 0;
}