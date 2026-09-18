#include <bits/stdc++.h>
#include <atcoder/maxflow>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    mf_graph<int> G(n + m + 2);
    rep(i,n) G.add_edge(n + m, i, 1);
    rep(j,m) G.add_edge(n + j, n + m + 1, 1);
    
    rep(i,n){
        int k;
        cin >> k;
        rep(j,k){
            int c;
            cin >> c;
            c--;
            G.add_edge(i, n + c, 1);
        }
    }

    cout << G.flow(n + m, n + m + 1) << endl;

    return 0;
}