#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s;
    cin >> s;

    bool check = true;
    rep(i,16){
        if(i % 2 == 1 && s[i] != '0') check = false;
    }
    cout << (check ? "Yes" : "No") << endl;
    return 0;
}