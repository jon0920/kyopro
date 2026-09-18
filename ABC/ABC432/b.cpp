#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s;
    cin >> s;

    sort(s.begin(), s.end());
    char first = 0;
    for(char c : s){
        if(c != '0'){
            first = c;
            break;
        }
    }
    
    vector<char> ans;
    bool flag = false;
    for(char c : s){
        if(!flag && c == first){
            flag = true;
            continue;
        }
        ans.push_back(c);
    }
    cout << first;
    for(char c : ans) cout << c;
    cout << endl;
    return 0;
}