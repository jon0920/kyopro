#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)  

struct E {int u, v, id;};

int main(){

    int n, m;
    cin >> n >> m;

    vector<E> edges;
    dsu uf(n);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--, b--;
        if(uf.same(a, b)){
            edges.push_back({a, b, i + 1});
        } else {
            uf.merge(a, b);
        }
    }

    set<int> st;
    rep(i,n) st.insert(uf.leader(i));

    int sz = st.size() - 1;
    cout << sz << endl;
    rep(i,sz){
        auto [a, b, id] = edges[i];
        int x = uf.leader(a);
        st.erase(uf.leader(a));
        int y = *st.begin();
        st.erase(y);
        int z = uf.merge(x, y);
        st.insert(z);
        cout << id << ' ' << a + 1 << ' ' << y + 1 << endl;
    }

    return 0;
}