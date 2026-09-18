#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, k, m;
    cin >> n >> k >> m;
    vector<int> s(n);
    rep(i,n) cin >> s[i];
    vector<pair<int,int>> lr(m);
    vector<int> p(m);
    rep(i,m){
        cin >> lr[i].first >> lr[i].second >> p[i];
        lr[i].first--;
        lr[i].second--;
    }

    int ans = -1e9;
    for(int bit = 0; bit < (1 << n); bit++){
        vector<int> flowers;
        int sum = 0;
        rep(i,n){
            if(bit & (1 << i)){
                flowers.push_back(i);
                sum += s[i];
            }
        }

        rep(i,m){
            bool use = false;
            for(auto x : flowers){
                if(lr[i].first <= x && lr[i].second >= x) use = true;
            }
            if(use) sum += p[i];
        }
        ans = max(ans, sum);
    }

    cout << ans << endl;

    return 0;
}