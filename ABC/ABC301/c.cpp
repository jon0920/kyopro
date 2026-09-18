#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;


int main() {
    
    string s, t;
    cin >> s >> t;
    vector<int> cnts(26), cntt(26);
    int ats = 0, att = 0;
    for(auto c : s){
        if(c != '@') cnts[c - 'a']++;
        else ats++;
    }
    for(auto c : t){
        if(c != '@') cntt[c - 'a']++;
        else att++;
    }
    
    auto wild = [](int x){
        char c = x + 'a';
        string ref = "atcoder";
        if(find(ref.begin(), ref.end(), c) == ref.end()) return false;
        return true;
    };

    rep(i,26){
        if(cnts[i] != cntt[i]){
            if(!wild(i)){
                cout << "No" << endl;
                return 0;
            }
            if(cnts[i] > cntt[i]) att -= (cnts[i] - cntt[i]);
            else ats -= cntt[i] - cnts[i];

            if(ats < 0 || att < 0){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    
    return 0;
}