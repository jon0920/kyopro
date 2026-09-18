#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, q;
    cin >> n >> q;
    
    int l = 1, r = 2;
    int cnt = 0;
    rep(i,q){
        char h;
        int t;
        cin >> h >> t;
        if(h == 'L'){
            int to = (t - l + n) % n;
            int ng = (r - l + n) % n;
            if(to < ng) cnt += to;
            else cnt += n - to;
            l = t;
        }
        if(h == 'R'){
            int to = (t - r + n) % n;
            int ng = (l - r + n) % n;
            if(to < ng) cnt += to;
            else cnt += n - to;
            r = t;
        }
    }
    
    cout << cnt << endl;
    
    return 0;
}