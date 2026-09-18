#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    rep(i,n) cin >> a[i];
    rep(i,n-1) cin >> b[i];

    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());

    int ans;
    int j = 0;
    bool ngflag = true;
    rep(i,n){
        if(a[i] <= b[j]){
            j++;
            continue;
        }
        else if(ngflag){
            ans = a[i];
            ngflag = false;
        }
        else ans = -1;
    }
    cout << ans << endl;
    
    return 0;
}