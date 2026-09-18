#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, q;
    cin >> n >> q;
    map<int,int> mp;
    rep(i,n){
        int x;
        cin >> x;
        mp[x] = i;
    }

    int num = n;
    while(q--){
        int a;
        cin >> a;
        mp[a] = num;
        num++;
    }

    vector<pair<int,int>> p;
    for(auto [k, v] : mp){
        p.push_back({v, k});
    }
    sort(p.begin(), p.end());

    for(auto [x, y] : p) cout << y << " ";
    cout << endl;
    
    return 0;
}