#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, q;
    cin >> n >> q;
    set<int> s;
    vector<int> last(200010, -1);
    fenwick_tree<ll> fw(q);
    vector<ll> ans(n);
    rep(i,q){
        int x;
        cin >> x;
        if(s.count(x)){
            int l = last[x];
            ans[x - 1] += fw.sum(l, i);
            s.erase(x);
            last[x] = -1;
        } else {
            s.insert(x);
            last[x] = i;
        }

        int sz = s.size();
        fw.add(i,sz);
    }

    for(auto x : s){
        int l = last[x];
        if(l != -1){
            ans[x - 1] += fw.sum(l, q);
        }
    }

    rep(i,n) cout << ans[i] << " ";
    cout << endl;
    
    return 0;
}