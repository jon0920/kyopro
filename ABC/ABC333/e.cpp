#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> t(n), x(n);
    rep(i,n){
        cin >> t[i] >> x[i];
        x[i]--;
    }

    vector<int> ans(n);
    vector<int> rem(n);
    for(int i = n - 1; i >= 0; i--){
        if(t[i] == 1){
            if(rem[x[i]] > 0){
                rem[x[i]]--;
                ans[i] = 1;
            }
        } else {
            rem[x[i]]++;
            ans[i] = -1;
        }
    }

    rep(i,n) if(rem[i] > 0){
        cout << -1 << endl;
        return 0;
    }
    
    int mx = 0;
    int sum = 0;
    rep(i,n){
        sum += ans[i];
        mx = max(mx, sum);
    }

    cout << mx << endl;
    rep(i,n){
        if(ans[i] != -1) cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}