#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> p(n);
    rep(i,n){
        int x;
        cin >> x;
        p[i] = {x, i};
    }
    sort(p.begin(), p.end());

    set<int> st;
    rep(i,k) st.insert(p[i].second);

    int mx = *st.rbegin();
    int mn = *st.begin();
    int ans = mx - mn;

    rep(i,n-k){
        st.erase(p[i].second);
        st.insert(p[i+k].second);
        mx = *st.rbegin();
        mn = *st.begin();
        ans = min(ans, mx - mn);
    }
    cout << ans << endl;
    
    return 0;
}