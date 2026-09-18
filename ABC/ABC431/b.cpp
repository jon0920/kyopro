#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int x, n;
    cin >> x >> n;
    vector<pair<int,bool>> w(n,{0,false});
    rep(i,n) cin >> w[i].first;

    int ans = x;
    int q;
    cin >> q;
    rep(i,q){
        int p;
        cin >> p;
        p--;
        if(!w[p].second){
            ans += w[p].first;
            w[p].second = true;
            cout << ans << endl;
        }
        else{
            ans -= w[p].first;
            w[p].second = false;
            cout << ans << endl;
        }
    }

    
    return 0;
}