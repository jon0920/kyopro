#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    vector<pair<int,int>> ans;
    rep(i,h) rep(j,w){
        if(s[i][j] == 'T') ans.push_back({i + 1, j + 1});
    }

    cout << ans.size() << endl;
    for(auto [x, y] : ans) cout << x << " " << y << endl;

    return 0;
}