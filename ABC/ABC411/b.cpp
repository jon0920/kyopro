#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<int> d(n - 1);
    for(int i = 0; i < n - 1; i++) cin >> d[i];
    for(int i = 0; i < n - 1; i++){
        int ans = 0;
        for(int j = 0; j < n - 1; j++){
            ans += d[j];
            if(ans != 0) cout << ans << " ";
        }
        d[i] = 0;
        cout << endl;
    }
    return 0;
}