#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int h, w, r, c;
    cin >> h >> w >> r >> c;
    r--, c--;
    int n;
    cin >> n;
    map<int,vector<int>> row, col;
    rep(i,n){
        int x, y;
        cin >> x >> y;
        x--, y--;
        row[x].push_back(y);
        col[y].push_back(x);
    }

    for(auto &[k, v] : row){
        v.push_back(-1);
        v.push_back(w);
        sort(v.begin(), v.end());
    }
    for(auto &[k, v] : col){
        v.push_back(-1);
        v.push_back(h);
        sort(v.begin(), v.end());
    }

    int q;
    cin >> q;
    while(q--){
        char d; int l;
        cin >> d >> l;
        int x_max = -1, x_min = -1, y_max = -1, y_min = -1;
        if(row.count(r)){
            auto it = lower_bound(row[r].begin(), row[r].end(), c);
            x_max = min(*it - 1, c + l);
            it--;
            x_min = max(*it + 1, c - l);
        }
        if(col.count(c)){
            auto it = lower_bound(col[c].begin(), col[c].end(), r);
            y_max = min(*it - 1, r + l);
            it--;
            y_min = max(*it + 1, r - l); 
        }

        if(d == 'R'){
            if(x_max == -1) c = min(w - 1, c + l);
            else c = min(x_max, c + l);
        } else if(d == 'L') {
            if(x_min == -1) c = max(0, c - l);
            else c = max(x_min, c - l);
        } else if(d == 'D') {
            if(y_max == -1) r = min(h - 1, r + l);
            else r = min(y_max, r + l);
        } else {
            if(y_min == -1) r = max(0, r - l);
            else r = max(y_min, r - l);
        }

        cout << r + 1 << " " << c + 1 << endl;
    }
    
    return 0;
}