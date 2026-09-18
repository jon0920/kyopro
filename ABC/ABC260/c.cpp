#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, x, y;
    cin >> n >> x >> y;
    vector<vector<ll>> jewels(n, vector<ll>(2));
    n--;
    jewels[n][0] = 1;
    for(int i = n; i >= 1; i--){
        jewels[i-1][0] += jewels[i][0];
        jewels[i][1] += x * jewels[i][0];
        jewels[i-1][0] += jewels[i][1];
        jewels[i-1][1] += y * jewels[i][1];
    }

    cout << jewels[0][1] << endl;
    
    return 0;
}