#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n);
    vector<int> med(n);
    rep(i,n){
        int c;
        cin >> c;
        v[i].resize(c);
        rep(j,c){
            cin >> v[i][j];
        }
        sort(v[i].begin(), v[i].end());
        med[i] = v[i][(c - 1) / 2];
    }
    sort(med.rbegin(), med.rend());
    
    int ans = 0;
    rep(i,k){
        if(med[i] > 0) ans += med[i];
    }
    cout << ans << endl;
    
    return 0;
}