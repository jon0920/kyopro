#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> ab(m);
    rep(i,n){
        int a, b;
        cin >> a >> b;
        a--, b--;
        ab[a].first++;
        ab[b].second++;
    }

    for(auto [a, b] : ab) cout << b - a << endl;

    return 0;
}