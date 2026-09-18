#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int k, g, m;
    cin >> k >> g >> m;

    int glass = 0, mug = 0, diff = 0;
    rep(i,k){
        if(glass == g) glass = 0;
        else if(mug == 0) mug = m;
        else{
            diff = min(g - glass, mug);
            glass += diff, mug -= diff;
        }
    }
    cout << glass << " " << mug << endl;
    
    return 0;
}