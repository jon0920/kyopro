#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int INF = 1e9;
int op(int a, int b){ return min(a, b); }
int e(){ return INF; }

int main(){

    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    segtree<int,op,e> seg(h);
    vector<int> dist(n);
    stack<int> st;
    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && h[st.top()] <= h[i]){
            st.pop();
        }

        if(!st.empty()) dist[i] = st.top();
        else dist[i] = -1;

        st.push(i);
    }

    ll ans = 0;
    rep(i,n){
        if(dist[i] == -1) continue;
        ans += seg.prod(i, dist[i]);
    }
    cout << ans << endl;

    return 0;
}