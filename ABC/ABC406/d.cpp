#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int h, w, n;
    cin >> h >> w >> n;
    map<int,set<int>> row_mp;
    map<int,set<int>> col_mp;

    rep(i,n){
        int x, y;
        cin >> x >> y;
        x--; y--;
        row_mp[x].insert(y);
        col_mp[y].insert(x);
    }

    int q;
    cin >> q;
    while(q--){
        int type, a;
        cin >> type >> a;
        a--;
        if(type == 1){
            cout << row_mp[a].size() << endl;
            for(auto i : row_mp[a]){
                col_mp[i].erase(a);
            }
            row_mp[a].clear();
        }
        else{
            cout << col_mp[a].size() << endl;
            for(auto i : col_mp[a]){
                row_mp[i].erase(a);
            }
            col_mp[a].clear();
        }
    }
    
    return 0;
}