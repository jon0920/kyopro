#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m;
    cin >> n >> m;
    map<int,vector<double>> mp;
    rep(i,n){
        int a;
        double b;
        cin >> a >> b;
        mp[a].push_back(b);
    }
    for(auto [k,v] : mp){
        double sum = 0;
        for(auto x : v){
            sum += x;
        }
        double p = v.size();
        double ans = sum / p;
        cout << fixed << setprecision(10) << ans << endl;
    }
    
    
    return 0;
}