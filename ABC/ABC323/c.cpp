#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    rep(i,m) cin >> a[i];
    vector<string> s(n);
    rep(i,n) cin >> s[i];

    int mx = 0;
    rep(i,n){
        int sum = 0;
        rep(j,m){
            if(s[i][j] == 'o') sum += a[j];
        }
        mx = max(mx, sum);
    }

    
    
    return 0;
}