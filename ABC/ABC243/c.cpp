#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

bool check(vector<ll> R, vector<ll> L){
    sort(R.begin(), R.end());
    sort(L.begin(), L.end());
    for(auto p : R){
        auto it = lower_bound(L.begin(), L.end(), p);
        if(it != L.end()) return true;
    }
    return false;
}

int main() {
    
    int n;
    cin >> n;
    map<ll,vector<pair<ll,char>>> mp;
    vector<ll> x(n), y(n);
    rep(i,n){
        cin >> x[i] >> y[i];
    }
    string s;
    cin >> s;
    rep(i,n){
        mp[y[i]].push_back({x[i], s[i]});
    }

    for(auto [k, v] : mp){
        if(v.size() >= 2){
            vector<ll> right, left;
            for(auto [a, d] : v){
                if(d == 'R') right.push_back(a);
                else left.push_back(a);
            }
            if(check(right, left)){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    
    return 0;
}