#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    ll n, m;
    cin >> n >> m;
    
    set<pair<int,int>> cantput;
    vector<pair<int,int>> move = {{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}};
    rep(i,m){
        int x, y;
        cin >> x >> y;
        cantput.insert({x,y});
        for(auto [a, b] : move){
            if(x + a >= 1 && x + a <= n && y + b >= 1 && y + b <= n){
                cantput.insert({x + a, y + b});
            }
        }
    }

    ll ans;
    ans = n * n - (ll)cantput.size();
    cout << ans << endl;
    
    return 0;
}