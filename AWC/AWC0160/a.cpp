#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> s(n, vector<int>(m));
    rep(i,n){
        rep(j,m) cin >> s[i][j];
        sort(s[i].begin(), s[i].end());
    } 

    vector<int> score(n);
    rep(i,n){
        for(int j = 1; j < m - 1; j++){
            score[i] += s[i][j];
        }
    }
    
    int ans = -1;
    int mx = 0;
    rep(i,n){
        if(mx < score[i]){
            ans = i + 1;
            mx = score[i];
        }
    }

    cout << ans << endl;
    
    return 0;
}