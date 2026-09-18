#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<pair<int,int>> ab(n);
    rep(i,n) cin >> ab[i].first >> ab[i].second;

    vector<vector<set<char>>> st(11, vector<set<char>>(11));
    int m;
    cin >> m;
    vector<string> s(m);
    rep(i,m){
        cin >> s[i];
        int sz = s[i].size();
        rep(j,sz){
            st[sz][j].insert(s[i][j]);
        }
    }

    for(auto t : s){
        int sz = t.size();
        if(sz != n){
            cout << "No" << endl;
            continue;
        }

        bool ok = true;
        rep(i,n){
            auto [x, y] = ab[i];
            if(!st[x][y - 1].count(t[i])) ok = false;
        }
        if(ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}