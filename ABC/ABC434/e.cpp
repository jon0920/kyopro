#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<ll> x(n), r(n);
    set<ll> st;
    rep(i,n){
        cin >> x[i] >> r[i];
        st.insert(x[i] - r[i]);
        st.insert(x[i] + r[i]);
    }

    map<ll,int> mp;
    int cur = 0;
    for(ll x : st){
        mp[x] = cur;
        cur++;
    }

    dsu uf(cur);

    vector<int> edge_cnt(cur);
    rep(i,n){
        int a = mp[x[i] - r[i]];
        int b = mp[x[i] + r[i]];
        if(!uf.same(a, b)){
            int la = uf.leader(a);
            int lb = uf.leader(b);
            uf.merge(a, b);
            int lab = uf.leader(a);
            edge_cnt[lab] = edge_cnt[la] + edge_cnt[lb] + 1;
        } else {
            int lab = uf.leader(a);
            edge_cnt[lab]++;
        }
    }

    int ans = 0;
    rep(i,cur){
        if(uf.leader(i) == i){
            int u = uf.size(i);
            int v = edge_cnt[i];
            ans += min(u, v);
        }
    }
    cout << ans << endl;
    
    return 0;
}