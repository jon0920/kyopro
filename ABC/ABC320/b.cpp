#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

bool is_palindrome(string T, string U){
    for(int i = 0; i < T.size(); i++){
        if(T[i] != U[i]) return false;
    }
    return true;
}


int main() {
    
    string s;
    cin >> s;

    int ans;
    for(int i = 1; i <= s.size(); i++){
        for(int j = 0; j + i <= s.size(); j++){
            string t = s.substr(j, i), u = s.substr(j, i);
            reverse(t.begin(), t.end());
            if(is_palindrome(t, u)) ans = i;
        }
    }
    cout << ans << endl;
    
    return 0;
}