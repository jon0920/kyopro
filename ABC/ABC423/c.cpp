#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, r;
    cin >> n >> r;
    vector<int> l(n);
    rep(i,n) cin >> l[i];

    int left = n, right = 0;
    for(int i = 0; i < n; i++){
        if(l[i] == 0){
            left = i;
            break;
        }
    }
    for(int i = n - 1; i >= 0; i--){
        if(l[i] == 0){
            right = i;
            break;
        }
    }

    int open = count(l.begin(), l.end(), 0);
    int t = 0;
    if(left <= r - 1) for(int i = left + 1; i < r; i++) if(l[i] == 1) t++;
    if(right >= r) for(int i = r; i < right; i++) if(l[i] == 1) t++;
    int ans = t * 2 + open;
    
    cout << ans << endl;
    
    return 0;
}