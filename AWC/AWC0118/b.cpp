#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());

    int i = 0;
    int ans = 0;
    while(i + 1 < n){
        if(a[i + 1] - a[i] <= k){
            ans++; i += 2;
        } else i++;
    }
    cout << ans << endl;
    
    return 0;
}