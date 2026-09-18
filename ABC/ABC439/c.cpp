#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    map<int,int> mp;
    for(int y = 1; y * y <= n; y++){
        for(int x = 1; x < y; x++){
            if(x * x + y * y > n) break;
            mp[x * x + y * y]++;
        }
    }

    vector<int> res;
    for(auto [k, v] : mp){
        if(v == 1) res.push_back(k);
    }

    cout << res.size() << endl;
    for(auto x : res) cout << x << " ";
    cout << endl;

    return 0;
}