#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    vector<int> sum(n + 1);
    rep(i,n){
        sum[i + 1] = sum[i] + (s[i] == '1');
    }

    int ans = 0;
    rep(i,n - m + 1){
        if(sum[i + m] - sum[i] < k) ans++;
    }
    cout << ans << endl;
    
    return 0;
}