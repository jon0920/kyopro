#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;

    ll t = 0;
    int c;
    rep(i,n){
        int h;
        cin >> h;
        c = h / 5;
        t += c * 3;
        h -= c * 5;
        while(h > 0){
            t++;
            if(t % 3 == 0) h -= 3;
            else h--;
        }
    }

    cout << t << endl;
    
    return 0;
}