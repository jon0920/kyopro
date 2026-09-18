#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    vector<vector<int>> c(3, vector<int>(3));
    rep(i,3) rep(j,3) cin >> c[i][j];

    vector<int> p(9);
    iota(p.begin(), p.end(), 0);

    int cnt = 0;
    do{
        vector<vector<int>> ord(3, vector<int>(3));
        rep(i,3) rep(j,3) ord[i][j] = p[i * 3 + j];

        bool ok = true;
        rep(i,3){
            vector<pair<int,int>> v(3);
            rep(j,3) v[j] = {ord[i][j], c[i][j]};
            sort(v.begin(), v.end());
            if((v[0].second == v[1].second) && (v[1].second != v[2].second)) ok = false;
        }
        rep(j,3){
            vector<pair<int,int>> v(3);
            rep(i,3) v[i] = {ord[i][j], c[i][j]};
            sort(v.begin(), v.end());
            if((v[0].second == v[1].second) && (v[1].second != v[2].second)) ok = false;
        }

        vector<pair<int,int>> d1(3), d2(3);
        d1[0] = {ord[0][0], c[0][0]}; d1[1] = {ord[1][1], c[1][1]}; d1[2] = {ord[2][2], c[2][2]};
        d2[0] = {ord[0][2], c[0][2]}; d2[1] = {ord[1][1], c[1][1]}; d2[2] = {ord[2][0], c[2][0]};
        sort(d1.begin(), d1.end());
        sort(d2.begin(), d2.end());
        if((d1[0].second == d1[1].second) && (d1[1].second != d1[2].second)) ok = false;
        if((d2[0].second == d2[1].second) && (d2[1].second != d2[2].second)) ok = false;
        
        if(ok) cnt++;

    }while(next_permutation(p.begin(), p.end()));

    int sum = 1;
    for(int i = 1; i <= 9; i++){
        sum *= i;
    }

    double ans = (double)cnt / sum;

    cout << fixed << setprecision(17);
    cout << ans << endl;
    
    return 0;
}