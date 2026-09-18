#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s;
    cin >> s;
    string t = "";
    for(auto &c : s){
        t += c;
        if(t.size() >= 3){
            if(t.substr(t.size() - 3) == "ABC") t.erase(t.size() - 3);
        }
    }
    cout << t << endl;
    
    return 0;
}