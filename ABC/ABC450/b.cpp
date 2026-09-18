#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<vector<ll>> c(n, vector<ll>(n + 1));
    for(int i = 1; i < n; i++){
        for(int j = i + 1; j <= n; j++){
            cin >> c[i][j];
        }
    }

    bool ans = false;
    for(int i = 1; i <= n - 2; i++){
        for(int j = i + 1; j <= n - 1; j++){
            for(int k = j + 1; k <= n; k++){
                if(c[i][j] + c[j][k] < c[i][k]) ans = true;
            }
        }
    }

    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}