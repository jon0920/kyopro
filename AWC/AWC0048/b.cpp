#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int INF = 1e9;

int main(){

    int n;
    cin >> n;
    vector<int> h(n), d(n);
    rep(i,n) cin >> h[i];
    rep(i,n) cin >> d[i];

    vector<int> res(n, INF);
    if(h[0] > 0 && d[0] > 0) res[0] = 1;
    else res[0] = 0;

    for(int i = 0; i < n; i++){
        for(int j = 1; j <= 2; j++){
            if(i + j < n){
                if(h[i + j] > 0 && d[i + j] > 0) res[i + j] = min(res[i + j], res[i] + 1);
                else res[i + j] = min(res[i + j], res[i]);
            }
        }
    }

    cout << res[n - 1] << endl;

    return 0;
}