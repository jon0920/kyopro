#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    string s;
    cin >> n >> s;

    string ans = "";
    vector<int> pos;
    rep(i,n){
        if(s[i] != '(' && s[i] != ')') ans += s[i];
        else if(s[i] == '('){
            pos.push_back(ans.size());
            ans += s[i];
        }
        else{
            if(pos.empty()){
                ans += s[i];
            }
            else{
                int x = pos.back();
                ans.erase(x);
                pos.pop_back();
            }
        }
    }
    cout << ans << endl;

    return 0;
}