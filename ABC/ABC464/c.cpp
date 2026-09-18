#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> vec(m);
    rep(i,n){
        int a, d, b;
        cin >> a >> d >> b;
        d--;
        if(d == 0){
            vec[d].push_back({b, 1});
            continue;
        }
        vec[0].push_back({a, 1});
        if(a != b){
            vec[d].push_back({b, 1});
            vec[d].push_back({a, -1});
        }
    }

    rep(i,m) sort(vec[i].rbegin(), vec[i].rend());

    map<int,int> mp;
    rep(i,m){
        for(auto [x, y] : vec[i]){
            if(y == 1) mp[x]++;
            else{
                mp[x]--;
                if(mp[x] == 0) mp.erase(x);
            }
        }
        cout << mp.size() << endl;
    }
    
    return 0;
}