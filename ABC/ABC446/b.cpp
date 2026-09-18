#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<vector<int>> x(n);
    rep(i,n){
        int l;
        cin >> l;
        x[i].resize(l);
        rep(j,l){
            cin >> x[i][j]; 
            x[i][j]--;
        }
    }

    vector<bool> used(n);
    rep(i,n){
        int ans = 0;
        for(auto a : x[i]){
            if(!used[a]){
                used[a] = true;
                ans = a + 1;
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}