#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> cnt(n + 1);
    rep(i,n){
        int c;
        cin >> c;
        cnt[c]++;
    }

    int mx = 0;
    for(int i = 1; i <= n; i++) mx = max(mx, cnt[i]);

    cout << n - mx << endl;
    
    return 0;
}