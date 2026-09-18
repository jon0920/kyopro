#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, h, w;
    cin >> n >> h >> w;
    vector<pair<int,int>> ab(n);
    rep(i,n) cin >> ab[i].first >> ab[i].second;

    auto solve = [&](vector<pair<int,int>> v){
        
        return true;
    };

    bool ok = false;
    for(int bit = 0; bit < (1 << n); bit++){
        vector<pair<int,int>> tiles;
        rep(i,n){
            if(1 & (bit >> i)) tiles.push_back(ab[i]);
        }
        if(solve(tiles)) ok = true;
    }

    cout << (ok ? "Yes" : "No") << endl;
    
    return 0;
}