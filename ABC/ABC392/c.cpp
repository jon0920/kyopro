#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    rep(i,n) cin >> p[i];
    rep(i,n) cin >> q[i];
    vector<int> s(n);
    for(int i = 0; i < n; i++){
        s[q[i] - 1] = q[p[i] - 1]; 
    }

    rep(i,n){
        cout << s[i] << " ";
    }

    cout << endl;

    return 0;
}