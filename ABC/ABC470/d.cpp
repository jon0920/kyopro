#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<int> P(n);
    vector<int> Q(n);
    rep(i,n){
        cin >> P[i];
        P[i]--;
    }
    rep(i,n) Q[P[i]] = i;
    
    int inv = 0;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int x, y;
            cin >> x >> y;
            x--, y--;
            if(inv == 0){
                int u = P[x], v = P[y];
                swap(P[x], P[y]);
                swap(Q[u], Q[v]);
            }else {
                int u = Q[x], v = Q[y];
                swap(Q[x], Q[y]);
                swap(P[u], P[v]); 
            }
        } else {
            inv ^= 1;
        }
    }

    vector<int> ans = (inv == 0 ? P : Q);
    for(auto x : ans) cout << x + 1 << " ";
    cout << endl; 
    
    return 0;
}