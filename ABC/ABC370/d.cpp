#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> row(h, {-1, w}), col(w, {-1, h});
    rep(i,h) rep(j,w){
        row[i].insert(j);
        col[j].insert(i);
    }

    auto del = [&](int r, int c) -> void {
        if(r < 0 || r >= h || c < 0 || c >= w) return;
        row[r].erase(c);
        col[c].erase(r);
    };

    while(q--){
        int r, c;
        cin >> r >> c;
        r--, c--;

        auto R = row[r].lower_bound(c);
        if(*R == c){
            del(r, *R);
            continue;
        }

        auto L = prev(R);
        auto D = col[c].lower_bound(r);
        auto U = prev(D);
        del(r, *R), del(r, *L), del(*D, c), del(*U, c);
    }

    ll ans = 0;
    rep(i,h) ans += (ll)row[i].size() - 2;
    cout << ans << endl;

    return 0;
}