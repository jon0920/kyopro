#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s, t;
    cin >> s >> t;

    for(int w = 1; w < s.size(); w++){
        rep(c,w){
            string res = "";
            for(int i = c; i < s.size(); i += w){
                res += s[i];
            }
            if(res == t){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    
    return 0;
}