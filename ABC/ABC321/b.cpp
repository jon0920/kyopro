#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, x;
    cin >> n >> x;
    vector<int> a(n - 1);
    rep(i,n - 1) cin >> a[i];

    sort(a.begin(), a.end());
    /*if(n == 3){
        if(a.back() <= x) cout << 0 << endl;
        else if(a.front() < x && a.back() > x) cout << x << endl;
        else cout << -1 << endl;
        return 0;
    }*/

    int sum = 0;
    for(int i = 1; i < n - 2; i++) sum += a[i];
    if(x - sum <= a.front()) cout << 0 << endl;
    else if(x - sum <= a.back()) cout << x - sum << endl;
    else cout << -1 << endl;

    
    return 0;
}