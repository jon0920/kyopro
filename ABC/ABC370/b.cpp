#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    rep(i,n){
        for(int j = 0; j <= i; j++){
            int A;
            cin >> A;
            a[i].push_back(A);
        }
    }

    int res = 1;
    for(int i = 1; i <= n; i++){
        if(res >= i){
            res = a[res - 1][i - 1];
        }
        else res = a[i - 1][res - 1];
    }

    cout << res << endl;
    
    return 0;
}