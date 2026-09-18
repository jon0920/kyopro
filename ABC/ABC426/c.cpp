#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n, 1);
    int oldest = 0;
    while(q--){
        int x, y;
        int cnt = 0;
        cin >> x >> y; x--, y--;
        if(oldest > x){
            cout << cnt << endl;
            continue;
        }
        while(oldest <= x){
            cnt += a[oldest];
            a[y] += a[oldest];
            oldest++;
        }
        cout << cnt << endl;
    }
    
    return 0;
}