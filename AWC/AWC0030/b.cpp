#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

int main(){

    int n, m;
    cin >> n >> m;
    vector<pair<ll,int>> foods(n);
    rep(i,n){
        cin >> foods[i].first >> foods[i].second;
    }

    rep(i,m){
        ll ves = INF, meat = INF;
        int k;
        cin >> k;
        rep(j,k){
            int s;
            cin >> s;
            s--;
            if(foods[s].second == 0) ves = min(ves, foods[s].first);
            else meat = min(meat, foods[s].first);
        }
        if(ves + meat >= INF) cout << -1 << endl;
        else cout << ves + meat << endl;
    }


    return 0;
}