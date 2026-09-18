#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<int,char>> C;
    rep(i,m){
        int p;
        char c;
        cin >> p >> c;
        p--;
        C.push_back({p, c});
    }

    while(q--){
        string t;
        cin >> t;
        bool ok = true;
        for(auto [p, c] : C){
            if(t[p] != c){
                ok = false;
                break;
            }
        }
        if(ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}