#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    string s;
    cin >> n >> s;
    string t = s;
    reverse(t.begin(), t.end());

    rep(i,n){
        if(s[i] != t[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    
    return 0;
}