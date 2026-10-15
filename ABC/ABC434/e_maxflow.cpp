#include <bits/stdc++.h>
#include <atcoder/maxflow>
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
    for(ll a : st){
        mp[a] = cur;
        cur++;
    }

    int source = n + cur;
    int sink = source + 1;
    mf_graph<int> mf(sink + 1);

    rep(i,n){
        mf.add_edge(source, i, 1);
    }
    rep(i,n){
        mf.add_edge(i, mp[x[i] - r[i]] + n, 1);
        mf.add_edge(i, mp[x[i] + r[i]] + n, 1);
    }
    rep(i,cur){
        mf.add_edge(i + n, sink, 1);
    }

    cout << mf.flow(source, sink) << endl;
    
    return 0;
}