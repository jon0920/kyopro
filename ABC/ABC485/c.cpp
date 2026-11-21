#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> c(n);
    rep(i,n) cin >> c[i];

    const int INF = 1e9;
    vector<int> l(n), r(n);
    l[0] = INF, r[n - 1] = INF;
    for(int i = 1; i < n; i++){
        if(c[i - 1] == c[i]){
            l[i] = l[i - 1] + 1;
        } else {
            l[i] = 1;
        }
    }
    for(int i = n - 2; i >= 0; i--){
        if(c[i + 1] == c[i]){
            r[i] = r[i + 1] + 1;
        } else {
            r[i] = 1;
        }
    }

    rep(i,n){
        cout << min(l[i], r[i]) << " ";
    }
    cout << endl;
    
    return 0;
}