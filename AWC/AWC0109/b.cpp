#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    string s;
    cin >> s;
    int n = s.size();
    vector<char> v;
    rep(i,n){
        if(v.empty() || v.back() != s[i]) v.push_back(s[i]);
        else v.pop_back();
    }

    cout << v.size() << endl;
    
    return 0;
}