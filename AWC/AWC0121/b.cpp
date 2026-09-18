#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.rbegin(), a.rend());

    int ans = k;
    for(int i = k; i < n; i++){
        if(a[k - 1] == a[i]) ans++;
    }
    cout << ans << endl;
    
    return 0;
}