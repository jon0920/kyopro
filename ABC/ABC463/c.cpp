#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;
int main(){
    
    int n;
    cin >> n;
    priority_queue<P, vector<P>, greater<P>> pq;
    multiset<int> st;
    rep(i,n){
        int h, l;
        cin >> h >> l;
        pq.push({l, h});
        st.insert(h);
    }

    int q;
    cin >> q;
    vector<pair<int,int>> t(q);
    rep(i,q){
        int T;
        cin >> T;
        t[i] = {T, i};
    }
    sort(t.begin(), t.end());

    vector<int> ans(q);
    rep(i,q){
        auto [ti, id] = t[i];
        while(!pq.empty() && pq.top().first <= ti){
            auto [l, h] = pq.top();
            pq.pop();
            st.erase(st.find(h));
        }
        ans[id] = *st.rbegin();
    }

    for(auto x : ans) cout << x << endl;
    
    return 0;
}