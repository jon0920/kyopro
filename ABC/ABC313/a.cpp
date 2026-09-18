#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];

    int mx = 0;
    for(int i = 1; i < n; i++) mx = max(mx, p[i]);
    
    if(p[0] > mx) cout << 0 << endl;
    else cout << mx - p[0] + 1 << endl;
    
    return 0;
}