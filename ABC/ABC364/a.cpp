#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];

    rep(i,n-1){
        if(s[i] == "sweet" && s[i + 1] == "sweet" && i != n - 2){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    
    return 0;
}