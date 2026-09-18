#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m, q;
    cin >> n >> m >> q;
    vector<set<int>> v(n);
    vector<bool> va(n, 0);

    rep(i,q){
        int type, x, y;
        cin >> type >> x;
        x--;
        if(type == 1){
            cin >> y;
            y--;
            v[x].insert(y);
        }
        else if(type == 2){
            va[x] = 1;
        }
        else{
            cin >> y;
            y--;
            if(va[x] || v[x].count(y)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    
    return 0;
}