#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    string s;
    int k;
    cin >> s >> k;
    s += "!";
    char last = s[0];
    int cnt = 0;
    vector<pair<char,int>> rle;
    for(char c : s){
        if(c == last) cnt++;
        else {
            rle.push_back({last, cnt});
            last = c;
            cnt = 1;
        }
    }

    string res;
    for(auto [c, len] : rle){
        if(len >= k){
            res += c;
            res += to_string(len);
        } else {
            res += string(len, c);
        }
    }

    cout << res << endl;
    
    return 0;
}