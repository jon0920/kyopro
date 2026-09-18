#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    vector<set<int>> row_check(9);
    vector<set<int>> col_check(9);
    vector<set<int>> box_check(9);
    vector<vector<int>> a(9, vector<int>(9));
    rep(i,9) rep(j,9){
        int x;
        cin >> x;
        row_check[i].insert(x);
        col_check[j].insert(x);
        int idx = (i / 3) * 3 + (j / 3);
        box_check[idx].insert(x);
    }
    bool ok = true;
    rep(i,9){
        if(row_check[i].size() != 9) ok = false;
        if(col_check[i].size() != 9) ok = false;
        if(box_check[i].size() != 9) ok = false;
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}