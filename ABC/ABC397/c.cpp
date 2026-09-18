#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
        a[i]--;
    }

    vector<int> l(n - 1, 1), r(n - 1, 1);
    vector<bool> usedl(n, false), usedr(n, false);

    usedl[a[0]] = true;
    for(int i = 1; i < n; i++){
        if(!usedl[a[i]]) l[i] = l[i - 1] + 1;
        else l[i] = l[i - 1];
        usedl[a[i]] = true;
    }

    reverse(a.begin(), a.end());
    usedr[a[0]] = true;
    for(int i = 1; i < n; i++){
        if(!usedr[a[i]]) r[i] = r[i - 1] + 1;
        else r[i] = r[i - 1];
        usedr[a[i]] = true;
    }

    int ans = 0;
    rep(i,n - 1){
        int sum = l[i] + r[n - 2 - i];
        ans = max(ans, sum);
    }
    cout << ans << endl;
    
    return 0;
}