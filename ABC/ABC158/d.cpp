#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    string s;
    int q;
    cin >> s >> q;
    int rev = 0;
    string l, r;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            rev ^= 1;
        } else {
            int f; char c;
            cin >> f >> c;
            f--;
            if(rev == f){
                l += c;
            } else {
                r += c;
            }
        }
    }
    if(rev){
        reverse(r.begin(), r.end());
        reverse(s.begin(), s.end());
        cout << r + s + l << endl;
    } else {
        reverse(l.begin(), l.end());
        cout << l + s + r << endl;
    }
    
    return 0;
}