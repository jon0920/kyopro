#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    map<int,int> G;
    rep(i,n){
        int a;
        cin >> a;
        a--;
        G[i] = a;
    }

    int pos = 0;
    rep(i,n){
        pos = G[pos];
    }

    vector<int> res;
    res.push_back(pos);
    while(res[0] != G[pos]){
        res.push_back(G[pos]);
        pos = G[pos];
    }
    cout << res.size() << endl;
    for(auto x : res) cout << x + 1 << " ";
    cout << endl;
    
    return 0;
}