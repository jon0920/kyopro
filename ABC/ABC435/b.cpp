#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    int ans = 0;
    rep(i,n){
        for(int j = i + 1; j < n; j++){
            int sum = 0;
            bool flag = true;
            for(int k = i; k <= j; k++){
                sum += a[k];
            }
            for(int k = i; k <= j; k++){
                if(sum % a[k] == 0) flag = false;
            }
            if(flag) ans++;
        }
    }
    cout << ans << endl;
    
    return 0;
}