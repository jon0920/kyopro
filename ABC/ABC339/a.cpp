#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    string t = "";
    for(auto c : s){
        if(c != '.') t += c;
        else break;
    }
    reverse(t.begin(), t.end());
    cout << t << endl;
    
    return 0;
}