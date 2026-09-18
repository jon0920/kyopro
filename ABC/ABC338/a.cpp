#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s;
    cin >> s;
    bool check = true;
    rep(i,s.size()){
        if(i == 0 && islower(s[i])) check = false;
        else if(i != 0 && isupper(s[i])) check = false; 
    }
    cout << (check ? "Yes" : "No") << endl;
    return 0;
}