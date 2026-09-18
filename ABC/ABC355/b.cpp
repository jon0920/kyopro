#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m), c(n + m);
    rep(i,n){
        cin >> a[i];
        c[i] = a[i];
    }
    rep(i,m){
        cin >> b[i];
        c[i + n] = b[i];
    }
    sort(c.begin(), c.end());
    rep(i,n + m - 1){
        if(find(a.begin(), a.end(), c[i]) != a.end() && find(a.begin(), a.end(),c[i + 1]) != a.end()){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}