#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.rbegin(), a.rend());
    if(n == 1) cout << a[0] << endl;
    else if(a[0] != a[1]) cout << a[0] << endl;
    else cout << 0 << endl;

    return 0;
}