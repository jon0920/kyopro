#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> e(m);
    rep(i,m){
        cin >> e[i].first >> e[i].second;
    }
    
    int a1 = e[0].first;
    int b1 = e[0].second;
    vector<pair<int,int>> e_a1, e_b1;
    rep(i,m){
        if(e[i].first != a1 && e[i].second != a1) e_a1.push_back(e[i]);
        if(e[i].first != b1 && e[i].second != b1) e_b1.push_back(e[i]);
    }

    auto cover = [&](int x, const vector<pair<int,int>> edges) -> bool {
        for(const auto &e : edges){
            if(e.first != x && e.second != x) return false;
        }
        return true;
    };

    if(e_a1.empty() && e_b1.empty()){
        cout << 2 * n - 3 << endl;
        return 0;
    } else if(e_a1.empty()){
        int ans = n - 1;
        int u = e_b1[0].first;
        int v = e_b1[0].second;

        if(u != a1 && cover(u, e_b1)) ans++;
        if(v != a1 && cover(v, e_b1)) ans++;
        cout << ans << endl;
        return 0;
    } else if(e_b1.empty()){
        int ans = n - 1;
        int u = e_a1[0].first;
        int v = e_a1[0].second;

        if(u != b1 && cover(u, e_a1)) ans++;
        if(v != b1 && cover(v, e_a1)) ans++;
        cout << ans << endl;
        return 0;
    }

    set<pair<int,int>> st;
    int u1 = e_a1[0].first, v1 = e_a1[0].second;
    int u2 = e_b1[0].first, v2 = e_b1[0].second;
    if(cover(u1, e_a1)) st.insert({min(a1, u1), max(a1, u1)});
    if(cover(v1, e_a1)) st.insert({min(a1, v1), max(a1, v1)});
    if(cover(u2, e_b1)) st.insert({min(b1, u2), max(b1, u2)});
    if(cover(v2, e_b1)) st.insert({min(b1, v2), max(b1, v2)});
    cout << st.size() << endl;

    
    return 0;
}