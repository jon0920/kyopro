#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, q;
    string s;
    cin >> n >> q >> s;
    int offset = 0;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int x;
            cin >> x;
            offset += x;
            offset %= n;
        }
        else{
            int x;
            cin >> x;
            x--;
            int pos = (x - offset + n) % n;
            cout << s[pos] << endl;
        }
    }
    
    return 0;
}