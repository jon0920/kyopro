#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int T;
    cin >> T;
    while(T--){
        string a, b;
        cin >> a >> b;
        int n = a.size(), m = b.size();

        string s, t;
        rep(i,n){
            s += a[i];
            if(s.size() >= 4){
                string ss = s.substr(s.size() - 4);
                if(ss == "(xx)"){
                    s.erase(s.size() - 4);
                    s += "xx";
                }
            }
        }
        rep(i,m){
            t += b[i];
            if(t.size() >= 4){
                string tt = t.substr(t.size() - 4);
                if(tt == "(xx)"){
                    t.erase(t.size() - 4);
                    t += "xx";
                }
            }
        }

        if(s == t) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}