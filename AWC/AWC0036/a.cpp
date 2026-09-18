#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<vector<int>> s(n);
    rep(i,n){
        int m;
        cin >> m;
        s[i].resize(m);
        rep(j,m) cin >> s[i][j];
    }

    int q;
    cin >> q;
    int wa = 0;
    while(q--){
        int v, d;
        cin >> v >> d;
        v--, d--;
        if(s[v][d] > 0){
            s[v][d]--;
        } else {
            wa++;
        }
    }

    rep(i,n){
        for(auto x : s[i]) cout << x << " ";
        cout << endl;
    }
    cout << wa << endl;

    return 0;
}