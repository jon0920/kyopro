#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<tuple<int,int,char>> vec(m);
    rep(i,m){
        int x, y;
        char c;
        cin >> x >> y >> c;
        vec[i] = {x, y, c};
    }
    sort(vec.begin(), vec.end());

    int mn = 1e9;
    bool ok = true;
    for(auto [x, y, c] : vec){
        if(c == 'W'){
            mn = min(mn, y);
        } else {
            if(y >= mn) ok = false;
        }
    }

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}