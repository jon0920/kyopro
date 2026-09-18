#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

map<pair<int,int>, int> solve(int m, vector<int> &V){
    int n = V.size();
    map<pair<int,int>, int> res;
    for(int bit = 0; bit < (1 << n); bit++){
        pair<int,int> p = {0, 0};
        rep(i,n){
            if(bit & (1 << i)){
                p.first++;
                p.second += V[i];
                p.second %= m;
            }
        }
        res[p]++;
    }
    return res;
}

int main(){

    int n, k, m;
    cin >> n >> k >> m;
    vector<int> A, B;
    rep(i,n){
        int a;
        cin >> a;
        if(i < n / 2) A.push_back(a);
        else B.push_back(a);
    }

    auto L = solve(m, A);
    auto R = solve(m, B);

    int ans = 0;
    for(auto &[p, v] : L){
        pair<int,int> r = {k - p.first, (m - p.second) % m};
        auto it = R.find(r);
        if(it != R.end()){
            ans += v * (*it).second;
        }
    }
    cout << ans << endl;

    return 0;
}