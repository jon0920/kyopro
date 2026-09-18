#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    vector<int> a(3);
    rep(i,3) cin >> a[i];
    sort(a.begin(), a.end());
    if(a[0] == a[1] && a[1] == a[2]) cout << "Yes" << endl;
    else cout << (a[0] + a[1] == a[2] ? "Yes" : "No")  << endl;
    
    return 0;
}