#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];

    rep(i,n){
        double mx = 0;
        int ans;
        for(int j = n - 1; j >= 0; j--){
            double dist = sqrt(pow((x[i] - x[j]), 2) + pow((y[i] - y[j]), 2));
            if(mx <= dist){
                mx = dist;
                ans = j + 1;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}