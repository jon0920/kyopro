#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    string t = "sayounara";
    int m = t.size();

    rep(i,n){
        string s;
        cin >> s;
        int sz = s.size();
        int id = 0;
        rep(j,sz){
            if(t[id] == s[j]){
                id++;
                if(id == m) break;
            }
        }
        if(id == m) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}