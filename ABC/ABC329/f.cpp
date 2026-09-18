#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<set<int>> st(n);
    rep(i,n){
        int c;
        cin >> c;
        st[i].insert(c);
    }

    while(q--){
        int a, b;
        cin >> a >> b;
        a--, b--;
        if(st[a].size() <= st[b].size()){
            for(auto x : st[a]){
                st[b].insert(x);
            }
            st[a].clear();
            cout << st[b].size() << endl;
        } else {
            for(auto x : st[b]){
                st[a].insert(x);
            }
            st[b].clear();
            swap(st[a],st[b]);
            cout << st[b].size() << endl;
        }
    }
    
    return 0;
}