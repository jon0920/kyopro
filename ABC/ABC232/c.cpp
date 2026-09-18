#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> T(n, vector<bool>(n));
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--, b--;
        T[a][b] = true;
        T[b][a] = true;
    }

    vector<pair<int,int>> cd(m);
    rep(i,m){
        int c, d;
        cin >> c >> d;
        c--, d--;
        cd[i] = {c, d};
    }

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);

    do{
        vector<vector<bool>> A(n, vector<bool>(n));
        rep(i,m){
            auto [x, y] = cd[i];
            A[p[x]][p[y]] = true;
            A[p[y]][p[x]] = true;
        }
        bool ok = true;
        rep(i,n) rep(j,n){
            if(T[i][j] != A[i][j]) ok = false;
        }
        if(ok){
            cout << "Yes" << endl;
            return 0;
        }
    }while(next_permutation(p.begin(), p.end()));

    cout << "No" << endl;
    
    return 0;
}