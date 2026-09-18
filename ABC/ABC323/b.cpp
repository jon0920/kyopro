#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];

    vector<pair<int,int>> p(n);
    rep(i,n) rep(j,n){
        p[i].second = i + 1;
        if(s[i][j] == 'o') p[i].first++;
    }
    sort(p.begin(), p.end(), [](pair<int,int> x, pair<int,int> y){
        if(x.first != y.first) return x.first > y.first;
        return x.second < y.second;
    });
    rep(i,n) cout << p[i].second << " ";
    cout << endl;
    
    return 0;
}