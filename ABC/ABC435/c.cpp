#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    int r = a[1];
    int ans = 1;
    for(int i = 2; i <= n; i++){
        if(r < i) break;
        r = max(r, i + a[i] - 1);
        ans++;
    }
    cout << ans << endl;

    return 0;
}