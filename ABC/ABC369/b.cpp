#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    bool il = true, ir = true;

    int ans = 0;
    int l, r;
    rep(i,n){
        int a;
        char s;
        cin >> a >> s;
        if(s == 'L'){
            if(il){
                l = a;
                il = false;
            }
            else{
                ans += abs(l - a);
                l = a;
            }
        }
        if(s == 'R'){
            if(ir){
                r = a;
                ir = false;
            }
            else{
                ans += abs(r - a);
                r = a;
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}