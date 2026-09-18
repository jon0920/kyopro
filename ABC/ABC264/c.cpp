#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int h1, w1;
    cin >> h1 >> w1;
    vector<vector<int>> a(h1, vector<int>(w1));
    rep(i,h1) rep(j,w1) cin >> a[i][j];
    int h2, w2;
    cin >> h2 >> w2;
    vector<vector<int>> b(h2, vector<int>(w2));
    rep(i,h2) rep(j,w2) cin >> b[i][j];

    for(int r = 0; r < (1 << h1); r++){
        vector<int> r_id;
        rep(i,h1) if(r & (1 << i)) r_id.push_back(i);
        if(r_id.size() != h2) continue;
        for(int c = 0; c < (1 << w1); c++){
            vector<int> c_id;
            rep(j,w1) if(c & (1 << j)) c_id.push_back(j);
            if(c_id.size() != w2) continue;

            vector<vector<int>> res;
            for(auto x : r_id){
                vector<int> tmp;
                for(auto y : c_id){
                    tmp.push_back(a[x][y]);
                }
                res.push_back(tmp);
            }
            
            bool ok = true;
            rep(ii,h2){
                rep(jj,w2){
                    if(res[ii][jj] != b[ii][jj]) ok = false;
                }
            }
            if(ok){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    
    return 0;
}