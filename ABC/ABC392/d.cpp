#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<map<int,double>> mp(n);
    vector<double> k(n);
    rep(i,n){
        cin >> k[i];
        rep(j,k[i]){
            int a;
            cin >> a;
            mp[i][a]++;
        }
    }

    double ans = 0;
    rep(i,n){
        rep(j,n){
            if(i == j) continue;
            double sum = 0;
            for(auto v : mp[i]){
                auto [key, val] = v;
                if(!mp[j].count(key)) continue;
                double A = val / k[i];
                double B = mp[j][key] / k[j];
                sum += A * B;
            }
            ans = max(ans, sum);
        }
    }
    cout << fixed << setprecision(17);
    cout << ans << endl;
    
    return 0;
}