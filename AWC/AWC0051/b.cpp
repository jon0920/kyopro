#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    string s;
    cin >> s;
    int n = s.size();
    s += '!';
    char c = s[0];
    int cnt = 1;
    string res = "";
    for(int i = 1; i <= n; i++){
        if(s[i] == c) cnt++;
        else {
            if(cnt == 1) res += c;
            else {
                res += c;
                res += to_string(cnt);
            }
            cnt = 1;
            c = s[i];
        }
    }

    cout << res << endl;

    return 0;
}