#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> x(n), y(m);
    rep(i,n) cin >> x[i];
    rep(i,m) cin >> y[i];

    vector<int> fx(n * m + 1, -1), fy(n * m + 1, -1);
    rep(i,n){
        if(fx[x[i]] != -1){
            cout << "No" << endl;
            return;
        }
        fx[x[i]] = i;
    }
    rep(j,m){
        if(fy[y[j]] != -1){
            cout << "No" << endl;
            return;
        }
        fy[y[j]] = j;
    }

    vector<vector<pair<int,int>>> mn(n * m + 1);
    rep(i,n){
        rep(j,m){
            mn[min(x[i], y[j])].push_back({i, j});
        }
    }

    vector<vector<int>> res(n, vector<int>(m));
    vector<pair<int,int>> pool;
    for(int z = n * m; z >= 1; z--){
        for(auto cell : mn[z]) pool.push_back(cell);

        int row, col;
        if(fx[z] != -1 && fy[z] != -1){
            row = fx[z];
            col = fy[z];
        } else if(fx[z] != -1 || fy[z] != -1){
            if(mn[z].empty()){
                cout << "No" << endl;
                return;
            }
            row = mn[z].back().first;
            col = mn[z].back().second;
        } else {
            while(!pool.empty()){
                auto [i, j] = pool.back();
                if(res[i][j] == 0) break;
                pool.pop_back();
            }
            if(pool.empty()){
                cout << "No" << endl;
                return;
            }
            row = pool.back().first;
            col = pool.back().second;
            pool.pop_back();
        }

        res[row][col] = z;
    }

    cout << "Yes" << endl;
    rep(i,n){
        rep(j,m){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
};

int main(){
    
    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}