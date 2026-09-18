#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    vector<vector<int>> vec(3, vector<int>(6));
    rep(i,3){
        rep(j,6) cin >> vec[i][j];
    }

    int cnt = 0;
    rep(i,6){
        rep(j,6){
            rep(k,6){
                set<int> st = {vec[0][i], vec[1][j], vec[2][k]};
                if(st == set<int>{4, 5, 6}) cnt++;
            }
        }
    }

    double ans = (double)cnt / 216;
    cout << fixed << setprecision(17);
    cout << ans << endl;

    return 0;
}