#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    vector<int> row = a, col = b;
    sort(row.begin(), row.end());
    sort(col.begin(), col.end());

    map<int,int> row_mp, col_mp;
    int last = row[0];
    int num = 1;
    row_mp[last] = num;
    for(int i = 1; i < n; i++){
        if(last == row[i])continue;
        else{
            last = row[i];
            num++;
            row_mp[last] = num;
        }
    }
    last = col[0];
    num = 1;
    col_mp[last] = num;
    for(int i = 1; i < n; i++){
        if(last == col[i]) continue;
        else{
            last = col[i];
            num++;
            col_mp[last] = num;
        }
    }

    for(auto &x : a) x = row_mp[x];
    for(auto &y : b) y = col_mp[y];

    rep(i,n) cout << a[i] << " " << b[i] << endl;
    
    return 0;
}