#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s;
    cin >> s;
    int n = s.size();
    if(s[0] != '<' || s[n - 1] != '>'){
        cout << "No" << endl;
        return 0;
    }
    for(int i = 1; i <= n - 2; i++){
        if(s[i] != '='){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    
    return 0;
}