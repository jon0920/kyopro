#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    vector<int> a(3);
    rep(i,3) cin >> a[i];
    sort(a.rbegin(), a.rend());
    rep(i,3) cout << a[i];
    cout << endl;

    return 0;
}